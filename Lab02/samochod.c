

#include "samochod.h"


Samochod* stworzSamochod(char *marka, char *model, int rok_produkcji, double przebig) {
	Samochod *samochod = (Samochod *)malloc(sizeof(Samochod));
	assert(samochod != NULL);

	strcpy(samochod->marka, marka);
	strcpy(samochod->model, model);
	samochod->rok_produkcji = rok_produkcji;
	assert(przebig >= 0);
	samochod->przebieg = przebig;
	id_licznik_samochodow++;
	samochod->id = id_licznik_samochodow;
	samochod->naprawy = malloc(sizeof(struct LinkedList));

	assert(samochod->naprawy != NULL);
	Initialize(samochod->naprawy);

	return samochod;
}

Samochod* stworzSamochodzOdUzytkownika() {
	Samochod* samochod = stworzSamochod("a","a",1,1.0);
	printf("Podaj parametry samochodu\n");
	printf("Podaj marke\n");
	scanf("%s", samochod->marka);
	printf("Podaj model\n");
	scanf("%s", samochod->model);
	printf("Podaj rocznik\n");
	scanf("%d", &samochod->rok_produkcji);
	while (1)
	{
		printf("Podaj przebieg\n");
		scanf("%lf", &samochod->przebieg);
		if (samochod->przebieg >= 0) {
			break;
		}
		printf("Zly zakres przebiegu.\n");
	}
	return samochod;
}

void zniszczSamochod(Samochod *samochod) {
	assert(samochod != NULL);
	FreeList(samochod->naprawy);
	free(samochod);
	samochod = NULL;
}

void wypiszSamochod(Samochod *samochod) {
	int i;
	printf("ID: %d, MARKA: %s, MODEL: %s, \n\tROCZNIK: %d, PRZBIEG: %.1lf, LICZBA NAPRAW: %d\n", samochod->id, samochod->marka, samochod->model, samochod->rok_produkcji, samochod->przebieg, GetLenght(samochod->naprawy));
	for ( i = 0; i < GetLenght(samochod->naprawy); i++)
	{
		printf("\t");
		wypiszNaprawe((Naprawa*)GetElement(samochod->naprawy,i)->data);
	}
}

int dodajNapraweDoSamochodu(Samochod *samochod, Naprawa *naprawa) {
	/*if (samochod->liczbaNapraw == samochod->max_liczba_napraw) {
		samochod->max_liczba_napraw *= 2;
		samochod->tablica_napraw = (Naprawa **)realloc(samochod->tablica_napraw, samochod->max_liczba_napraw*sizeof(Naprawa *));
		samochod->tablica_napraw[samochod->liczbaNapraw] = naprawa;
		samochod->liczbaNapraw++;
	}
	else
	{
		samochod->tablica_napraw[samochod->liczbaNapraw] = naprawa;
		samochod->liczbaNapraw++;
	}*/
		AddElement(samochod->naprawy,(void*)naprawa);
	return 1;
}

int usunNapraweZSamochodu(Samochod *samochod, int id) {
	int i,j;
	for (i = 0; i < GetLenght(samochod->naprawy); i++)
	{
		if (((Naprawa*)GetElement(samochod->naprawy,i)->data)->id == id)
		{
			RemoveElement(samochod->naprawy,i);
			/*for (j = i+1; j <samochod->liczbaNapraw ; j++)
			{
				samochod->tablica_napraw[j - 1] = samochod->tablica_napraw[j];
			}
			samochod->liczbaNapraw--;*/
			return 1;
		}
	}
	return 0;
}

void zapiszSamochod(Samochod* samochod,FILE* plik){
		fprintf(plik,"%d\n%s\n%s\n%d\n%lf\n",samochod->id,samochod->marka,samochod->model,samochod->rok_produkcji,samochod->przebieg);
		fprintf(plik,"Liczba napraw:\n");
		fprintf(plik,"%d\n",GetLenght(samochod->naprawy));
		fprintf(plik, "Id napraw:\n");
		int i;
		for(i = 0 ; i < GetLenght(samochod->naprawy);i++){
			fprintf(plik,"%d\n",((Naprawa*)GetElement(samochod->naprawy,i)->data)->id);
		}
}

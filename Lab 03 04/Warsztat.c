
#include"Warsztat.h"

void zapiszDoPlikuTekstowego(Warsztat* warsztat,char* nazwaPliku){
	FILE* plik;
	plik = fopen(nazwaPliku,"w");
	if(plik == NULL){
		printf("Blad otwarcia pliku: %s",nazwaPliku);
		return ;
	}

	fprintf(plik,"Liczba napraw:\n");
	fprintf(plik,"%d\n",GetLenght(warsztat->naprawy));
		fprintf(plik,"Naprawy:\n");
	int i;
	for(i = 0 ; i < GetLenght(warsztat->naprawy);i++){

			zapiszNaprawa((Naprawa*)GetElement(warsztat->naprawy,i)->data,plik);
	}
	fprintf(plik,"Liczba samochodow:\n");
	fprintf(plik,"%d\n",GetLenght(warsztat->samochody));
	for(i = 0 ; i < GetLenght(warsztat->samochody);i++){
		zapiszSamochod((Samochod*)GetElement(warsztat->samochody,i)->data,plik);
	}

	fclose(plik);
}

void wczytajZPlikuTekstowego(Warsztat* warsztat,char* nazwaPliku){
	FILE* plik;
	plik = fopen(nazwaPliku,"r");
	if(plik == NULL){
		printf("Blad otwarcia pliku: %s",nazwaPliku);
		return ;
	}
	char* buffor = malloc(sizeof(char)*512);
	int buffSize = 512;

	free(buffor);
	fclose(plik);
}

Warsztat* inicjalizujWarsztat() {
	Warsztat *warsztat = malloc(sizeof(Warsztat));

	warsztat->samochody = malloc(sizeof(struct LinkedList));
	Initialize(warsztat->samochody);
	assert(warsztat->samochody != NULL);

	warsztat->naprawy = malloc(sizeof(struct LinkedList));
	Initialize(warsztat->naprawy);
	assert(warsztat->naprawy != NULL);

	return warsztat;
}

void zniszczWarsztat(Warsztat *warsztat){
	int i;
	assert(warsztat != NULL);
	FreeList(warsztat->samochody);
	FreeList(warsztat->naprawy);
	/*for ( i = 0; i < warsztat->liczbaSamochodow; i++)
	{
		zniszczSamochod(warsztat->samochody[i]);
	}*/
	/*free(warsztat->samochody);
	for ( i = 0; i < warsztat->liczbaNapraw; i++)
	{
		zniszczNaprawe(warsztat->naprawy[i]);
	}
	free(warsztat->naprawy);*/
	free(warsztat);
	warsztat = NULL;
}


void dodajSamochod(Warsztat *warsztat,Samochod *samochod) {
	int i;
	for ( i = 0; i < GetLenght(warsztat->samochody); i++)
	{
		if(((Samochod*)GetElement(warsztat->samochody,i)->data)->id == samochod->id) {
			return;
		}
	}

	AddElement(warsztat->samochody,(void*)samochod);

	/*if (warsztat->liczbaSamochodow == warsztat->max_liczba_samochodow) {
		warsztat->max_liczba_samochodow *= 2;
		warsztat->samochody = (Samochod**)realloc(warsztat->samochody,warsztat->max_liczba_samochodow*sizeof(Samochod*));
		warsztat->samochody[warsztat->liczbaSamochodow] = samochod;
		warsztat->liczbaSamochodow++;
	}
	else
	{
		warsztat->samochody[warsztat->liczbaSamochodow] = samochod;
		warsztat->liczbaSamochodow++;
	}*/
}
void dodajNaprawe(Warsztat *warsztat, Naprawa *naprawa) {
	int i;
	for (i = 0; i < GetLenght(warsztat->naprawy); i++)
	{
		if (((Naprawa*)GetElement(warsztat->naprawy,i)->data)->id == naprawa->id){
			return;
		}
	}
	AddElement(warsztat->naprawy,(void*)naprawa);
	/*if (warsztat->liczbaNapraw == warsztat->max_liczba_napraw) {
		warsztat->max_liczba_napraw *= 2;
		warsztat->naprawy = (Naprawa**)realloc(warsztat->naprawy, warsztat->max_liczba_napraw * sizeof(Naprawa*));
		warsztat->naprawy[warsztat->liczbaNapraw] = naprawa;
		warsztat->liczbaNapraw++;
	}
	else
	{
		warsztat->naprawy[warsztat->liczbaNapraw] = naprawa;
		warsztat->liczbaNapraw++;
	}*/
}

void wypiszWarsztat(Warsztat *warsztat) {
	int i;
	printf("#####################################\n");
	printf("###########WARSZTAT##################\n");
	printf("#####################################\n");
	printf("\n\t\tSAMOCHODY\n");
	for ( i = 0; i <GetLenght(warsztat->samochody); i++)
	{
		wypiszSamochod((Samochod*)GetElement(warsztat->samochody,i)->data);
		printf("\n");

	}
	printf("\n\t\tNAPRAWY\n");
	for ( i = 0; i < GetLenght(warsztat->naprawy); i++)
	{
		wypiszNaprawe((Naprawa*)GetElement(warsztat->naprawy,i)->data);
	}
	printf("#####################################\n");
	printf("#####################################\n");
}

int usunSamochod(Warsztat *warsztat, int id) {
	int i,j;
	for (i = 0; i < GetLenght(warsztat->samochody); i++)
	{
		if (((Samochod*)GetElement(warsztat->samochody,i)->data)->id == id)
		{
			Samochod* s = (Samochod*) GetElement(warsztat->samochody,i)->data;
			RemoveElement(warsztat->samochody,i);
			zniszczSamochod(s);
			/*for ( j = i+1; j < warsztat->liczbaSamochodow; j++)
			{

				warsztat->samochody[j - 1] = warsztat->samochody[j];
			}
			warsztat->liczbaSamochodow--;*/
			return 1;
		}
	}
	return 0;
}

int usunNaprawe(Warsztat *warsztat, int id) {
	int i,j;
	for ( i = 0; i < GetLenght(warsztat->naprawy); i++)
	{
		if (((Naprawa*)GetElement(warsztat->naprawy,i)->data)->id == id)
		{
			for (j = 0; j < GetLenght(warsztat->samochody); j++)
			{
				usunNapraweZSamochodu((Samochod*)GetElement(warsztat->samochody,j)->data, id);
			}
			zniszczNaprawe((Naprawa*)GetElement(warsztat->naprawy,i)->data);
			/*for (j = i+1 ; j < warsztat->liczbaNapraw; j++)
			{
				warsztat->naprawy[j - 1] = warsztat->naprawy[j];
			}
			warsztat->liczbaNapraw--;*/
			return 1;
		}

	}
	return 0;
}

int modyfikujSamochod(Warsztat *warsztat, int id) {
	int i;
	for (i = 0; i < GetLenght(warsztat->samochody); i++)
	{
		Samochod* s = (Samochod*)GetElement(warsztat->samochody,i)->data;
		if (s->id == id) {
			printf("Zmiana parametrow samochodu\n");
			printf("Podaj nowa marke\n");
			scanf("%s", s->marka);
			printf("Podaj nowy model\n");
			scanf("%s", s->model);
			printf("Podaj nowy rocznik\n");
			scanf("%d", &s->rok_produkcji);
			while (1)
			{
				printf("Podaj nowy przebieg\n");
				scanf("%lf", &s->przebieg);
				if (s->przebieg >= 0) {
					return 1;
				}
				printf("Zly zakres przebiegu.\n");
			}
		}
	}
	return 0;
}

int modyfikujNaprawe(Warsztat *warsztat, int id) {
	int i;
	for (i = 0; i < GetLenght(warsztat->naprawy); i++)
	{
		Naprawa* n= (Naprawa*) GetElement(warsztat->naprawy,i)->data;
		if (n->id == id) {
			printf("Zmiana parametrow naprawy\n");
			printf("Podaj nowa nazwe\n");
			scanf("%s", n->nazwa);
			while (1)
			{
				printf("Podaj nowa liczbe roboczogodzin\n");
				scanf("%lf", &n->roboczo_godziny);
				if (n->roboczo_godziny > 0) {
					return 1;
				}
				printf("Zly zakres czasu.\n");
			}
		}
	}
	return 0;
}


int porownajNaprawyNazwa(const void *a, const void *b)
{
	Naprawa* __a = (Naprawa*)((struct Element*)a)->data;
	Naprawa* __b = (Naprawa*)((struct Element*)b)->data;

	return strcmp((__a)->nazwa, (__b)->nazwa);
}

void sortujNapraweNazwa(Warsztat *warsztat) {
	Sort(warsztat->naprawy,porownajNaprawyNazwa);
}

int porownajNaprawyGodziny(const void *a, const void *b) {
	Naprawa* __a = (Naprawa*)((struct Element*)a)->data;
	Naprawa* __b = (Naprawa*)((struct Element*)b)->data;
	if ((__a)->roboczo_godziny < (__b)->roboczo_godziny)return -1;
	else if ((__a)->roboczo_godziny == (__b)->roboczo_godziny) return 0;
	else return 1;
}
void sortujNapraweGodziny(Warsztat *warsztat) {
	Sort(warsztat->naprawy,porownajNaprawyGodziny);
}

int porownajSamochodyMarka(const void *a, const void *b) {
	Samochod* __a = (Samochod*)((struct Element*)a)->data;
	Samochod* __b = (Samochod*)((struct Element*)b)->data;
	return strcmp((__a)->marka, (__b)->marka);
}

void sortujSamochodyMarka(Warsztat *warsztat) {
		Sort(warsztat->samochody, porownajSamochodyMarka);
}

int porownajSamochodyModel(const void *a, const void *b) {
	Samochod* __a = (Samochod*)((struct Element*)a)->data;
	Samochod* __b = (Samochod*)((struct Element*)b)->data;
	return strcmp((__a)->model, (__b)->model);
}

void sortujSamochodyModel(Warsztat *warsztat) {
	Sort(warsztat->samochody, porownajSamochodyModel);
}

int porownajSamochodyPrzebieg(const void *a, const void *b) {
	Samochod* __a = (Samochod*)((struct Element*)a)->data;
	Samochod* __b = (Samochod*)((struct Element*)b)->data;
	if ((__a)->przebieg < (__b)->przebieg)return -1;
	else if ((__a)->przebieg == (__b)->przebieg) return 0;
	else return 1;
}
void sortujSamochodyPrzebieg(Warsztat *warsztat) {
	Sort(warsztat->samochody, porownajSamochodyPrzebieg);
}

int porownajSamochodyRocznik(const void *a, const void *b) {
	Samochod* __a = (Samochod*)((struct Element*)a)->data;
	Samochod* __b = (Samochod*)((struct Element*)b)->data;
	if ((__a)->rok_produkcji < (__b)->rok_produkcji)return -1;
	else if ((__a)->rok_produkcji == (__b)->rok_produkcji) return 0;
	else return 1;
}

void sortujSamochodyRocznik(Warsztat *warsztat) {
	Sort(warsztat->samochody, porownajSamochodyRocznik);
}

int porownajSamochodyLiczbaNapraw(const void *a, const void *b) {
	Samochod* __a = (Samochod*)((struct Element*)a)->data;
	Samochod* __b = (Samochod*)((struct Element*)b)->data;
	if (GetLenght(__a->naprawy) < GetLenght(__b->naprawy))return -1;
	else if (GetLenght(__a->naprawy) == GetLenght(__b->naprawy)) return 0;
	else return 1;
}

void sortujSamochodyLiczbaNapraw(Warsztat *warsztat) {
	Sort(warsztat->samochody, porownajSamochodyLiczbaNapraw);
}

void wyswietlSamochody(Warsztat *warsztat) {
	int i;
	printf("#####################################\n");
	printf("\n\t\tSAMOCHODY\n");
	for ( i = 0; i < GetLenght(warsztat->samochody); i++)
	{
		wypiszSamochod((Samochod*)GetElement(warsztat->samochody,i)->data);
		printf("\n");
	}
	printf("#####################################\n");
}

void wyswietlNaprawy(Warsztat *warsztat) {
	int i;
	printf("#####################################\n");
	printf("\n\t\tNAPRAWY\n");
	for (i = 0; i < GetLenght(warsztat->naprawy); i++)
	{
		wypiszNaprawe((Naprawa*)GetElement(warsztat->naprawy,i)->data);

	}
	printf("#####################################\n");
}

int dodajNapraweDoSamochoduWarsztat(Warsztat *warsztat, int idSamochodu, int idNaprawy) {
	int i;
	Samochod* s = NULL;
	Naprawa* n = NULL;
	for (i = 0; i < GetLenght(warsztat->samochody); i++)
	{
		if (((Samochod*)GetElement(warsztat->samochody,i)->data)->id == idSamochodu)
		{
			s = (Samochod*)GetElement(warsztat->samochody,i)->data;
			break;
		}
	}
	if (s == NULL) {
		return 0;
	}
	for ( i = 0; i < GetLenght(warsztat->naprawy); i++)
	{
		if (((Naprawa*)GetElement(warsztat->naprawy,i)->data)->id == idNaprawy)
		{
			n = (Naprawa*)GetElement(warsztat->naprawy,i)->data;
			break;
		}
	}
	if (n == NULL) {
		return 0;
	}

	return dodajNapraweDoSamochodu(s, n);
}

int usunNapraweZSamochoduWarsztat(Warsztat *warsztat, int idSamochodu, int idNaprawy) {
	int i;
	Samochod* s = NULL;
	Naprawa* n = NULL;
	for ( i = 0; i < GetLenght(warsztat->samochody); i++)
	{
		if ((((Samochod*)GetElement(warsztat->samochody,i)->data))->id == idSamochodu)
		{
			s = (Samochod*)GetElement(warsztat->samochody,i)->data;
			break;
		}
	}
	if (s == NULL) {
		return 0;
	}
	return usunNapraweZSamochodu(s,idNaprawy);
}

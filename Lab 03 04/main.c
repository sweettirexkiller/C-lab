

#include "Warsztat.h"
#include<assert.h>
#include <stdio.h>
#include <stdlib.h>



#ifdef __unix__
	#define CLEAR "clear"
#elif defined _WIN32
	#define CLEAR "cls"
#elif defined _WIN64
	#define CLEAR "cls"
#endif


int main()
{
	Warsztat *warsztat = inicjalizujWarsztat();
	assert(warsztat != NULL);

	char komenda[512];
	while (1) {
		printf("#####################\n");
		printf("\tMENU\n");
		printf("#####################\n");
		printf("1 - Dodaj samochod\n");
		printf("2 - Dodaj naprawe\n");
		printf("3 - Skasuj samochod\n");
		printf("4 - Skasuj naprawe\n");
		printf("5 - Wypisz warsztat\n");
		printf("6 - Wypisz samochody\n");
		printf("7 - Wypisz Naprawy\n");
		printf("8 - Modyfikuj samochod\n");
		printf("9 - Modyfikuj naprawe\n");
		printf("10 - Dodaj naprawe do samochodu \n");
		printf("11 - Usun naprawe z samochodu \n");
		printf("12 - Sortuj Naprawy wedlug godziny \n");
		printf("13 - Sortuj Naprawy wedlug nazwy \n");
		printf("14 - Sortuj Samochody wedlug marki\n");
		printf("15 - Sortuj Samochody wedlug modelu\n");
		printf("16 - Sortuj Samochody wedlug przebiegu\n");
		printf("17 - Sortuj Samochody wedlug rocznika \n");
		printf("18 - Sortuj Samochody wedlug liczby napraw\n");
		printf("wczytaj - wczytaj Warsztat z pliku\n");
		printf("zapisz - zapisz Warsztat do pliku\n");
		printf("wyjscie - Wyjscie z programu\n");
		scanf("%s",komenda);

		system(CLEAR);
		if (strcmp(komenda,"wyjscie") == 0) {
			printf("Czy na pewno chcesz wyjsc? Wcisnij y lub n.\n");
			char ostatniakomenda[512];
			scanf("%s", ostatniakomenda);
			if(strcmp(ostatniakomenda, "n") == 0){
				system(CLEAR);
				continue;
			}else if(strcmp(ostatniakomenda, "y") == 0){
				break;
			}
		}else if (strcmp(komenda, "1") == 0) {
			Samochod *s1 = stworzSamochodzOdUzytkownika();
			dodajSamochod(warsztat, s1);
			printf("Dodano nowy samochod\n");
		}else if (strcmp(komenda, "2") == 0) {
			Naprawa *n1 = stworzNapraweOdUzytkownika();
			dodajNaprawe(warsztat, n1);
			printf("Dodano nowa naprawe\n");
		}else if (strcmp(komenda, "3") == 0) {
			int id;
			printf("Podaj id samochodu do usuniecia: \n");
			scanf("%d", &id);
			if (usunSamochod(warsztat, id) == 1) {
				printf("Usunieto samochod\n");
			}
			else
			{
				printf("Nie znalezionio samochodu o id: %d\n", id);
			}
		}else if (strcmp(komenda, "4") == 0) {
			int id;
			printf("Podaj id naprawy do usuniecia: \n");
			scanf("%d", &id);
			if(usunNaprawe(warsztat,id) == 1){
				printf("Usunieto naprawe\n");
			}
			else
			{
				printf("Nie znalezionio naprawy o id: %d\n", id);
			}
		}else if (strcmp(komenda, "5") == 0) {
			wypiszWarsztat(warsztat);
		}
		else if (strcmp(komenda, "6") == 0) {
			wyswietlSamochody(warsztat);
		}
		else if (strcmp(komenda, "7") == 0) {
			wyswietlNaprawy(warsztat);
		}
		else if (strcmp(komenda, "8") == 0) {
			int id;
			printf("Podaj id samochodu do modyfikacji: \n");
			scanf("%d", &id);
			if (modyfikujSamochod(warsztat, id) == 1) {
				printf("Zmodyfikowano Samochod\n");
			}
			else
			{
				printf("Nie znalezionio samochodu o id: %d\n", id);
			}

		}
		else if (strcmp(komenda, "9") == 0) {
			int id;
			printf("Podaj id naprawy do modyfikacji: \n");
			scanf("%d", &id);
			if (modyfikujNaprawe(warsztat, id) == 1) {
				printf("Zmodyfikowano naprawe\n");
			}
			else
			{
				printf("Nie znalezionio naprawy o id: %d\n", id);
			}

		}
		else if (strcmp(komenda, "10") == 0) {
			int idNaprawy;
			printf("Podaj id naprawy do dodania: \n");
			scanf("%d", &idNaprawy);
			int idSamochodu;
			printf("Podaj id samochodu: \n");
			scanf("%d", &idSamochodu);
			if (dodajNapraweDoSamochoduWarsztat(warsztat, idSamochodu, idNaprawy) == 1)
			{
				printf("Dodano naprawe do samochodu\n");
			}
			else
			{
				printf("Nie dodano\n");
			}
		}
		else if (strcmp(komenda, "11") == 0) {
			int idNaprawy;
			printf("Podaj id naprawy do usuniecia: \n");
			scanf("%d", &idNaprawy);
			int idSamochodu;
			printf("Podaj id samochodu: \n");
			scanf("%d", &idSamochodu);
			if (usunNapraweZSamochoduWarsztat(warsztat, idSamochodu, idNaprawy) == 1)
			{
				printf("Usunieto naprawe z samochodu\n");
			}
			else
			{
				printf("Nie usunieto\n");
			}
		}
		else if (strcmp(komenda, "12") == 0) {

			sortujNapraweGodziny(warsztat);
			printf("Naprawy zostaly posortowane.");
		}
		else if (strcmp(komenda, "13") == 0) {
			sortujNapraweNazwa(warsztat);
			printf("Naprawy zostaly posortowane.");
		}
		else if (strcmp(komenda, "14") == 0) {
			sortujSamochodyMarka(warsztat);
			printf("Samochody zostaly posortowane.");
		}
		else if (strcmp(komenda, "15") == 0) {
			sortujSamochodyModel(warsztat);
			printf("Samochody zostaly posortowane.");
		}
		else if (strcmp(komenda, "16") == 0) {
			sortujSamochodyPrzebieg(warsztat);
			printf("Samochody zostaly posortowane.");
		}
		else if (strcmp(komenda, "17") == 0) {
			sortujSamochodyRocznik(warsztat);
			printf("Samochody zostaly posortowane.");

		}
		else if (strcmp(komenda, "18") == 0) {
			sortujSamochodyLiczbaNapraw(warsztat);
			printf("Samochody zostaly posortowane.");
		}
		else if (strcmp(komenda, "wczytaj") == 0 ) {
			wczytajZPlikuTekstowego(warsztat,"pamiec.txt");
		}
		else if (strcmp(komenda, "zapisz") == 0 ) {
			zapiszDoPlikuTekstowego(warsztat,"pamiec.txt");
		}
		else {
			printf("Nie znaleziono komendy.\n");
		}

		printf("\nNacisnij klawisz zeby kontynuowac...\n");
		getchar();
		getchar();
		system(CLEAR);
	}
	zniszczWarsztat(warsztat);
	return 0;
}


#ifndef SAMOCHOD_H
#define SAMOCHOD_H

#include"LinkedList.h"
#include "Naprawa.h"
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

static int id_licznik_samochodow = 0;

typedef struct Samochod {
	char marka[512];
	char model[512];
	int rok_produkcji;
	double przebieg;
	int id;
	struct LinkedList* naprawy;
}Samochod;

Samochod* stworzSamochod(char *marka, char *model, int rok_produkcji, double przebig);

Samochod* stworzSamochodzOdUzytkownika();

void zniszczSamochod(Samochod *samochod);

void wypiszSamochod(Samochod *samochod);

int dodajNapraweDoSamochodu(Samochod *samochod, Naprawa *naprawa);

int usunNapraweZSamochodu(Samochod *samochod, int id);

void zapiszSamochod(Samochod* samochod,FILE* plik);
#endif

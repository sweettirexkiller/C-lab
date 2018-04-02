#ifndef NAPRAWA_H
#define NAPRAWA_H

#include<assert.h>
#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
static int id_licznik_napraw = 0;


typedef struct Naprawa {
	int id;
	char nazwa[512];
	double roboczo_godziny;
}Naprawa;

Naprawa* stworzNaprawe(char *nazwa, double roboczo_godziny);

Naprawa* stworzNapraweOdUzytkownika();

void zniszczNaprawe(Naprawa *naprawa);

void wypiszNaprawe(Naprawa *naprawa);

void zapiszNaprawa(Naprawa* naprawa,FILE* plik);

#endif

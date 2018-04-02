#ifndef WARSZTAT_H
#define WARSZTAT_H
#define _CRT_SECURE_NO_WARNINGS
#include"samochod.h"
#include<stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

typedef struct Warsztat
{
	struct LinkedList* samochody;
	struct LinkedList* naprawy;
}Warsztat;


void zapiszDoPlikuTekstowego(Warsztat* warsztat,char* nazwaPliku);
void wczytajZPlikuTekstowego(Warsztat* warsztat,char* nazwaPliku);

Warsztat* inicjalizujWarsztat();

void zniszczWarsztat(Warsztat *warsztat);

void dodajSamochod(Warsztat *warsztat, Samochod *samochod);

void dodajNaprawe(Warsztat *warsztat, Naprawa *naprawa);

void wypiszWarsztat(Warsztat *warsztat);

int usunSamochod(Warsztat *warsztat, int id);

int usunNaprawe(Warsztat *warsztat, int id);

int modyfikujSamochod(Warsztat *Warsztat, int id);

int modyfikujNaprawe(Warsztat *warsztat, int id);


int porownajNaprawyNazwa(const void *a,const void *b);

int porownajNaprawyGodziny(const void *a, const void *b);

void sortujNapraweNazwa(Warsztat *warsztat);

void sortujNapraweGodziny(Warsztat *warsztat);

int porownajSamochodyMarka(const void *a, const void *b);

void sortujSamochodyMarka(Warsztat *warsztat);

int porownajSamochodyModel(const void *a, const void *b);

void sortujSamochodyModel(Warsztat *warsztat);

int porownajSamochodyPrzebieg(const void *a, const void *b);

void sortujSamochodyPrzebieg(Warsztat *warsztat);

int porownajSamochodyRocznik(const void *a, const void *b);

void sortujSamochodyRocznik(Warsztat *warsztat);

int porownajSamochodyLiczbaNapraw(const void *a, const void *b);

void sortujSamochodyLiczbaNapraw(Warsztat *warsztat);

void wyswietlSamochody(Warsztat *warsztat);

void wyswietlNaprawy(Warsztat *warsztat);

int dodajNapraweDoSamochoduWarsztat(Warsztat *warsztat, int idSamochodu, int idNaprawy);

int usunNapraweZSamochoduWarsztat(Warsztat *warsztat, int idSamochodu, int idNaprawy);
#endif

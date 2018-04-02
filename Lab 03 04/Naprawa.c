#include "Naprawa.h"

Naprawa* stworzNaprawe(char *nazwa, double roboczo_godziny) {
	Naprawa* naprawa = (Naprawa *)malloc(sizeof(Naprawa));
	assert(naprawa != NULL);
	assert(roboczo_godziny > 0);
	id_licznik_napraw++;
	naprawa->id = id_licznik_napraw;
	strcpy(naprawa->nazwa, nazwa);
	naprawa->roboczo_godziny = roboczo_godziny;

	return naprawa;
}

Naprawa* stworzNapraweOdUzytkownika() {
	Naprawa *naprawa = stworzNaprawe("a", 1.0);

	printf("Podaj parametry naprawy\n");
	printf("Podaj nazwe\n");
	scanf("%s", naprawa->nazwa);
	while (1)
	{
		printf("Podaj liczbe roboczogodzin\n");
		scanf("%lf", &naprawa->roboczo_godziny);
		if (naprawa->roboczo_godziny > 0) {
			break;
		}
		printf("Zly zakres czasu.\n");
	}

	return naprawa;
}


void zniszczNaprawe(Naprawa *naprawa) {
	assert(naprawa != NULL);
	free(naprawa);
	naprawa = NULL;
}

void wypiszNaprawe(Naprawa *naprawa) {
	printf("NAPRAWA %d. %s LICZBA ROBOCZOGODZIN: %.1lf\n", naprawa->id, naprawa->nazwa, naprawa->roboczo_godziny);
}

void zapiszNaprawa(Naprawa* naprawa,FILE* plik){
	fprintf(plik,"%d\n%s\n%lf\n",naprawa->id,naprawa->nazwa,naprawa->roboczo_godziny);
}

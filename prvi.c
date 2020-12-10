#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	char ime[20];
	char prez[20];
	int bod;
}student;

int brojR();
void unos(int, student*);
void ispis(student*, int);

int main() {
	int br;
	//broj redaka
	br = brojR();
	student* s;
	s = (student*)malloc(br * sizeof(student));
	//unos u datoteku
	unos(br, s);
	//ispis datoteke
	ispis(s, br);
	return 0;
}

int brojR() {
	FILE* ulz;
	int br = 1;
	ulz = fopen("proba.txt", "r");
	if (ulz == NULL) {
		printf("Greska");
		exit(1);
	}
	while (!feof(ulz)) {
		if (fgetc(ulz) == '\n') {
			br++;
		}
	}
	fclose(ulz);
	return br;
}

void unos(int br, student* s) {
	FILE* ulz;
	int i;
	ulz = fopen("proba.txt", "r");
	for (i = 0; i < br; i++) {
		fscanf(ulz, "%s %s %d", s[i].ime, s[i].prez, &s[i].bod);
	}
	fclose(ulz);
}

void ispis(student* s, int br) {
	int maks = 50;
	int i;
	for (i = 0; i < br; i++) {
		printf("%s %s %d/%d %f\n", (s + i)->ime, (s + i)->prez, (s + i)->bod, maks, ((float)(s + i)->bod / (float)maks * 100));
	}

}


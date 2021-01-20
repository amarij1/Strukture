#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
	char ime[20];
	char prez[20];
	int bod;
};
int brojR(char[]);
int unos(int, struct student*, char[]);
int ispis(int, struct student*, char[]);
int main() {
	int br = 0;
	char dat[20];
	struct student* st;
	st = (struct student*)malloc(br * sizeof(struct student));
	printf("Unesi ime datoteke\n");
	scanf("%s", dat);
	br = brojR(dat);
	unos(br, st, dat);
	ispis(br, st, dat);

	return 0;
}

int brojR(char dat[]) {
	FILE* ulz;
	int br = 1;
	char c;
	ulz = fopen(dat, "r");
	if (ulz == NULL) {
		printf("Greska, dokument ne postoji");
	}
	for (c = getc(ulz); c != EOF; c = getc(ulz)) {
		if (c == '\n') {
			br = br + 1;
		}
	}
	fclose(ulz);
	return br;
}

int unos(int br, struct student* st, char dat[]) {
	int i = 0;
	FILE* ulz;
	ulz = fopen(dat, "r");
	for (i = 0; i < br; i++) {
		fscanf(ulz, "%s %s %d", (st + i)->ime, (st + i)->prez, &(st + i)->bod);
	}
	fclose(ulz);
}

int ispis(int br, struct student* st, char dat[]) {
	int maks = 50;
	int i = 0;
	for (i = 0; i < br; i++) {
		printf("%s %s %d %d %d\n", (st + i)->ime, (st + i)->prez, (st + i)->bod, maks, ((st + i)->bod / maks * 100));
	}
}

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct polinom* pozicija;

struct polinom {
	int k;
	int e;
	pozicija next;
};

void unos(pozicija, char[]);
void suma(pozicija, pozicija, pozicija);
void produkt(pozicija, pozicija, pozicija);

int main() {
	struct polinom pol1, pol2, s, p;
	char datoteka[20];

	pol1.next = NULL;
	pol2.next = NULL;
	s.next = NULL;
	p.next = NULL;

	unos(&pol1, datoteka);
	unos(&pol2, datoteka);
	suma(pol1.next, pol2.next, &s);
	produkt(pol1.next, pol2.next, &p);

	return 0;
}

void unos(pozicija pol, char datoteka[]) {
	FILE* ulz;
	printf("Unesi ime datoteke");
	scanf("%s", datoteka);

	ulz = fopen(datoteka, "r");
	if (NULL == ulz)
	{
		printf("Nema datoteke");
		exit(1);
	}
	while (0 == feof(ulz))
	{
		fscanf(ulz, " %d %d", &pol->k, &pol->e);
	}
	fclose(ulz);
}

void suma(pozicija pol1, pozicija pol2, pozicija s) {
	while (pol1 != NULL && pol2 != NULL)
	{
		if (pol1->e == pol2->e)
		{
			s->e = pol1->e;
			s->k = pol1->k + pol2->k;
		}
	}
}

void produkt(pozicija pol1, pozicija pol2, pozicija p) {
	while (pol1 != NULL && pol2 != NULL)
	{
		if (pol1->k == pol2->k)
		{
			p->k = pol1->k;
			p->e = pol1->e + pol2->e;
		}
	}
}





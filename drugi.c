#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

struct osob;
typedef struct osob* pozicija;
typedef struct osob
{
	char ime[100];
	char prezime[100];
	int godina;
	pozicija next;
}osoba;
void UnesiEl(pozicija);
void Podatci(pozicija);
int Isp(pozicija);
void UnesiElK(pozicija, pozicija);
pozicija TraziEl(pozicija, char[]);


int main() {
	pozicija head = NULL, d;
	head = (pozicija)malloc(sizeof(osoba));
	head->next = NULL;
	char prezime[50];
	char a;
	printf("Odaberite opciju: \n \tu - Unesite novi element na pocetak liste \n \ti - Ispis liste \n \t
		z - Unesite novi element na kraj liste \n \tt - Trazenje elementa \n \t, v - van programa");
		while (1)
			scanf("%c", &a);
	switch (s)
	{
	case 'u':
		UnesiEl(head);
		break;
	case 'i':
		Isp(head->next);
		break;
	case 'z':
		UnesiElK(head->next, d);
		break;
	case 't':
		TraziEl(head, prezime);
		break;
	case 'v':
		return 0;
		break;

	}
	free(head);
	return 0;
}

void Umetni(pozicija p)
{
	pozicija d = NULL;
	d = (pozicija)malloc(sizeof(osoba));
	if (d == NULL)
		return 1;
	UnesiPodatke(d);
	d->next = p->next;
	p->next = d;
}

void Podatci(pozicija d)
{
	scanf(" %s", d->ime);
	scanf(" %s", d->prezime);
	scanf(" %d", &d->godina);
}

int Isp(pozicija p)
{
	printf("Sadrzaj elemenata");
	printf("%s %s %d\n", p->ime, p->prezime, p->godina);
}

void UnesiElK(pozicija d, pozicija p)
{
	while (d->next != NULL) {
		d = d->next;
	}
	Umetni(p);
}

pozicija TraziEl(pozicija p, char prezime[])
{
	while ((p->next != NULL) && strcmp(p->prezime, prezime) != NULL)
		p = p->next;
	return p;
}


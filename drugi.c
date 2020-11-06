#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct osoba* pozicija;

struct osoba {
	char ime[50];
	char prezime[50];
	int godina;
	pozicija next;
};

void ispis(pozicija);
void umetniPocetak(pozicija);
void unesiPodatke(pozicija);
void umetniKraj(pozicija);
pozicija pronadi(char[], pozicija);
void ispisJednog(pozicija p);
void brisi(char[], pozicija);
pozicija pronadiPret(char[], pozicija);

int main() {
	struct osoba head;
	head.next = NULL;
	char prezim[50];
	pozicija t;

	umetniPocetak(&head);
	umetniKraj(&head);
	ispis(head.next);
	t = pronadi(prezim, head.next);
	ispisJednog(t);
	brisi(prezim, &head);
	ispis(head.next);

	return 0;
}

void ispis(pozicija p) {
	while (p != NULL)
	{
		printf("%s, %s, %d\n", p->ime, p->prezime, p->godina);
		p = p->next;
	}
}
void ispisJednog(pozicija p) {

	printf("%s, %s, %d\n", p->ime, p->prezime, p->godina);
}

void umetniPocetak(pozicija p) {
	pozicija q;

	q = (pozicija)malloc(sizeof(struct osoba));
	unesiPodatke(q);

	q->next = p->next;
	p->next = q;
}

void unesiPodatke(pozicija q) {

	printf("Unesi prezime\n");
	scanf("%s", q->prezime);
	printf("Unesi ime\n");
	scanf("%s", q->ime);
	printf("Unesi godinu\n");
	scanf("%d", &q->godina);
}

void umetniKraj(pozicija p) {
	pozicija q;

	q = (pozicija)malloc(sizeof(struct osoba));
	unesiPodatke(q);

	while (p->next != NULL)
	{
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
}

pozicija pronadi(char prezim[], pozicija p) {
	printf("Unesi prezime elementa kojeg zelis pronaci\n");
	scanf("%s", prezim);
	while (p != NULL && strcmp(p->prezime, prezim) != NULL)
		p = p->next;
	if (p == NULL)
		printf("Element ne postoji.");
	return p;
}

pozicija pronadiPret(char prezim[], pozicija p) {
	printf("Unesi prezime elementa kojeg zelis pronaci\n");
	scanf("%s", prezim);
	while (p->next != NULL && strcmp(p->next->prezime, prezim) != NULL) {
		p = p->next;
	}
	if (p->next == NULL) {
		printf("Element ne Postoji");
		return NULL;
	}
	return p;
}

void brisi(char prezim[], pozicija p) {
	pozicija pret;

	pret = pronadiPret(prezim, p);
	if (pret != NULL) {
		p = pret->next;
		pret->next = p->next;
		free(p);
	}
}


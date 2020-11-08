#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


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
//treci zadatak
void unesiIza(char[], pozicija);
void unesiIspred(char[], pozicija);
void sort(pozicija );
void upisd(pozicija);
void upisc(pozicija)

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
	//treci zadatak
	unesiIza(prezim, &head);
	unesiIspred(prezim; &head);
	ispis(head.next);
	printf("Sortiranje");
	sort(&head);
	ispis(head.next);
	upisd(head.next);
	upisc(head.next);
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

pozicija pronadiPret(char prezim, pozicija p) {
	printf("Unesi prezime elementa kojeg zelis pronaci\n");
	scanf("%s", prezim);
	while (p->next != NULL && strcmp(p->next->prezime, prezim) != NULL) {
		p = p->next;
	}
	if (p->next = NULL) {
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
//treci zadatak
void unesiIza(char prezim[], pozicija p) {
	p = pronadi(prezim, p);
	if (p != NULL)
		umetniPocetak(p);
}

void unesiIspred(char prezim[], pozicija p) {
	p = pronadiPret(prezim, p);
	if(p!=NULL)
		umetniPocetak(p)
}

void sort(pozicija p) {
	pozicija i, preti, temp, kraj;
	kraj = NULL;
	while (p->next != kraj)
	{
		preti = p;
		i = p->next;
		while (i->next != kraj)
		{
			if (strcmp(i->prezime, i->next->prezime) > 0)
			{
				temp = i->next;
				preti->next = temp;
				i->next = temp->next;
				temp->next = i;

				i = temp;
			}
			preti = i;
			i = i->next;
		}
		kraj = i;
	}
}

void upisd(pozicija p) {
	FILE* izl;
	izl = fopen("datoteka1.txt", "w");
	if (izl == NULL) {
		printf("nema datoteke");
	}
	while (p->next != NULL) {
		fprintf(izl, "%s\n", p->ime);
		fprintf(izl, "%s", p->prezime);
		fprintf(izl, "%d,", p->godina);
		p = p->next;
	}
	fclose(izl);
}

void upisc(pozicija p) {
	FILE* ulz;
	ulz = fopen("datoteka2.txt", "r");
	if (ulz = NULL) {
		printf("nema datoteke");
	}
	while (feof(ulz) == 0) {
		pozicija q;
		q = (pozicija)malloc(sizeof(struct osoba));
		fscanf(ulz, "%s", q->ime);
		fscanf(ulz, "%s", q->prezime);
		fscanf(ulz, "%d", &q->godina);
		q->next = p->next;
		p->next = q;
	}
	fclose(ulz);
}

//kraj

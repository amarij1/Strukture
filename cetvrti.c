#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct polinom* poz;

struct polinom {
	int k;
	int e;
	poz next;
};

void unos(poz, char[]);
void unosP(poz, int, int);
void ispis(poz);
void suma(poz, poz, poz);
void produkt(poz, poz, poz);

int main() {
	struct polinom pol1, pol2, s, p;
	char dat[20];

	pol1.next = NULL;
	pol2.next = NULL;
	s.next = NULL;
	p.next = NULL;

	unos(&pol1, dat);
	unos(&pol2, dat);
	suma(pol1.next, pol2.next, &s);
	produkt(pol1.next, pol2.next, &p);
	ispis(pol1.next);
	ispis(pol2.next);
	ispis(s.next);
	ispis(p.next);

	return 0;
}

void unos(poz p, char dat[]) {
	poz q;
	FILE* ulz;
	printf("Unesi ime datoteke\n");
	scanf("%s", dat);

	ulz = fopen(dat, "r");
	if (NULL == ulz)
	{
		printf("Nema datoteke");
		exit(1);
	}
	while (0 == feof(ulz))
	{
		q = (poz)malloc(sizeof(struct polinom));
		fscanf(ulz, " %d %d", &q->k, &q->e);
		while (p->next != NULL && p->next->e > q->e) {
			if (p->next->e == q->next->e) {
				p->next->k = p->next->k + q->k;
			}
			p = p->next;
		}
		if (q != NULL) {
			q->next = p->next;
			p->next = q;
		}

	}
	fclose(ulz);
}

void unosP(poz p, int k, int e) {
	poz q;
	while (p != NULL) {
		p = p->next;
	}
	q = (poz)malloc(sizeof(struct polinom));
	q->e = p->e;
	q->k = p->k;
	q->next = p->next;
	p->next = q;

}

void ispis(poz p)
{
	while (p != NULL) {
		if (p->k > 0)
			printf("\n\t+%d*x^%d\n", p->k, p->e);
		else
			printf("\n\t%d*x^%d\n", p->k, p->e);
		p = p->next;
	}
}

void suma(poz p1, poz p2, poz s) {
	poz temp;
	while (p1 != NULL && p2 != NULL) {
		if (p1->e == p2->e) {
			unosP(s, p1->k + p2->k, p1->e);
			p1 = p1->next; p2 = p2->next;
		}
		else if (p1->e > p2->e) {
			unosP(s, p1->k, p1->e);
			p1 = p1->next;
		}
		else {
			unosP(s, p2->k, p2->e);
			p2 = p2->next;
		}
	}
	if (p1 != NULL) temp = p1;
	else temp = p2;
	while (temp != NULL) {
		unos(s, temp->k, temp->e);
		temp = temp->next;
	}
}
void produkt(poz p1, poz p2, poz p) {
	poz pr, dr, poc, temp;
	poc = p;
	pr = p1;
	dr = p2;
	while (p1 != NULL) {
		while (p2 != NULL) {
			int k, e;
			k = pr->k * dr->k;
			e = pr->e *= dr->e;
			unosP(p, k, e);
			dr = dr->next;
		}
		dr = p2;
		pr = p1->next;
	}
	//zbrajanje elemenata sa istim potencijama
	pr = poc;
	while (pr != NULL && pr->next != NULL) {
		dr = pr;
		while (dr->next != NULL) {
			if (pr->e == dr->next->e) {
				pr->k = pr->k = dr->next->k;
				temp = dr->next;
				dr->next = dr->next->next;
				free(temp);
			}
			else
				dr = dr->next;
		}
		pr = pr->next;

	}

}


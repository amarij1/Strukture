#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct lista* poz;
struct lista {
	int el;
	poz next;
};
void push(poz, int);
int pop(poz);
int unos(poz);


int main() {
	struct lista head;
	head.next = NULL;
	int r=0;
	r=unos(&head);
	printf("rezultat je %d",r);
	return 0;
}
void push(poz p, int x) {
	poz q;
	q = (poz)malloc(sizeof(struct lista));
	q->el = x;
	q->next = p->next;
	p->next = q;
}
int pop(poz p) {
	poz temp;
	int br=0;
	if (p->next != NULL) {
		temp = p->next;
		p->next = temp->next;
		br = temp->el;
		free(temp);
	}
	return br;
}

int unos(poz p) {
	int i1,i2, rez;
	FILE* ulz;
	char a=4;
	ulz = fopen("proba.txt", "r");
	if (ulz == 0) {
		printf("Nema datoteke");
	}
	while ((a = getc(ulz))!=EOF) {
		switch (a) {
		case '+':
			i2 = pop(p);
			i1 = pop(p);
			push(p, i1 + i2);
			break;
		case '-':
			i2 = pop(p);
			i1 = pop(p);
			push(p, i1 - i2);
			break;
		case '*':
			i2 = pop(p);
			i1 = pop(p);
			push(p, i1 * i2);
			break;
		case '/':
			i2 = pop(p);
			i1 = pop(p);
			push(p, i1 / i2);
			break;
		default:
			push(p, a-'0');
			break;
		}
	}
	fclose(ulz);
	rez = pop(p);
	return rez;
}

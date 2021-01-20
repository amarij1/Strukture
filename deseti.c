#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stablo* pozp;
struct stablo {
	char elp;
	pozp left;
	pozp right;
};
typedef struct stak* pozd;
struct stak {
	pozp eld;
	pozd next;
};

pozd pushd(pozd, pozp);
pozp popd(pozd);
char* ispis(pozicija, char[])
void unos(pozp, pozd);
void push(pozp, int);
int pop(pozp);
int main() {
	char dat[100];
	dat = ispis(&root, dat)
	FILE * ulz = fopen("proba.txt", "w");
	fprintf(ulz,"%s", dat);
	return 0;
}
pozd pushd(pozd p, pozp q) {
	pozd s;
	if (p == NULL) {
		return NULL;
	}
	s = (pozd)malloc(sizeof(struct stak));
	s->eld = q;
	s->next = p->next;
	p->next = s;
}
pozp popd(pozd p) {
	pozd q;
	pozp s;
	if (p == NULL) { 
		return NULL;
	}
	else {
		q = p->next;
		p->next = q->next
		s = q->eld
		free(q);
	}
	return q;
}

char* ispis(pozicija p, char dat[]) {
	if (p = NULL) {
		return NULL;
	}
	ispis(p->left, dat);
	strcat(dat, " ");
	strcat(dat, p->elp);
	ispis(p->right, dat);
}
void unos(pozp p, pozd s) {
	int i1, i2, rez;
	FILE* ulz;
	char a = 4;
	ulz = fopen("proba.txt", "r");
	if (ulz == 0) {
		printf("Nema datoteke");
	}
	while ((a = getc(ulz)) != EOF) {
		switch (a) {
		case '+':
			i2 = pop(p);
			i1 = pop(p);
			push(p, i1 + i2);
			q = napravi(i1 + i2);
			umetni(p, q);
			break;
		case '-':
			i2 = pop(p);
			i1 = pop(p);
			push(p, i1 - i2);
			q = napravi(i1 + i2);
			umetni(p, q);
			break;
		case '*':
			i2 = pop(p);
			i1 = pop(p);
			push(p, i1 * i2);
			q = napravi(i1 + i2);
			umetni(p, q);
			break;
		case '/':
			i2 = pop(p);
			i1 = pop(p);
			push(p, i1 / i2);
			q = napravi(i1 + i2);
			umetni(p, q);
			break;
		default:
			push(p, a - '0');
			q = napravi(i1 + i2);
			umetni(p, q);
			break;
		}
	}
	fclose(ulz);
	return 1;
}
pozp umetni(pozp p, pozp q) {
	if (p == NULL)return el;
	if (p->elp > q->elp) {
		p->left = umetni(p->left, q);
	}
	else if (p->elp < q->elp) {
		p->right = umetni(p->right, q);
	}
	else {
		free(q);
	}
	return p;
}
pozp napravi(int el) {
	pozp q = (pozp)malloc(sizeof(struct stablo));
	q->elp = el;
	q->left = q->right = NULL;
	return q;
}
}
void push(pozp p, int x) {
	poz q;
	q = (pozp)malloc(sizeof(struct stablo));
	q->el = x;
	q->next = p->next;
	p->next = q;
}
int pop(pozp p) {
	pozp temp;
	int br = 0;
	if (p->next != NULL) {
		temp = p->next;
		p->next = temp->next;
		br = temp->elp;
		free(temp);
	}
	return br;
}
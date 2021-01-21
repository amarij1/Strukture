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

pozp umetni(int el);
void umetniEl(pozp, pozp, pozp);
pozd push(pozd, pozp);
pozp pop(pozd);
void ispis(pozp);
void unos(pozp, pozd);
int main() {
	struct stablo headp;
	headp.left = NULL;
	headp.right = NULL;
	struct stak headd;
	headd.next = NULL;
	unos(&headp, &headd);
	FILE* ulz;
	ulz = fopen("proba.txt", "w");
	ispis(&headp, ulz);
	fclose(ulz);
	return 0;
}

void ispis(pozp p, FILE* ulz) {
	if (p == NULL)return;
	ispis(p->left, ulz);
	fprintf(ulz, "%c", p->elp);
	ispis(p->right, ulz);
}
void umetniEl(char a, pozp s, pozp p, pozp q) {
	pozp temp;
	temp = (pozp)malloc(sizeof(struct stablo));
	temp->elp = a;
	temp->right = p;
	temp->left = q;
}
pozp umetni(int el) {
	pozp temp;
	temp = (pozp)malloc(sizeof(struct stablo));
	temp->left = NULL;
	temp->right = NULL;
	temp->elp = el;
	return temp;
}

pozd push(pozd p, pozp q) {
	pozd s;
	if (p == NULL) {
		return NULL;
	}
	s = (pozd)malloc(sizeof(struct stak));
	s->eld = q;
	s->next = p->next;
	p->next = s;
}
pozp pop(pozd p) {
	pozd q;
	pozp s;
	if (p == NULL) {
		return NULL;
	}
	else {
		q = p->next;
		p->next = q->next;
		s = p->eld;
		free(q);
	}
	return s;
}

void unos(pozp p, pozd s) {
	pozp i1, i2, rez;
	pozp temp;
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
			umetniEl(a, p, i2, i1);
			break;
		case '-':
			i2 = pop(p);
			i1 = pop(p);
			umetniEl(a, p, i2, i1);
			break;
		case '*':
			i2 = pop(p);
			i1 = pop(p);
			umetniEl(a, p, i2, i1);
			break;
		case '/':
			i2 = pop(p);
			i1 = pop(p);
			umetniEl(a, p, i2, i1);
			break;
		default:
			temp = umetni(a - '0');
			push(s, temp);
			break;
		}
	}
	fclose(ulz);
}
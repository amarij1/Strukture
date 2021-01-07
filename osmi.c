#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct dir* poz;
struct dir {
	char el[50];
	poz sibling;
	poz child;
};
typedef struct put* pozd;
struct put {
	int eld;
	pozd next;
};

void push(pozd, char[]); 
void pop(pozk);
void print(pozk);
int md(char[], poz);//radi novi direktorij
poz cdDir(char[], poz, pozd);// ulazi u novi  direktorij
poz cdN(poz, poz, poz);// izlazi iz direktorija
int Dir(poz);//vidit sta se nalazi u mapi
void remov(poz);
poz trazi(poz, char[]);

int main() {

	struct dir root;
	poz t;
	struct put path;
	root.sibling = NULL;
	root.child = NULL;
	char ime[50];
	char imet[50];
	md(ime, &root);
	md(ime, &root);
	scanf("%s", imet);//unosenje imena direktorija u koji zelimo uci
	trazi(&root, imet);//trazenje tog direktorija
	t = cdDir(ime, &root, &path);//ulazak u taj direktorija
	md(ime, t);//izrada novog pod-direkotorija u tom direktoriju
	t=cdN(&root, t, &path);//izlazak iz trenutnog direktorija
	Dir(t);//prikaz tog direktorija
	remov(&root);//izlaz
	return 0;
}

int md(char ime[], poz p) {
	scanf("%s", ime);
	struct dir* q;
	q = (poz)malloc(sizeof(struct dir));
	q->child = NULL;
	q->sibling = NULL;
	strcpy(q->el, ime);
	if (NULL == q)
		printf("\nGreska\n");
	else
	{
		if (p->child = NULL) {
			p->child = q;
		}
		else {
			q->child = p->child;
			p->child = q;
		}
	}
}

poz cdDir(char ime[], poz p, pozd s) {
	poz temp = p->child;
	while (temp != NULL && strcmp(temp->el, ime) != 0) {
		temp = temp->sibling;
	}
	if (NULL == temp) {
		printf("Nema direktorija");
	}
	else{
		push(s, ime);
		printf("C:");
		print(s);
	}
	return temp;
}
poz cdN(poz p, poz t, pozd s) {
	t = traziP(p, t);
	pop(p);
	printf("C:");
	print(s);
	return t;
}

int Dir(poz t) {
	if (t->child == NULL) {
		return 1;
	}
	else {
		t = t->child;
		while (t->sibling != NULL) {
			printf("%s", t->el);
			t = t->sibling;
		}
	}
}
void remov(poz p) {
	if (p == NULL)return;
	remov(p->sibling);
	remov(p->child);
	free(p);
}

void push(pozd p, char x[]) {
	pozd q;
	q = (pozd)malloc(sizeof(struct put));
	q->eld = x;
	q->next = p->next;
	p->next = q;
}
void pop(pozd p) {
	pozd temp;
	if (p->next != NULL) {
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
}
void print(pozd p) {
	while (p != NULL) {
		printf("\\");
		printf("%d ", p->eld);
		p = p->next;
	}
}

poz trazi(poz p, char ime[]) {
	if (strcmp(p->el, ime) == 0){return p;}
	else {
		if (p == NULL)return;
		trazi(p->sibling, ime);
		trazi(p->child, ime);
	}
}

poz traziP(poz p, poz t) {
		if (p == NULL)return;
		traziP(p->sibling, t);
		if (strcmp(p->child->el, t->el) == 0) { return p; }
		traziP(p->child, t);
}
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct lista* pozicija;
struct lista {
	int el;
	pozicija next;
};
//simulira rad reda pomocu listi
pozicija push(pozicija, int);
void pop(pozicija);
void print(pozicija);
int nBroj(int, int);

int main() {
	struct lista head;
	head.next = NULL;
	pozicija zadnji;
	zadnji = head.next;
	char i[20];
	int K = 0;
	int x = 0;
	printf("Unesi\n\tU za umetnje elemenata\n\tI za brisanje elementa\n\tP za ispis stoga\n\tK za kraj\n");
	while (K == 0) {
		scanf("%c", i);
		switch (*i) {
		case 'U':
			x = nBroj(100, 10);
			zadnji=push(&head, x);
			printf("\njesam\n");
			break;
		case 'I':
			pop(&head);
			printf("\njesam\n");
			break;
		case 'P':
			print(head.next);
			printf("\njesam\n");
			break;
		case 'K':
			K = 1;
			printf("\njesam\n");
			break;
		}
	}
	return 0;
}
//umetanje novog elementa
pozicija push(pozicija p, int x) {
	pozicija q;
	while (p->next != NULL) {
		p = p->next;
	}
	q = (pozicija)malloc(sizeof(struct lista));
	q->el = x;
	q->next = p->next;
	p->next = q;
	return q;
}
//brisanje elementa
void pop(pozicija p) {
	pozicija temp;
	if (p->next != NULL) {
		temp = p->next;
		p->next = temp->next;
		free(temp);
	}
}

int nBroj(int gor, int dol) {
	srand(time(NULL));
	int n = (rand() %
		(gor - dol + 1)) + dol;
	return n;
}

void print(pozicija p) {
	while (p != NULL) {
		printf("%d ", p->el);
		p = p->next;
	}
}
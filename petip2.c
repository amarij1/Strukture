#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct lista* pozicija;

struct lista {
	int el;
	pozicija next;
};

void unesi(pozicija, int);
void ispis(pozicija);
void unija(pozicija, pozicija, pozicija);
//void presjek(pozicija, pozicija, pozicija);

int main() {
	struct lista l1, l2, p, u;
	char i[20];
	int K = 0;
	l1.next = NULL;
	l2.next = NULL;
	p.next = NULL;
	u.next = NULL;
	printf("\nUnesi slovo,\n A za unos novog elementa u prvu listu, S za unos novog elementa u drugu listu");
	printf("\nD za ispis prve liste, F za ispis druge liste, G za ispis liste presjeka, H za ispis liste unije ");
	printf("\nU za uniju te dvije liste, P za presjek te dvi liste te K za izlaz iz programa\n");
	while (K == 0) {
		scanf("%c", &i);
		switch (*i) {
		case'K':
			K = 1;
			break;
		case 'A':;
			int xt = 0;
			printf("Unesi element(broj)\n");
			scanf("%d", &xt);
			unesi(&l1, xt);
			printf("\nJesam\n");
			break;
		case 'S':;
			int xy = 0;
			printf("Unesi element(broj)\n");
			scanf("%d", &xy);
			unesi(&l2, xy);
			printf("\nJesam\n");
			break;
		case 'D':
			ispis(&l1);
			printf("\nJesam\n");
			break;
		case 'F':
			ispis(&l2);
			printf("\nJesam\n");
			break;
		case 'G':
			ispis(&p);
			printf("\nJesam\n");
			break;
		case 'H':
			ispis(&u);
			printf("\nJesam\n");
			break;
		case'U':
			unija(&l1, &l2, &u);
			printf("\nJesam\n");
			break;
		case'P':
			presjek(&l1, &l2, &u);
			printf("\nJesam\n");
			break;
		}
	}
	puts("Kraj programa");

	return 0;
}

void unesi(pozicija p, int x) {

	pozicija q;
	q = (pozicija)malloc(sizeof(struct lista));
	q->el = x;
	while (p->next != NULL && p->next->el < q->el) {
		p = p->next;
	}
	if (q != NULL) {
		q->next = p->next;
		p->next = q;
	}
}

void ispis(pozicija p) {
	printf("\n");
	p = p->next;
	while (p != NULL)
	{
		printf("\t%d", p->el);
		p = p->next;
	}
	printf("\n");
}

void unija(pozicija l1, pozicija l2, pozicija u) {
	while (l1->next != NULL || l2->next != NULL) {
		if (l1->el < l2->el) {
			unesi(&u, l1->el);
			l1 = l1->next;
		}
		else if (l2->el < l1->el) {
			unesi(&u, l2->el);
			l2 = l2->next;
		}
		else {
			unesi(&u, l1->el);
			l1 = l1->next;
			l2 = l2->next;

		}
		u = u->next;
	}
}

void presjek(pozicija l1, pozicija l2, pozicija u) {
	while (l1->next != NULL || l2->next != NULL) {
		if (l1->el < l2->el) {
			l1 = l1->next;
		}
		else if (l2->el < l1->el) {
			l2 = l2->next;
		}
		else {
			unesi(&u, l1->next);
			l1 = l1->next;
			l2 = l2->next;

		}
		u = u->next;
	}
}





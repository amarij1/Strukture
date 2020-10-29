#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
	char ime[20];
	char prez[20];
	int bodovi;
}student;

int main() {
	int n = 0, br = 0, maks = 0, u = 0, is = 0;
	char c;
	student* s;

	char dat[20];

	printf("Upisi naziv datoteke\n");
	scanf("%s", dat);

	FILE* ulz;
	ulz = fopen(dat, "r");
	if (ulz == NULL)
	{
		printf("Greska");
		exit(1);
	}
	//alokacija memorije
	s = (student*)malloc(br * sizeof(student));
	//broji retke, tj studente
	while (!feof(ulz))
	{
		if (fgetc(ulz) == '\n')
		{
			br++;
		}
	}
	//maks broj bodova
	printf("\nUnesi maksimalan broj bodova\n");
	scanf("%d", &maks);
	//upis datoteke
	for (u = 0; u < br; u++) {
		fscanf(ulz, "%s %s %d", s[u].ime, s[u].prez, &s[u].bodovi);
	}
	//ispis datoteke
	for (is = 0; is < br; is++) {
		printf("%s %s %d %f\n", s[is].ime, s[is].prez, &s[is].bodovi, ((float)s[is].bodovi / (float)maks * 100));
	}



	fclose(ulz);
	free(s);
	return 0;
}
#include"Player.h"
#include <stdio.h>
#include <stdlib.h>
int lenght, width;
Hos* Create()
{
	Hos* jatekos;

	jatekos = (Hos*)calloc(1, sizeof(Hos));
	if (!jatekos) {
		printf("Nem sikerult a jatekos letrehozasa!");
		return 0;
	}
	jatekos->name = (char*)calloc(50, sizeof(char));
	if (!jatekos->name) {
		printf("Nem sikerult a jatekos nevenek letrehozasa!");
		return 0;
	}
	jatekos->hp = (int*)calloc(10, sizeof(int)); //Alap hp 100
	if (!jatekos->hp) {
		printf("Nem sikerult  hp-nak letrehozasa!");
		return 0;
	}
	jatekos->mp = (int*)calloc(10, sizeof(int));
	if (!jatekos->mp) {
		printf("Nem sikerult  mp-nek letrehozasa!"); //Alap mana 250
		return 0;
	}
	jatekos->level = (int*)calloc(10, sizeof(int)); //Alap szint 1
	if (!jatekos->level) {
		printf("Nem sikerult  level-nek letrehozasa!");
		return 0;
	}
	jatekos->xp = (int*)calloc(50, sizeof(int)); //Alap xp szint 0 kovetkezo szint lepes 100, 250,500.
	if (!jatekos->xp) {
		printf("Nem sikerult  xp-nek letrehozasa!");
		return 0;
	}

	return jatekos;
}

void Destroy(Hos* jatekos)
{
	free(jatekos->name);
	free(jatekos->hp);
	free(jatekos->mp);
	free(jatekos->level);
	free(jatekos->xp);
	free(jatekos);
}

void KiirHosStatistica(Hos* jatekos)
{
	printf("Neve: %s\n",jatekos->name);
	printf("Elet szintje: %d\n", jatekos->hp);
	printf("Mana szintje: %d\n", jatekos->mp);
	printf("Tapasztalati pontjai: %d\n", jatekos->xp);
	printf("Szintje: %d\n", jatekos->level);

}

void BeolvasHosAdatait(Hos* jatekos)
{
	printf("Irja be a hose nevet!");
	scanf("%[^\n]\n", jatekos->name);
	jatekos->hp = 100;  //Alap ertekek 
	jatekos->mp = 250;
	jatekos->xp = 0;
	jatekos->level = 1;
	
}
char** BeolvasPalya(const char* file)
{

	FILE* fin = fopen(file, "rt");
	if (!fin) {
		printf("Sikertelen belovasasa a palyanak1!");
		return 0;
	}

	fscanf(fin, "%i%i\n", &lenght, &width);

	char** level = (char**)(calloc(lenght, sizeof(char*)));
	if (!level) {
		printf("Sikertelen belovasasa a palyanak2!");
		return 0;
	}
	for (int i = 0; i < lenght; ++i) {
		level[i] = (char*)(calloc(width, sizeof(char)));
	}
	for (int i = 0; i < lenght; ++i) {
		for (int j = 0; j < width; ++j) {
			fscanf(fin, "%c\n", &level[i][j]);
		}
	}
	return level;
}

void KiirPalya(char** level)
{
	for (int i = 0; i < lenght; ++i) {
		for (int j = 0; j < width; ++j) {
			if (level[i][j] == '3' && (i == 0 || i == lenght - 1)) {
				printf("-");
			}
			else if (level[i][j] == '3') {
				printf("|");
			}
			if (level[i][j] == '0') {
				printf(" ");
			}
			if (level[i][j] == '1') {
				printf("*");
			}
			if (level[i][j] == 'C') {
				printf("X");
			}
			if (level[i][j] == 'H') {
				printf("H");
			}
			if (level[i][j] == 'L') {
				printf(" "); //rejtet lada 
			}
		}
		printf("\n");
	}
}

#include "Player.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include<stdio.h>
#include<stdlib.h>

int main() {
	int v1;
	Hos* j1;
	j1 = Create();
	BeolvasHosAdatait(j1);
	printf("Udvozollek %s a Dragons and Magic vilagaban!\nA feladatod az ellensegek legyozese a relytet kincsek megtalalasa(opcionalis) es a cel ellerese\n",j1->name);
	printf("A palyan a * a hallalos tuskeket mutatja ameleykhez hozza erve veget er a jatek ugyanigy ha kimesz a palyarol az is GAME OVER!\n");
	printf("Sok sikert a jatekhoz!\nRemelem keszen alsz a galandra!\n 1.Igen\n 2.Nem\n");
	scanf("%d", &v1);
	switch (v1)
	{
	case 1:
		printf("Remek kezdodjon a jatek!\n");
		KiirHosStatistica(j1);
		char** level1;
		level1 = BeolvasPalya("be1.txt");
		printf("Egyes szint:\n");
		Mozgas(level1, j1);
		printf("Gratulalok egy szint telyesitve!\n");
		char** level2;
		level2 = BeolvasPalya("be2.txt");
		printf("Masodik szint:\n");
		KiirHosStatistica(j1);
		Mozgas(level2, j1);
		printf("Gratulalok masodik szint telyesitve!\n");
		printf("Utolso szint kezdodik!\n");
		char** level3;
		level3 = BeolvasPalya("be3.txt");
		printf("Harmadik szint:\n");
		KiirHosStatistica(j1);
		Mozgas(level3, j1);
		printf("Gratulalok jatek telyesitve\n");
		if (j1->level >= 1150) {
			printf("Elerted a legnagyobb szintet!\n Achievement unlocked!\n MAXED OUT!\n");
		}
	default:
		printf("Lekozelebb talalkozunk amikor ugy erzed hogy keszen allsz a kallandra!\n");
		exit(1);
	}

	return 0;
}
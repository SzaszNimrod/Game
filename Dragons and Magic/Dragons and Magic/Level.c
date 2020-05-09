#include"Level.h"
#include <stdio.h>
#include <stdlib.h>
int lenght, width;
char** BeolvasPalya(const char* file)
{
	
	FILE* fin = fopen(file, "rt");
	if (!fin) {
		printf("Sikertelen belovasasa a palyanak!");
		return 0;
	}
	
	fscanf(fin, "%i%i\n", &lenght, &width);

	char** level = (char**)(calloc(lenght, sizeof(char*)));
	if (!level) {
		printf("Sikertelen belovasasa a palyanak!");
		return 0;
	}
	for (int i = 0; i <lenght; ++i) {
		level[i] = (char*)(calloc(width, sizeof(char)));
	}
	for (int i = 0; i <lenght; ++i) {
		for (int j = 0; j <width; ++j) {
			fscanf(fin, "%c\n", &level[i][j]);
		}
	}
	return level;
}

void KiirPalya(char** level)
{
	for (int i = 0; i <lenght; ++i) {
		for (int j = 0; j <width ; ++j) {
			if (level[i][j] == '3' && (i == 0 || i ==  lenght- 1)) {
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
			if (level[i][j] == 'R') {
				printf("X");
			}
			if (level[i][j] == 'P') {
				printf("P");
			}
		}
		printf("\n");
	}
}


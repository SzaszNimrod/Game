#include "Player.h"
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include<stdio.h>
#include<stdlib.h>

int main() {
	char** level1;
	level1 = BeolvasPalya("be1.txt");
	printf("Egyes szint:\n");
	KiirPalya(level1);




	return 0;
}
#pragma once
#pragma once
#ifndef LEVEL_H
#define LEVEL_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include<stdio.h>
#include <string.h>

typedef struct Level {
	int	length; // palya hossza
	int width; //palya szelesege
}Level;

char** BeolvasPalya (const char* file);
void KiirPalya(Level* level);






#endif//!LEVEL_H
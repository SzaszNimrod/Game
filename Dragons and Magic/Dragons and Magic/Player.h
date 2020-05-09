#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN
#include<stdio.h>
#include <string.h>


typedef struct Player {
	char* name;  //jatekos neve
	int hp; // jatekos elet pontjai
	int mp;  //jatekos mana/energia pontjai
	int level; // jatekos szintje
	int xp; //jatekos tapasztalati pontja a kovetkezo szintlepesre szugseges ami kinyit uj keppeseget
}Hos;

Hos* Create();    //Letrehoza a jatekost
void Destroy(Hos* jatekos);  //Kitorli a jatekos adatait
void KiirHosStatistica(Hos* jatekos); //Kiirja a jatekos adatait 
void BeolvasHosAdatait(Hos* jatekos); // beolvasa a jatekos adatait 




char** BeolvasPalya(const char* file); // palya beolvasa
void KiirPalya(char** level); //palya kiiratasa






#endif//!PLAYER_H
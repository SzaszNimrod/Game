#include"Player.h"

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
}

Hos* BeolvasHosAdatait()
{
	return NULL;
}

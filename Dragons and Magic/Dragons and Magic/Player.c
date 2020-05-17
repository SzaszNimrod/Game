#include"Player.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

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
	jatekos->atk = (int*)calloc(50, sizeof(int)); //Alap atk ertek 15.
	if (!jatekos->atk) {
		printf("Nem sikerult  atk-nak a letrehozasa!");
		return 0;
	}
	jatekos->def = (int*)calloc(50, sizeof(int)); //Alap def ertek 10.
	if (!jatekos->def) {
		printf("Nem sikerult  def-nek a letrehozasa!");
		return 0;
	}
	jatekos->mpatk = (int*)calloc(50, sizeof(int)); //Alap mpatk ertek 30.
	if (!jatekos->mpatk) {
		printf("Nem sikerult  mpatk-nek a letrehozasa!");
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
	free(jatekos->atk);
	free(jatekos->def);
	free(jatekos->mpatk);
	free(jatekos);
}

void KiirHosStatistica(Hos* jatekos)
{
	printf("Neve: %s\n",jatekos->name);
	printf("Elet szintje: %d\n", jatekos->hp);
	printf("Mana szintje: %d\n", jatekos->mp);
	printf("Tamado ereje: %d\n", jatekos->atk);
	printf("Magikus tamado ereje: %d\n", jatekos->mpatk);
	printf("Vedekezo ereje: %d\n", jatekos->def);
	printf("Tapasztalati pontjai: %d\n", jatekos->xp);
	printf("Szintje: %d\n", jatekos->level);

}

void BeolvasHosAdatait(Hos* jatekos)
{
	printf("Irja be a hose nevet:\n");
	scanf("%[^\n]", jatekos->name);
	jatekos->hp = 100;  //Alap ertekek 
	jatekos->mp = 250;
	jatekos->atk = 15;
	jatekos->mpatk = 30;
	jatekos->def = 10;
	jatekos->xp = 0;
	jatekos->level = 1;
	
}

void BeolvasEllensegAdataitS(Hos* jatekos)
{

	jatekos->hp = 650;  //Alap ertekek Sarkany
	jatekos->atk = 50;
	jatekos->def = 100;
}

void BeolvasEllensegAdataitG(Hos* jatekos)
{

	jatekos->hp = 80;  //Alap ertekek Goblin
	jatekos->atk = 20;
	jatekos->def = 3;
	
}

void KiirEllensegStatisticaS(Hos* jatekos)
{

	printf("Neve: Sarkany\n");
	printf("Elet szintje: %d\n", jatekos->hp);
	printf("Tamado ereje: %d\n", jatekos->atk);
	printf("Vedekezo ereje: %d\n", jatekos->def);
	


}

void KiirEllensegStatisticaG(Hos* jatekos)
{

	printf("Neve: Goblin\n");
	printf("Elet szintje: %d\n", jatekos->hp);
	printf("Tamado ereje: %d\n", jatekos->atk);
	printf("Vedekezo ereje: %d\n", jatekos->def);
}

int Harc(Hos* Tamado, Hos* Vedekezo)
{
	int Tenylegessebzes = Tamado->atk - Vedekezo->def;
	int Tenylegessebzes1 = Vedekezo->atk - Tamado->def;
	int Tenylegessebzes2= Tamado->mpatk- Vedekezo->def;
	int mana;
	int valasz;
	printf("Valasz ki a lehetosegeid:\n1.Tamadas kardal\n2.Tamadas magiaval(50 mana)\n3.Menekules(hp vesztesegel jarhat!)\n");
	while (Vedekezo->hp || Tamado->hp <= 0)
	{
		scanf("%d", &valasz);
		switch (valasz) {
		case 1:

			Vedekezo->hp = Vedekezo->hp - Tenylegessebzes;
			printf("Ennyi eletereje marad az ellensegnek:  %d\n", Vedekezo->hp);
			Tamado->hp = Tamado->hp - Tenylegessebzes1;
			printf("Ennyi eleterod maradt:  %d\n", Tamado->hp);
			printf("Kardal valo tamadasod ereje:  %d\n", Tenylegessebzes);
			printf("Valasz ki a lehetosegeid:\n1.Tamadas kardal\n2.Tamadas magiaval(50 mana)\n3.Menekules(hp vesztesegel jarhat!)\n");
			break;
		case 2:
			if (Tamado->mp == 0) {
				printf("Nem tudsz magiaval tamadni!\n");
				printf("Valasz ki a lehetosegeid:\n1.Tamadas kardal\n2.Tamadas magiaval(50 mana)\n3.Menekules(hp vesztesegel jarhat!)\n");
			}
			else {
				Vedekezo->hp = Vedekezo->hp - Tenylegessebzes2;
				printf("Ennyi eletereje marad az ellensegnek:  %d\n", Vedekezo->hp);
				Tamado->hp = Tamado->hp - Tenylegessebzes1;
				mana = Tamado->mp - 50;
				Tamado->mp = mana;
				printf("Ennyi eleterod maradt:  %d\n", Tamado->hp);
				printf("Ennyi magiad maradt:  %d\n", Tamado->mp);
				printf("Magiadal valo tamadasod ereje:  %d\n", Tenylegessebzes2);
				printf("Valasz ki a lehetosegeid:\n1.Tamadas kardal\n2.Tamadas magiaval(50 mana)\n3.Menekules(hp vesztesegel jarhat!)\n");

			}
			break;
		case 3:
			printf("Menekules kozben elszenvedet sebzes: \n");
			srand(time(0));
			int szam1 = (rand() % (15 - 0 + 1)) + 0;
			printf("%d\n", szam1);
			printf("Ennyi eleterod maradt:  %d\n", Tamado->hp);
			return 0;
		default:
			printf("Nincs ilyen valasztas!\n");
			printf("Valasz ujat!\n");
			break;
		}

		if (Vedekezo->hp <= 0) {
			printf("\nMegnyerted a csatat!\n");
			return 0;
		}
		if (Tamado->hp <= 0) {
			printf("\nElvesztedet a csatat!\n");
			exit(1);
			
		}
	}
}

void Mozgas(char** level, Hos* jatekos)
{
	int X, Y;
	int jX = 1, jY = 1;
	level[jX][jY] = 'H';
	
		while (level[jX][jY] != 'C') {

			KiirPalya(level);
			printf("Fell:w\nLe: s\nJobbra: d\nBallra: a\n");
			char opt = getch();
			X = jX;
			Y = jY;
			if (opt == 'd') {
				jY++;
			}
			if (opt == 's') {
				jX++;
			}
			if (opt == 'a') {
				jY--;
			}
			if (opt == 'w') {
				jX--;
			}

			if (level[jX][jY] == '0') {
				level[jX][jY] = 'H';
				level[X][Y] = '0';
			}

			if (level[jX][jY] == '3'|| level[jX][jY] == '1') {
				printf("\nSajnos meghaltal a mergezo tuskekben probald meg ujra!\n");
				exit(1);
			}
			if (level[jX][jY] == 'G') {
				Hos * gb;
	            gb = Create();
	            BeolvasEllensegAdataitG(gb);
	            KiirEllensegStatisticaG(gb);
				KiirHosStatistica(jatekos);
	            Harc(jatekos, gb);
				if (level[jX][jY] == 'G') {
					level[jX][jY] = 'H';
					level[X][Y] = '0';
				}
				jatekos->xp = jatekos->xp + 50;
				printf("XP+25\n Tapasztalati pontok:%d\n", jatekos->xp);
				if (jatekos->xp == 100 || jatekos->xp == 250 || jatekos->xp == 500 || jatekos->xp == 1000) {
					jatekos->level = jatekos->level + 1;
					printf("Szintett leptel!\n Jellenlegi szit: %d\n", jatekos->level);
					int valasz2;
					printf("1.Tamado ertek noveles\n2.Vedekezo ertek noveles\n");
					scanf("%d", &valasz2);
					switch (valasz2) {

					case 1:
						jatekos->atk = jatekos->atk + 5;
						printf("Tamado ertek megnovelve: +5-el!\n");
						break;
					case 2:
						jatekos->def = jatekos->def + 5;
						printf("Vedekezo ertek megnovelve: +5-el!\n Jellenlegi vedekezo ertek: %d\n", jatekos->def);
						break;

					default:
						printf("Ilyen lehetoseg nincs!\n Valasz ujat!\n");
						break;
					}
				}


			}
			if (level[jX][jY] == 'S') {
				Hos* s;
				s = Create();
			    BeolvasEllensegAdataitS(s);
			    KiirEllensegStatisticaS(s);
				KiirHosStatistica(jatekos);
				Harc(jatekos, s);
				if (level[jX][jY] == 'S') {
					level[jX][jY] = 'H';
					level[X][Y] = '0';
				}
				jatekos->xp = jatekos->xp + 100;
				printf("XP+100\n Tapasztalati pontok:%d\n", jatekos->xp);
				if (jatekos->xp == 100  || jatekos->xp == 250 || jatekos->xp == 500 || jatekos->xp==1000) {
					jatekos->level = jatekos->level + 1;
					printf("Szintett leptel!\n Jellenlegi szit: %d\n", jatekos->level);
					int valasz1;
					printf("1.Tamado ertek noveles\n2.Vedekezo ertek noveles\n");
					scanf("%d", &valasz1);
					switch (valasz1) {

					case 1:
						jatekos->atk = jatekos->atk + 5;
						printf("Tamado ertek megnovelve: +5-el!\n");
						break;
					case 2:
						jatekos->def = jatekos->def + 5;
						printf("Vedekezo ertek megnovelve: +5-el!\n Jellenlegi vedekezo ertek: %d\n",jatekos->def);
						break;
				
					default:
						printf("Ilyen lehetoseg nincs!\n Valasz ujat!\n");
						break;
					}
				}
			}
			if (level[jX][jY] == 'L') {
				srand(time(0));
				int szam = (rand() % (6 - 1 + 1)) + 1;
				switch (szam) {

				case 1:
					printf("Megtalaltad a Holdsarlo penget(Tamado ertek megnovelve +10)\n");
					jatekos->atk = jatekos->atk + 10;
					break;
				case 2:
					printf("Megtalaltad a Annubis szivet(Eletero megnovelve +50)\n");
					jatekos->hp = jatekos->hp + 50;
					break;
				case 3:
					printf("Megtalaltad a Elveszet Gyurut(Magikus ero megnovelve +20)\n");
					jatekos->mpatk = jatekos->mpatk + 20;
					break;
				case 4:
					printf("Megtalaltad a Vanadium Pajzsot(Vedekezo ero megnovelve +20)\n");
					jatekos->def = jatekos->def + 20;
					break;
				case 5:
					printf("Megtalaltad a Tiszta Lelkek Forrasat(Mana szint +50)\n");
					jatekos->mp = jatekos->mp + 50;
					break;
				case 6:
					printf("Nem talaltal semmi hasznosat!\n");
					break;
				default:
					printf("Nem talaltal semmi hasznosat!\n");
					break;
				}
			}
			
		}
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
				printf("*"); // mergezo tuskek
			}
			if (level[i][j] == 'C') {
				printf("C");  //cel
			}
			if (level[i][j] == 'H') {
				printf("H");  //karakter
			}
			if (level[i][j] == 'L') {
				printf(" "); //rejtet lada 
			}
			if (level[i][j] == 'S') {
				printf("S"); //ellenseg sarkany
			}
			if (level[i][j] == 'G') {
				printf("G"); //ellenseg Goblin
			}
		}
		printf("\n");
	}


}

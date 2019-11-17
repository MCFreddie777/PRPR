/*
Praca s dynamickym polom struktur. Vytvorte pole zaznamov o tovare v potravinach. Jednotlive
zaznamy maju obsahovat nazov tovaru, vyrobcu, pocet kusov a jednotkovu cenu.
POZOR - Zoznam udrziavajte stale usporiadany podla nazvov tovarov. Umoznite pouzivatelovi
pridat novy tovar.
Pomocka: Pri pridavani zaznamu do pola, je potrebne najst miesto, kam sa ma novy
zaznam pridavat. Vsetky zaznamy, od tejto pozicie dalej, posunut na poziciu o jedno
vacsiu a na volne miesto zapisat novy zaznam.
Cielom programu nie je vytvorit pouzitelny program, ale naucit sa pracovat v poli struktur. 
Na prakticke pouzitie je potrebne program upravit (vstupy, vystupy).
Na vstupe pouzite napr. nazvy ovocia (jablko, hruska, ananas, hrozno, mandarinka, kokos)
a overte ci bude vysledny zoznam usporiadany podla nazvu tovaru.   
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// vytvorenie struktury na uchovavanie udajov (tj zaznamov v zozname tovaru)
// struktura je definovana ako typ (typ ZAZNAM)
typedef struct
{
	char nazov_tovaru[40];
	char nazov_vyrobcu[40];
	unsigned int pocet;
	double cena;
} ZAZNAM;

/*
 * funkcia vypise na obrazovku obsah pola struktur, konkretne informacie o tovare ulozenom v poli
 * 
 * parametre:
 *		zaznamy - pointer na prvy prvok v dynamicky vytvorenom poli struktur
 *		pocet_zaznamov - pocet zaznamov :) je predavany preto, lebo jazyk C si nevie zistit tento pocet automaticky
 */
void vypis(ZAZNAM *zaznamy,unsigned int pocet_zaznamov)
{
	// pomocny ukazovatel na polozku v zozname - bude pouzity na prechadzanie polom a na referencovanie jednotlivych poloziek v nom
	ZAZNAM *zaznam;

	// zaciatok vypisu
	printf("vypis:\n");

	/*
		cyklus prechadzania jednotlivymi polozkami zoznamu:

		Na zaciatku je do premennej zaznam priradeny ukazovatel na zaciatok zoznamu,
		v prvom kole cyklu su teda vypisane hodnoty prvej ulozenej struktury.

		Zapis v tvare: zaznam = zaznam + 1 (zaznam++) znamena, ze hodnota ukazovatela na strukturu typu ZAZNAM
		sa zvysi o hodnotu sizeof(ZAZNAM), teda ak su v pamati ulozene tieto zaznamy jeden za druhym, co v nasom 
		pripade su, premenna (pointer) 'zaznam' bude ukazovat na prvy bajt nasledovneho zaznamu, bude teda schopna 
		korektne pracovat so strukturou, na ktoru ukazuje - teda v druhom kole cyklu bude ukazovat na druhy prvok zoznamu, atd.

		zapis v tvare: zaznam++ sa pouziva BEZ hviezdicky!, nakolko sa nepracuje s hodnotou ulozenou na adrese
		ale so samotnou adresou, pripocitava sa k nej pocet bajtov sizeof(ZAZNAM), teda vysledkom operacie je adresa ulozenia
		dalej struktury v poli

		na zaklade vyssie spomenuteho principu je formulovana podmienka cyklu:
			zaznam < zaznamy + pocet_zaznamov
		cyklus teda konci, ak adresa, na ktoru ukazuje premenna zaznam bude vyssia ako pocet bajtov alokovanej pamate - 
			- cyklus nemoze pokracovat, pretoze na adrese zaznamy + pocet_zaznamov sa nenachadza ziadna struktura
			(a program tuto pamat ani nema pristupnu)
	*/
	for (zaznam = zaznamy; zaznam < zaznamy + pocet_zaznamov; zaznam++)
	{
		// vypis obsahu aktualnej struktury, kedze je referencovana pomocou pointera, pristupuje sa na jej prvky pomocou ->
		// ( pomocou . by sa pristupovalo ak by sme pracovali s premennou typu ZAZNAM )
		printf("%s   ; %s    %u   ; %.2lf\n", zaznam->nazov_tovaru, zaznam->nazov_vyrobcu, zaznam->pocet, zaznam->cena);
	}
	putchar('\n'); // novy riadok po vypisani obsahu aktualnej polozky
}

// main musi byt typu int, pretoze zdrojovy kod budeme kompilovat pod Unixom
int main()
{
	int pocet_zaznamov = 0; // premenna na uchovavanie poctu zaznamov :)
	ZAZNAM *zaznamy = NULL; // ukazovatel na zaciatok pola zaznamov, musi byt inicializovany, inak ukazuje na nahodne miesto

	// pomocne premenne na nacitanie konzolovych vstupov
	char nazov_tovaru[40]; 
	char nazov_vyrobcu[40];
	unsigned int pocet;
	double cena;
	
	int i; // pomocna premenna cyklov
	int pozicia; // pomocna premenna na uchovanie pozicie, na ktoru bude vlozena nova polozka
	
	// zaciatocny vypis programu
	printf("-zadajte \"K\" ako nazov tovaru pre ukoncenie programu\n");
	printf("-po pridani kazdeho zaznamu sa zobrazi vypis vsetkych poloziek\n\n");

	// hlavny cyklus programu
	while (1)
	{
		// nacitavanie vstupnych udajov v kazdom kroku cyklu
		printf("nazov tovaru: ");
		scanf("%s",nazov_tovaru);

		// podmienka ukoncenia programu - strcmp() vracia pri rovnosti 0, 
		// pri negacii vznikne pravdivy vyrok (cislo rozne od 0)
		if (!strcmp(nazov_tovaru,"K")) return 0;

		printf("nazov vyrobcu: ");
		scanf("%s",nazov_vyrobcu);

		printf("pocet: ");
		scanf("%u",&pocet);

		printf("jednotkova cena: ");
		scanf("%lf",&cena);
		
		// ak este nebolo vytvorene pole zaznamov (teda na zaciatku behu programu), 
		// je vytvorene pole o velkosti 1 prvku, do ktoreho bude pridany novy prvok
		if (zaznamy == NULL)
		{
			// dynamicky sa alokuje pamat o velkosti tolko bajtov, kolko je potrebnych 
			// na uchovanie jednej struktury typu ZAZNAM
			zaznamy = (ZAZNAM *) malloc(sizeof(ZAZNAM));
			// pozicia sa nastavi na 0, lebo prvy prvok pojde na zaciatok pola
			pozicia = 0;
		}
		else // ak sa pridava prvok do uz hotoveho pola, musi sa zistit, na ktoru poziciu
		{
			// prechod polom ulozenych zaznamov:
			// je potrebne najst prvok v poli, ktory sa na zaklade abecedneho poradia nachadza 
			// za prvkom, ktory chceme vlozit do pola zaznamov
			for (i = 0; i < pocet_zaznamov; i++)
			{
				/*
					Funkcia strcmp() vracia cislo vacsie ako nula, 
					ak retazec prveho parametra je lexikografixky za retazcom druheho parametra.

					Ak sa takyto prvok najde, nastavi sa pozicia ulozenia aktualneho prvku 
					na poziciu najdeneho prvku v zozname.

					Na tento prechod polom nepotrebujeme ziadny pomocny pointer na typ ZAZNAM,
					ide o dalsi sposob prechadzania polom struktur v cykle, staci nan premenna typu int,
					pretoze pomocou pripocitania hodnoty 'i' 
					vieme ziskat adresu ulozenia i-tej polozky zoznamu.

					Pomocou zapisu (zaznamy+i)->atribut, tak dokazeme pristupovat k jednotlivym atributom struktury.
				*/
				if (strcmp( (zaznamy+i)->nazov_tovaru, nazov_tovaru ) > 0)
				{
					pozicia=i;
					break;
				}
			}
			// ak i = pocet_zaznamov, polozka bude pridana na koniec zoznamu, teda na hodnotu pocet_zaznamov, 
			// kedze sa cisluje od nuly
			if (i == pocet_zaznamov) pozicia = pocet_zaznamov;
			
			// dynamicke realokovanie pamate - alokuje sa pamat pre jednu polozku typu ZAZNAM navyse (pocet_zaznamov+1), 
			// aby do tejto pamate mohla byt ulozena polozka nacitana zo vstupu (v praxi je lepsie alokovat vacsi priestor
			//naraz a postupne kontrolovat ci je pole naplnene) 
			zaznamy = (ZAZNAM *) realloc(zaznamy, (pocet_zaznamov + 1) * sizeof(ZAZNAM));

			/*
				cyklus na prechadzanie polom struktur:

				Zacina sa na poslednej polozke, ktora je posunuta o jedno miesto dalej (smerom na koniec pola struktur),
				posledna polozka sa tak presunie do novoalokovanej pamate, predposledna sa posunie na jej miesto, atd.
				(samozrejme iba v pripade, ze nova polozka nebude vkladana na koniec pola struktur, 
				v opacnom pripade podmienka cyklu nebude splnena)

				na prechod polom je zasa pouzita iba premenna typu int, k jednotlivym polozkam sa pristupuje pomocou
				vypocitania posunutia od bazovej adresy pola, teda od adresy ulozenej v ukazovateli 'zaznamy'
			*/
			for ( i = pocet_zaznamov - 1; i >= pozicia; i-- )
			{	
				/*
					operator '*' znamena, ze je pristupovane k hodnote ulozenej na adrese (zaznamy + i + 1),
					teda na adrese ktora vznikne pripocitanim posunutia k adrese zaciatku pola struktur

					hodnota na tejto adrese je typu ZAZNAM, teda cela struktura

					prikaz priradenia predstavuje premiestnenie polozky v poli struktur o jedno miesto dalej v smere ku koncu pola,
					teda hodnota i-tej polozky v poli bude ulozena na miesto (i+1)-vej polozky v poli, teda i-ta struktura bude 
					posunuta o jedno miesto doprava (v kazdom kroku cyklu)

					dojde tak k posunutiu vsetkych poloziek ktore sa nachadzaju v poli na pozicii 'pozicia' a za nou
				*/
				*(zaznamy + i + 1 ) = *(zaznamy + i);
			}
		}
		
		// na poziciu 'pozicia', predstavujucu index polozky v poli, sa nasledne v strukture ulozia udaje nacitane zo vstupu.
		// ukazovatel (zaznamy + pozicia) ukazuje na korektnu adresu, ktora je pridelena programu
		strcpy( (zaznamy + pozicia)->nazov_tovaru, nazov_tovaru );
		strcpy( (zaznamy + pozicia)->nazov_vyrobcu, nazov_vyrobcu );
		( zaznamy + pozicia )->pocet = pocet;
		( zaznamy + pozicia )->cena = cena;

		// po pridani polozky sa zmeni premenna uchovavajuca pocet poloziek
		pocet_zaznamov++;
		printf("pridany zaznam na poziciu %u ; aktualny pocet zaznamov: %u\n", pozicia, pocet_zaznamov);

		// po pridani polozky sa vypise cely zoznam poloziek, aby bolo vidno, ze polozka bola pridana na korektnu poziciu 
		// podla lexikografickeho zoradenia
		vypis(zaznamy, pocet_zaznamov);
	}

	return 0;
}

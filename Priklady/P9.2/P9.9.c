#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct zaznam
{
  char nazov_tovaru[40];
  char nazov_vyrobcu[40];
  unsigned int pocet;
  double cena;
  struct zaznam *dalsi;
} ZAZNAM;

void vypis(ZAZNAM *zaznam)
{
  printf("vypis:\n");

  while (zaznam!=NULL)
  {
    printf("  %s ; %s ; %u ; %.2lf\n",zaznam->nazov_tovaru, zaznam->nazov_vyrobcu,zaznam->pocet,zaznam->cena);
	zaznam=zaznam->dalsi;
  }
  putchar('\n');
}

int main()
{
  ZAZNAM *prvy=NULL;
  ZAZNAM *aktualny;
  ZAZNAM *novy;
  ZAZNAM *pred;

  char c;
  char vymazavane[20];

  printf("prikazy:\n");
  printf("  P: pridat zaznam\n");
  printf("  Z: zmazat zaznam\n");
  printf("  K: koniec programu\n");
  printf("po kazdej zmene sa zobrazi vypis vsetkych poloziek\n\n");

  while (1)
  {
    while ((c=getchar())=='\n')
		;
	getchar();

	if (c=='P')
	{
	// pridavanie
	  novy=(ZAZNAM *)malloc(sizeof(ZAZNAM));

	  printf("nazov tovaru: ");
	  scanf("%s",(novy->nazov_tovaru));

	  printf("nazov vyrobcu: ");
	  scanf("%s",(novy->nazov_vyrobcu));
			
	  printf("pocet: ");
	  scanf("%u",&(novy->pocet));

	  printf("jednotkova cena: ");
	  scanf("%lf",&(novy->cena));

    if (prvy==NULL)   // zoznam je prazdny, pridanie na prve miesto
	{
	  prvy=novy;
	  novy->dalsi=NULL;
	}
	else	// v zozname uz nieco je
	{
	  if (strcmp(novy->nazov_tovaru,prvy->nazov_tovaru)<0)
	  {   // pridanie na prve miesto
	    novy->dalsi=prvy;
	    prvy=novy;
	  }
	  else 
	  {   // pridanie na ine ako prve miesto
	    aktualny=prvy;
		while ((aktualny->dalsi!=NULL)&&(strcmp(novy->nazov_tovaru,aktualny->dalsi->nazov_tovaru)>0))
		  {
			aktualny=aktualny->dalsi;
		  }

		novy->dalsi=aktualny->dalsi;
		aktualny->dalsi=novy;
	  }
		
	}
	  printf("zaznam bol pridany\n");
	vypis(prvy);
	}

if (c=='Z')   {   // vymazavane
  if (prvy==NULL)
	printf("v zozname nic nie je\n");
  else   {
	printf("nazov tovaru: ");
	scanf("%s",vymazavane);
	  if (!strcmp(prvy->nazov_tovaru,vymazavane))
	    {   //vymazanie prveho
		  aktualny=prvy->dalsi;
		  free(prvy);
		  prvy=aktualny;
		  printf("zaznam bol vymazany\n");
		}

      else   { //vymazanie ineho ako prveho
		aktualny=prvy->dalsi;
		pred=prvy;
		while (aktualny!=NULL)
		    {if (!strcmp(aktualny->nazov_tovaru,vymazavane))
			pred->dalsi=aktualny->dalsi;
			free(aktualny);
			printf("zaznam bol vymazany\n");
			break;
			}
			aktualny=aktualny->dalsi;
			pred=pred->dalsi;
		  }
		}
		vypis(prvy); 
		  }
   }
	if (c=='K') 
  return 0; // koniec programu
 }



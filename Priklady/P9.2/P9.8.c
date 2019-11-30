#include <stdio.h>

int main(void) {
	FILE *fr;
	char c;
	// otvorenie suboru pre citanie
	if ((fr = fopen("text.txt", "r")) == NULL) {
		printf("Subor sa nepodarilo otvorit\n");
		return;
	}
	
	int vyber_riadok; // ktory riadok chcem vypisat
	scanf("%d",&vyber_riadok);
	int cislo_riadku = 1; // na ktorom riadku sa nachadzam
	
	while ((c = getc(fr)) != EOF){
		if(c == '\n') {
			cislo_riadku++; // pocitam cisla riadkov 
		}
		if(vyber_riadok == cislo_riadku){ // ked sa dostanem na riadok ktory hladam ...
			printf("%c",c); // ... tak vypisujem
		}
	}
if(vyber_riadok > cislo_riadku){
		printf("Subor ma iba %d riadkov preto nemozem vypisat %d riadok",cislo_riadku, vyber_riadok);
	}

	if (fclose(fr) == EOF) {
		printf("Subor sa nepodarilo zatvorit\n");
		return;
	}
return 0;
}


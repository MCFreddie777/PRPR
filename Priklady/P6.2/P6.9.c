#include <stdio.h>

int scitaj(int a, int b)	
{
	return a+b;
}
void vypis()	
{
	printf("FIIT\n");
}
void vypis_retazec(char*retazec)
{
	printf("Velmi rad programujem v %s", retazec);
}

int main()
{
	int c;
	int (*p)(int, int);
	void(*p_t)();
	void (*prt)(char*);
	prt = vypis_retazec;
	prt("Cecku\n"); 
	p_t = vypis;
	p_t();
	p = scitaj; //meno funkcie pouzite ako smernik
	c = p(2,8);	//dereferencia a vykonanie funkcie
	printf ("%d", c);
	return 0;
}




#include <stdio.h>
#define vytvorit_cislo(i) (1<<(i)) // vytvori cislo s 1 na mieste i, ostatne su 0
#define rad(x,i) (((x)>>(i))&1) // vrati cislicu i-teho radu cisla x

unsigned invert(unsigned x,int i, int n)
{	unsigned j;
	for (j=i;j<i+n;j++)
	{	if (rad(x,j)==0)
		   x=x|(vytvorit_cislo(j));
		else
		   x=x&(~(vytvorit_cislo(j)));
	}	
  return x;
}


//vypise cislo v dvojkovej sustave
void vypis(unsigned x)
{
	if (x>0) 
	{
		vypis(x>>1);
		printf("%d",x&1);
	}
}

int main()
{	unsigned x;
	int i,n;
	scanf("%d %d %d",&x,&i,&n);
	printf("Povodne cislo v dvojkovej sustave:");
	vypis(x);putchar('\n');
	x=invert(x,i,n);
	printf("Cislo po invertovani v dvojkovej sustave:");
	vypis(x);putchar('\n');
	printf("Cislo po invertovani v desiatkovej sustave: 	%u\n",x);
	return 0;
}


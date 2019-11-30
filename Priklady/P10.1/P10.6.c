#include <stdio.h>

unsigned invert(unsigned x,int i, int n)
{	unsigned j;
	for (j=i;j<i+n;j++)
	{		if (((x>>j)&1)==0)
			x=x|(1<<j);
		else
			x=x&(~(1<<j));
	}	return x;}

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
{	unsigned int x;
	int i,n;
	scanf("%u %d %d",&x,&i,&n);
	printf("Povodne cislo v dvojkovej sustave:");
	vypis(x);
	putchar('\n');
	x=invert(x,i,n);
	printf("Cislo po invertovani v dvojkovej sustave:");
	vypis(x);
	putchar('\n');
	printf("Cislo po invertovani v desiatkovej sustave: 	%u\n",x);
return 0;
}


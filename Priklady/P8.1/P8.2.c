//P8.2 Vymena troch cisel pomocou funkcie
#include <stdio.h>
void swapNumbers(int *x,int *y,int *z)
{
    int tmp;
    tmp=*y;
    *y=*x;
    *x=*z;
    *z=tmp;
}

int main()
{
    int n1,n2,n3;

    printf(" Vloz tri cisla: ");
    scanf("%d %d %d",&n1, &n2, &n3);
		
    printf("\n Hodnoty pred vymenou :\n");
    printf(" prvok 1 = %d\n prvok 2 = %d\n prvok 3 = %d\n",n1,n2,n3);
    swapNumbers(&n1,&n2,&n3);
    printf("\n Hodnoty po vymene :\n");
    printf(" prvok 1 = %d\n prvok 2 = %d\n prvok 3 = %d\n\n",n1,n2,n3);
    return 0;
}


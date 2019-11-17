#include <stdio.h>
#define M 100
#define N 100
int a[M][N],b[M][N];

int maximum(int pole [][100], int riadky)
{
    int pom = pole[0][0];
    int i, j;

    for (i = 0; i < riadky; i++) {
        for (j = 0; j < 4; j++) 
            if (pole[i][j] > pom) 
                pom = pole[i][j];
    }
    return (pom);
 }


int main(void){
  
  int m,n,i,j,vysledok;
  scanf("%d %d",&m,&n);
  for(i=0;i<m;i++)
   for(j=0;j<n;j++)
     a[i][j]=rand()%200-100;
     
   for(i=0;i<m;i++){
   for(j=0;j<n;j++)
     printf("%d ",a[i][j]);
     printf("\n");
  }
  vysledok = maximum(a,m);
  printf("Maximum = %d ", vysledok);
  return 0;
}

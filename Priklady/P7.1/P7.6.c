#include <stdio.h>
#include <stdlib.h>

#define M 100
#define N 100
int **a,**b,**c;

int **citaj(int m,int n)
{
 int i,j,**x=(int **)malloc(m*sizeof(int*));
 for(i=0;i<m;i++) {
  x[i]=(int *)malloc(n*sizeof(int));
  for(j=0;j<n;j++) 
    scanf("%d",&x[i][j]);
 }
 return x;
}

int **sucet(int **x,int **y,int m,int n)
{
 int i,j,**z=(int **)malloc(m*sizeof(int));
 for(i=0;i<m;i++) {
  z[i]=(int *)malloc(n*sizeof(int));
  for(j=0;j<n;j++)
    z[i][j]=x[i][j]+y[i][j];
 }
 return z;
}
void tlac(int **x,int m,int n)
{
  int i, j;
  for(i=0;i<m;i++){
    for(j=0;j<n;j++)
      printf("%d ",x[i][j]);
      printf("\n");
  }
}

void main(void)
{  int m,n;
   scanf("%d %d",&m,&n);
   a=citaj(m,n);
   b=citaj(m,n);
   c=sucet(a,b,m,n);
   tlac(c,m,n);
}  


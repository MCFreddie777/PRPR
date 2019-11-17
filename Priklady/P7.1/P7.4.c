#include <stdio.h>
#include <stdlib.h>
#define M 100
#define N 100
int *a[M],*b[M],*c[M];

void citaj(int* x[],int m,int n)
{
  int i,j;
  for(i=0;i<m;i++){ 
    x[i] = (int*)malloc(n * sizeof(int)); 
    for(j=0;j<n;j++) 
	scanf("%d",&x[i][j]);
  }
}

void sucet(int* x[],int *y[],int *z[],int m,int n)
{
  int i,j;
  for(i=0;i<m;i++) {
    z[i]=(int *)malloc(n*sizeof(int));
    for(j=0;j<m;j++) 
	z[i][j]=x[i][j]+y[i][j];
  }
}

void tlac(int* x[],int m,int n)
{
 int i, j;
 for(i=0;i<m;i++){
   for(j=0;j<n;j++)
     printf("%d ",x[i][j]);
     printf("\n");
  }
}

void main(void)
{ 
  int m,n;
  scanf("%d %d",&m,&n);
  citaj(a,m,n);
  citaj(b,m,n);
  sucet(a,b,c,m,n); 
  tlac(c,m,n);
}   


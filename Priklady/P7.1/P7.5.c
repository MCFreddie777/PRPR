#include <stdio.h>
#include <stdlib.h>
#define M 100
#define N 100
int (*a)[N],(*b)[N],(*c)[N];

int (*citaj(int m,int n))[]
{
 int i,j;
 int(*x)[N]=(int (*)[N])malloc(m*N*sizeof(int));
 for(i=0;i<m;i++) 
  for(j =0;j<n;j++) 
    scanf("%d",&x[i][j]);
 return x;
}

int (*sucet(int(*x)[N],int(*y)[N],int m,int n))[]
{
 int i,j;
 int(*z)[N]=(int(*)[N])malloc(m*N*sizeof(int));
 for(i=0;i<m;i++) 
  for(j=0;j<n;j++)z[i][j]=x[i][j]+y[i][j];
 return z;
}
void tlac(int (*x)[N],int m,int n)
{
  int i, j;
  for(i=0;i<m;i++){
    for(j=0;j<n;j++)
      printf("%d ",x[i][j]);
      printf("\n");
  }
}

int main(void)
{ 
  int m,n;
  scanf("%d %d",&m,&n);
  a=citaj(m,n);
  b=citaj(m,n);
  c=sucet(a,b,m,n);
  tlac(c,m,n);
return 0;
}   


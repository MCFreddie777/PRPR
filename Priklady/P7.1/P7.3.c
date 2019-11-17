//Nahodne generovan� cisla ulozime do pola a, 
//potom ich zapiseme do suboru, zo suboru nacitame a ulozime do pola b
//P7.3
#include <stdio.h>
#include <stdlib.h>

#define M 100
#define N 100
int a[M][N],b[M][N];

int main(void){
  FILE *fw, *fr;
  int m,n,i,j;
  scanf("%d %d",&m,&n);
  for(i=0;i<m;i++)
   for(j=0;j<n;j++)
     a[i][j]=rand()%200-100;
     
  fw=fopen("pole.txt","w");
  fprintf(fw,"%d %d\n",m,n);
  for(i=0;i<m;i++)
   for(j=0;j<n;j++)
     fprintf(fw,"%d ",a[i][j]);
  fclose(fw);

  fr=fopen("pole.txt","r");
  fscanf(fr,"%d %d",&m,&n);
  for(i=0;i<m;i++)
   for(j=0;j<n;j++)
     fscanf(fr,"%d ",&b[i][j]);
  fclose(fr);
  for(i=0;i<m;i++){
   for(j=0;j<n;j++)
     printf("%d ",b[i][j]);
     printf("\n");
  }
  return 0;
}

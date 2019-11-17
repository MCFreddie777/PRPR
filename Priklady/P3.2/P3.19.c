#include<stdio.h>

void delenie(int delenec, int delitel, int *podiel, int *zvysok) { 
  *podiel = delenec / delitel; 
  *zvysok = delenec % delitel; 
}

int main() { 
  int c1, c2, po, zv;
  printf("Zadaj 2 cele cisla: ");
  scanf("%d %d", &c1,&c2); 
  delenie(c1, c2, &po, &zv); 
  printf("podiel = %d\nzvysok = %d\n", po, zv);
  return 0; 
 } 


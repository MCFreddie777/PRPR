#include <stdio.h>

void vypis(int a[][3], int n, int m)
{
  int i, j;
  for (i = 0; i < n; i++)
  for (j = 0; j < m; j++)
    printf("%d ", a[i][j]);
}

int main(void){
  int p[][3] = { {1,2,3}, {4,5,6}, {7,8,9}, {10,11,12} };	
  vypis(p, 4, 3); // 1 2 3 4 5 6 7 8 9 10 11 12
  return 0;
}

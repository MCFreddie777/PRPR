#include <stdio.h>
int main() {
   int i, j, n, r;

   scanf("%d", &n);
   for(i=1; i<=n; i++) {
      for(j=1; j<=n; j++) 
         if(i < j)
            putchar('*');
         else 
            printf("%d", i%10);
      putchar('\n');
   }
return 0;
}


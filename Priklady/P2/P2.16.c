#include <stdio.h>

int main() {
   int i, j, n;

   scanf("%d", &n);
   if(n < 1 || n > 15) return 0;
   for(i=1; i<=n; i++) {
	for(j=1; j<=2*n-1; j++) {
         if(j <= n-i || j >= n+i)
            putchar('*');
         else 
            printf("%d", i%10);
      }
      putchar('\n');
   }
return 0;
}


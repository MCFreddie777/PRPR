#include <stdio.h>
#include <stdlib.h>
int main(void)
{   
   int  *p;  // p pointer na int    
   int  n, i, max;

   printf("zadaj pocet prvkov n = ");
   scanf("%d", &n);      
   p = (int*)malloc(n*sizeof(int)); //dynamicka alokacia
   for (i = 0; i < n ; i++) {
     printf("%d. prvok:  ", i + 1);
	scanf("%d", p + i);   // p + i je adresa, staticky &p[i]	      	
	}
   max = *p;  // ekvivalentne max = *(p+0), staticky p[0] 
   for (i = 0; i < n ; i++) {
      if (*(p + i) > max)  
          max = *(p + i);   
   }		   
   printf("Maximum je %d \n",  max);
return 0;
}


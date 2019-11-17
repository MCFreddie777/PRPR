#include <stdio.h>
int main( )
{
    int i, j, k = 1, rozmer;
	printf("zadaj rozmer Floydovho trojuholnika\n");
 	scanf("%d", &rozmer);

        for(i = 1; k <= rozmer; ++i)
        {
          for(j = 1; j <= i; ++j)
      	printf("%2d  ", k++);
      	printf("\n");    
  	 }
return 0;
}


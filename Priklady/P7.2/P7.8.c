//P7.8
#include <stdio.h>
int main(void){
 char retazec[] = {'j', 'a', 'z', 'y', 'k', 'C','\0'};
 int i;
 char *p_c;
 p_c = &retazec[0]; 
   for (i = 0; i < 2; i++)
   {
    printf("p_c + %d = %c\n",i, *(p_c + i)); 
    printf("p_c + %d = %c\n",i, *p_c++);
    printf("p_c + %d = %c\n",i, *(++p_c));
    }
return 0;
} 


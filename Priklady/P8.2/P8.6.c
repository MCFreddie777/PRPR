#include <stdio.h>
#include <stdlib.h>

typedef struct prvok {
    int hodnota;
    struct prvok *dalsi;
} PRVOK;

int main()
{
    int i, n;
    PRVOK *p_prv, *p_akt;

    printf("Zadaj pocet prvkov zoznamu: ");
    scanf("%d", &n);
    
    if((p_prv = (PRVOK *) malloc(sizeof(PRVOK))) == NULL){
        printf("Malo pamate.\n");
        return;
    }
    p_prv->hodnota = 1;
    printf("%d ",p_prv->hodnota );
    p_akt = p_prv; 
    for(i = 2; i <= n; i++) {
       if((p_akt->dalsi = (PRVOK *) malloc(sizeof(PRVOK))) == NULL) {
          printf("Malo pamate.\n");
          break;
       }
    p_akt = p_akt->dalsi;
    p_akt->hodnota = i;
    printf("%d ",p_akt->hodnota );
    }
    p_akt->dalsi = NULL;
    
    return 0;
}
	

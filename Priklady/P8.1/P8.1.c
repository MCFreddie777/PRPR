//P8.1 Cezarova sifra
#include<stdio.h>
#include<string.h>

int main()
{
    char p[20];
    int kluc,i,kod;
    
    printf("Vloz retazec=");
    gets(p);
    printf("\n Vloz kluc=");
    scanf("%d",&kluc);

    for(i=0;i<strlen(p);i++)
    {
           p[i]=tolower(p[i]); //velke pismena na male
           if (p[i]<'a'|| p[i]>'z')
             printf("%c",p[i]);
           else {
             kod=((p[i]-'a')+kluc)%26;
             printf("%c",kod +'a');	
		   } 
			 
    }
}

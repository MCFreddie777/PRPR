#include <stdio.h>
int main()
{
  char a[100], b[100];
  int ia = 1, ib = 1;
  FILE *fa = fopen("prvy.txt", "rt");
  FILE *fb = fopen("druhy.txt", "rt");
  FILE *fc = fopen("treti.txt", "wt");

  while (1)
  {
    if (ia > 0)
      ia = fscanf(fa, "%s", a);
    if (ib > 0)
      ib = fscanf(fb, "%s", b);
    if (ia <= 0 && ib <= 0)
      break;
    
    if (ia > 0)
      fprintf(fc, "+%s ", a);
    if (ib > 0)
      fprintf(fc, "-%s ", b);
  }    
  fclose(fa);
  fclose(fb);
  fclose(fc);    
  return 0;
}


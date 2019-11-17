#include <stdio.h>
int main()
{
	int i = -1, j = 0, k = 1;
	if (i++ && !j || k++)
		j++;
	if (i++ || j && !i || k++)
		j++;
	printf("%d %d %d\n", i, j, k);
return 0;
}


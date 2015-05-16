#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	char a[50];
	ungetc('a', stdin);
	ungetc('b', stdin);
	ungetc('c', stdin);

	scanf("%s", a);

	printf("read char: %s\n", a);
	return EXIT_SUCCESS;
}

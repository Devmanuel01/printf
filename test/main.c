#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
	int len;
	int len2;
	int len3;
	char b = 'A';

	len = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	len3 = _printf("%c\n", b);
	printf("Length: [%d, %i]\n", len, len2);
	printf("%d\n", len3);
	return (0);
}

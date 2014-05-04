#include <stdio.h>

main () {
	unsigned int i;
	int          j[10];
	int         *b;
	for (i = 0; i < 10; i++) {
		printf("Hello world!\n");
		j[i] = i;
	        b    = j;
		j[*b % 10] = i + 10;
	}
}

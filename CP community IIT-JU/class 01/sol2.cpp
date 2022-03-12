/*
*/
#include<stdio.h>
int  main ()
{
	int x;
	scanf("%d", &x);

	if (x % 3 == 0) {
		printf("%d is a multiple of 3.\n", x);
	}
	if (x % 5 == 0) {
		printf("%d is a multiple of 5.", x);
	}

	// logical operator
	// &&
	// ||
	// !

	if (x % 3 == 0 && x % 5 == 0) {
		printf("%d is a multiple of 3 and 5.\n", x);
	}
	else if (x % 3 == 0 || x % 5 == 0) {
		printf("%d is a multiple of 3 or 5.\n", x);
	}
	else if ( !(x % 3 == 0 || x % 5 == 0) ) {
		printf("%d is not a multiple of 3 or 5.\n", x);
	}


	return 0;
}
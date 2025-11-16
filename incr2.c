#include <stdio.h>

int x = 10; // x is declared outside from any function. It can be seen by any function.

int incr(void) {
	static int y = 0;
	printf("y = %d\n", ++y);
	return x++; // The compiler will refer to the global variable since it is not present any local x.
}

int main(void) {
	incr();
	incr();
	incr();
	printf("x = %d\n", x);
	return 0;
}
/*
It is worth noticing the y variable. y is local inside incr but it has the same lifespan of a global variable, i.e., until the end of the main function. It is for this reason that being initialised at 0, in the end its value is 3.
*/
/*
Notice how x and y are written and incremented: x is first read and then incremented, while y is first incremented and then read to written on standard ouput.
*/

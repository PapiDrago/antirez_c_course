#include <stdio.h>

int incr(int x){
	x = x+1;
	return x;
}

int main(void) {
	int x = 10;
	incr(x);
	printf("Hello Vim!\n");
	printf("%d\n", x);
	return 0;
}
/*
In C the arguments are passed by value. In this case, it is still printed 10 because the value of the local variable x defined in the main function iscopied, i.e., assigned to the local variable x defined in incr function. Those variables are different memory location and have different lifespan.

One could say that arguments can be passed also by reference, yes we can say so recalling that it is passed the value of a pointer.

How can the main function print the incremented value of x? See you in the other code.
*/

#include <stdio.h>

int main(void) {
	/*Literals in C */

	int n = 10;		// '10' is a literal, a fixed-value used in the source code which does not need an intermediate value or calculations.
	double f = 1.214;	// Floating point numbers are also literal.
	char c = 'A';		// Between superscripts there can only be a character which is also a literal. Actually the compiler when it sees this kind of values replaces them with the corresponding index (code) in the ASCII table. We can view the ASCII table by typing on the terminal "man ASCII". For instance the char 'A' is coded with the 8 bit integer 65.-->i).
	char str[] = "Hello!"; // A string literal is anything it is written between quotes. As we can see a string is treated as an array of char."

	/**/
	printf("ASCII code: %d\nASCII char: %c\n", c, c);
	printf("%s\n", "Hello world"); // Also strings have their own placeholder.
	
	char str2[6] = {'h', 'e', 'l', 'l', 'o', 0}; // A low lewel string declaration and assignment. -->ii). We could neglect to mention the dimension of the arrauy since it was clear by counting the number of elements which was assigned.
	printf("%s\n", str2);
	printf("%lu is the size of \"hello\" in bytes\n", sizeof("hello")); //-->iii).

	int i = 0;
	while (str2[i] != 0) {
		printf("%c", str2[i]);
		i++;
	}
	printf("\n"); // A loop to show that strings are indeed array of chars.
	
	return 0;
}
/*
i) We already knew that the type 'char' is used to represent integer values with 1 byte. Char literals are mapped to 1-byte wide integer values according to the ASCII code. Then since a string is treated as an array of char values, we can say that a string is an array of integers interpreted as ASCII characters.
We can conclude that in C, all the types are numerical.

ii) A string must be always terminated by the null character '\0' which has ASCII code equal to 0. This means that this char is stored in memory as 0000 0000.
If in the low level declaration I would not specified it, we would have been exposed to an aleatory behaviour because the memory location subsequent to the one storing 'o' (0011 1111) can store anything. In practice the printf in general would not have printed "hello".

iii) It is interesting to note that sizeof is solved at compile time, so it is free to use. Also notice that when we use a string literal is always included implicitely the null character at the end.
*/

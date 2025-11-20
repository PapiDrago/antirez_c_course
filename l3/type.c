#include <stdio.h>

int main(void) {
	int i = 11; // int type represents numbers in 2's complement with 32 bit.
	float f = 1.234; // float type respresents floating point numbers in single precision, according to IEEE 754 standard (32 bit).
	printf("i = %d f = %.3f\n", i, f);
	printf("i = %d f = %f\n ", f, i); //--> i)
	printf("i = %x\n\n", i); // 11 --> 0xb

	char c = 127; // 2's complement integer with 8 bit.
	printf("c + 1 = %d\n", c+1); //--> ii)
	
	unsigned short s = 65535; // absolute value integer with 16 bit.
	printf("s = %d\n", s);

	i = 2147483647; // 2^31 -1
	printf("INT_MAX + 1 = %d\n", i+1); //--> iii)
	unsigned int uns_i = 4294967295; // 2^32 -1
	printf("UNSIGNED INT_MAX + 1 = %d\n", uns_i+1);

	c++; // c = c + 1; --> iv)	
	printf("c = %d\n", c);


	unsigned char uns_c = 255;
	uns_c = uns_c+1;
	printf("uns_c = %d\n", uns_c);
	return 0;

}
/*
i) I have used the type specificator used for floating point numbers '%f' in the printf format and I passed a corresponding argument which is instead an int type value. The C compiler does not generate a compiling error, it generates a warning. My C compiler seems more smart than the one used by antirez because it prints anyway the correct values. In the antirez output the bit were interpretated wrongly, i.e., the floating point value was interpreted as an integer and the integer as a double. The semantic was lost.

Why in the warning was mentioned a double type? Since printf() is variadic, in the implementation of it there is a logic that handles all the arguments. To lighen it some values are promoted automatically to a type which retains the semantic before being actually passed. 'float' values are promoted to 'double' values which is the 64 bit type to represent floating point number using double precision.

Notice also that some other specificator for printf are '%x', '%X' which are used to print the exadecimal value of a in integer.

ii) C language promotes also type also in other cases, for example when summing char values, those are first promoted to int values. This is why we do not meet overflow: with 8 bit 2's complement I can represent numbers in the range [-128, 127], howevever the result of the operation is meaningful since the result can be perfectly represented with just one bit more.

iii) Here it is shown that when we add 1 to the maximum positive number representable with 32 bit in 2's complement, overflow occurs and it is printed the smallest representable number in 2's complement. I addressed also the carry problem in the subsequent printf when it is done a sum between the biggest absolute number (positive number) with 32 bit and the result is 0.

iv) The char variable c is incremented by 1 and the result is stored in the same variable. That result cannot be correctly interpretated with 1 byte. For this reason when we print c we see -128 (overflow occured). This would have happened also if I would have assigned to c 128. Before it was not happening because the result was an int and was printed in the standard output.
Now it is important to notice that it was not said that the printed 'c' value would have been -128, indeed in C the overflow behaviour with signed number is not defined. The app could have been crashed for instance.

Instead the C standard guarantees that with unsigned number in case of carry we start from 0 (a kind of modulo sum).
*/

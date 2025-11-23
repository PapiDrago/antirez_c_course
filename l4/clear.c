#include <stdio.h>

#include <limits.h> // Including this header allows to use constants corresponding to extremes of data types.

#include <stdint.h> // We can access "advanced" int types. I think it is a wrapping of the primitive int types.

void clear(void) {
	printf("\x1B[H\x1B[2J\x1B[3J"); // We should have flushed the buffer in which printf accumulates chars to eventually write in the stdout. Typically when it encounters \n immediately flush all the content. This saves time because I/O ops are slow. In the printf there is the equivalent ASCII chars of hex control (escape) sequence: "1b 5b 48 1b 5b 32 4a 1b  5b 33 4a". Please note that each escape sequence is introduced by the char 'ESC' which on the ASCII table is coded as 0x1B (033 in octal).
}

int main(void) {

	clear();	

	printf("Max int number = %d, min int number %d\n", INT_MAX, INT_MIN);

	long l = 100;
	int i = 100;
	printf("Long type has size %lu bytes.\n", sizeof(l));
	printf("Int type has size %lu bytes.\n", sizeof(i));

	size_t n = 64; // A variable with this "advanced type" represents a dimensio in bytes.
	printf("size_t types has size %lu bytes.\n", sizeof(n)); // sizeof(n) = 8 bytes.
	
	intptr_t ptr; // This type is used when we want to sum addresses to see for instance is one refers to a memory location that is lower than another.
	int64_t long_int;

	return 0;
}

/*
The C standard does not constrain on the exact number of bits defining a type. This is due to the design of the language in the sixties when the C compiler needed to able to work on all kinds of system, ranging from low resources embedded system to supercomputers. Nowadays int types goes typically from 8 bits (1 byte) to 64 bytes. In particular the long integer type typically use a number of bits equal to the size of the system word (the size of an address). We can see the size of an integer type using the kewword sizeof(). It returns a long integer referring to the size measured in bytes.

It is important to specifies type guaranteeing to save resources: if the word width of the system is 8 byes (64 bit), then in a word 8 char can fit and so on.

In order to see the documentation of the "advanced" types listed here, I wrote in the terminal "man 3 intptr_t". We can use wider (than int type width) widths when to make sure not to meet overflow when handling known width values. For instance if my inputs are 32 bit wide then I can store a result in a value of type int64_t.

Finally, very interesting the use of the shell command 'hexdump', this shows the content of the file passed as argument in hexadecimal. With '-C' we can see it in the so-called canonical form which allows us to see the ASCII characters decoded from the hexadecimal chars.
We used hexdump to find out what the clear command sends to the terminal (escape sequence) in order to clear it. We ran in the shell "clear | hexdump -C". 
In that prompt we see a linux pipe that allows communication between programs: hexdump input is clear output.
*/

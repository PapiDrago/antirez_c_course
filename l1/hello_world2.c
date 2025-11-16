/*
Here I did not included the header file 'stdio.h' but I specified explicitely the prototype of the printf function.

To see what was the prototype I look up the printf in the Linux manual page. I typed on the terminal 'man 3 printf'. I specified '3' because without it the documentation of the shell printf appeared.
*/

int printf(const char *format, ...);

int main(void) {
	printf("Hello World\n");
	return 0;
}

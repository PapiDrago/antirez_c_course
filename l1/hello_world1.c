/*
The directive of the preprocessor are introduced by the '#' character. The C compiler before compiling the C code,
calls the preprocessor which pre-processes the source code. In this case the 'include' directive allows to put the content of a
file in place of the directive itself.
'stidio.h' is the filename of a header file. Typically in a header files are contained the prototypes of function which will be
called during the execution.
Without including it we cannot call the printf function in the main function, because the compiler does not know what arguments a function wants and what value is returned by it.

The 'printf' function is a standard C library function. However it is not part of the language itself, for this reason we cannot call it implicitely, i.e., without specifying the prototype.

It is crucial to know that the compiler does not need to know also the implementation of the printf function. The compiler when compiling, substitutes it (the name) with a placeholder. Then the linker, that knows where the C standard library is located, will place in the object file the already compiled definition of printf that is contained in the C standard library which has been already compiled.

NB keywords like int, void, for, while, if and so on are part of the C language.
*/

#include <stdio.h>

int main(void) { // This function returns a value of type int and it does not accept any arguments since there is the void keyword.
	printf("Hello World\n"); //printf stands for print formatted. It prints on the standard output (the terminal), the string formatted like that. \n is the newline character.
	return 0; //By convention the main returns 0 when the execution completed successfully. By convention the linux shell associates to 0 the 'TRUE' boolean value.
}

/*
To compile this source code, from the terminal we call the gcc compiler and we specify the filename of the file to be compiled.
We can leverage the capabilities of the compiler by specifying:
- -S, in order to stop the compilation up to the creation of the assembly code (.s file);
- -O2, level 2 Optimization: the compiler improves the source code:
- -o, we can specify the name of the executable. The default name is a.out.
*/

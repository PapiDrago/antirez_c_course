#include <stdio.h>

void recursive_count(int count) {
	if(count > 9)  return;
	printf("count at address %p is %d\n", &count, count);
	count++;
	recursive_count(count);
}

int main(void) {
	int i = 5;
	{
		int i = 10;
		// This "i" is local to this block, i.e., the portion of code delimited by curly brackets.
		printf("Value of i at address (%p), within the block: %d\n", &i, i);
	}
	printf("Value of i at address (%p), outside the block: %d\n", &i, i);
	
	// Now we try to count from 0 to 9 with different approaches.

	int count = 0;
CONDITION: 	if(count >= 10) goto NEXT; // goto is used to make unconditional jumps. if the condition is satisfied we jump to the code marked with label 'NEXT'.
		printf("count = %d\n", count);
		count ++;
		goto CONDITION;
NEXT:		printf("\n");
	
	count = 0;
	while(count <10) {	// While the condition is true, do what it is inside the block.
		printf("count = %d\n", count);
		count ++;
	}
	printf("\n");
	
	for (int count = 0; count<10; count++) {	// For count that goes from 0 to 9, do what it inside the for loop block.
		printf("count = %d\n", count);
	}
	printf("\n");
	
	count = 0;
	recursive_count(count);
	printf("\n");
	
	if (i == 0) {
		int boole = (i == 0);
		printf("(i == 0) = %d\n", boole);
	} else {
		printf("(i == 0) = %d\n", (i==0));
	}
	return 0;
}
/*
The recursive function used to count from 0 to 9, altough more elegant (maybe), uses in an ineffient way the stack, because every time the function is called there is at least the instantiation of a new local variable "count".

Please keep in mind that in C, boolean value do not exist. For convention a value equal to 1 is considered to be "TRUE", while any value different from 1 is considered to be "FALSE". This means that expressions defining a condition to be evaluated as "TRUE" or "FALSE", return 1 if the condition is satified.

Do not make confusion with program exit status (code): 0 corresponds to "the program met no errors during its execution", while any value different from 0 corresponds to a specific abnormal status of the program.
*/

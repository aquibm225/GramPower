//run as : gcc parseCMD.c -o a
#include <stdio.h> 							// scanf, printf
#include <stdbool.h> 						// bool
#include <stdlib.h> 						// malloc

//Pilot program
int main()
{
	char c;								// incoming character		

	FILE *inputfile;						// input file handler
	inputfile = fopen("test.txt", "r+");		// open input file 
	if (inputfile == NULL) 					// error in opening file
	{
		printf("No input file\n");			// print error
		return 0;							// exit
	}
	return 0;
}

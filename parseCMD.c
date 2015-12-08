//run as : gcc parseCMD.c -o a
#include <stdio.h> 						// scanf, printf
#include <stdbool.h> 						// bool
#include <stdlib.h> 						// malloc

char *data; 							// arrey of desired string
int state = -1; 						// state of SM
int numberofchar; 						// number of elements in desired string



//Pilot program
int main()
{
	char c;							// incoming character		
	bool helloFound = false;				// success flag			
	data = getdata();		
	FILE *inputfile;						// input file handler
	inputfile = fopen("test.txt", "r+");			// open input file 
	if (inputfile == NULL) 					// error in opening file
	{
		printf("No input file\n");			// print error
		return 0;					// exit
	}
	for(;;)								// run infinitely
	{
		c = fgetc(inputfile);				// get next character
		if(c == EOF)						// file end
			break;						// exit
		
 		helloFound = parseForHello(c);		// SM function
 		if(helloFound)						// success check
 			break;						// break if success
	}

	if(helloFound)							// print success
		printf("Found!!!\n");
	else 
		printf("Not Found!!!\n");				

	fclose(inputfile);						// close test file
	return 0;
}

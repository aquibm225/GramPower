//run as : gcc parseCMD.c -o a
#include <stdio.h> 						// scanf, printf
#include <stdbool.h> 						// bool
#include <stdlib.h> 						// malloc

char *data; 							// arrey of desired string
int state = -1; 						// state of SM
int numberofchar; 						// number of elements in desired string

char *getdata()
{
	FILE *datafile; 						// file handler
	char c; 								// incoming char

	unsigned int i; 						// looping variable
	char *data; 							// desired string container
	datafile = fopen("data.txt", "r+");		// open data file, containing desired string
	if (datafile == NULL) 					// error in opeining file
	{
		printf("No data file\n");			// print error
		return 0;							// exit
	}

	numberofchar = fgetc(datafile) - (int)'0';	// get length of desired string
	data = malloc(numberofchar*sizeof(char));	// allocate memory
	c = fgetc(datafile);					// get newline after length in datat.txt

	for(i=0;i<numberofchar;i++)				// get all characters in desired string
	{
		c = fgetc(datafile);
		if(c == EOF)						// file end condition
			break;						// break loop, protection for wrong data file
		else
			data[i] = c;
	}
	return data;
}

bool parseForHello(char c)
{
	if(c == data[0])
		state = 0;
	else if(c == data[state+1])
		state++;
	//else if(c == data[state]) 					// redundant yet written for clarification of algorithm
	//   redundant yet written for clarification of algorithm	state = state; 
									// redundant yet written for clarification of algorithm
	else
		state = -1;

	if(state == numberofchar-1) 					// reached end of SM
		return true; 						// return success

	return false; 							// return failure
}

//Pilot program
int main()
{ 
	char c;								// incoming character		
	bool helloFound = false;					// success flag			
	data = getdata();		
	FILE *inputfile;						// input file handler
	inputfile = fopen("test.txt", "r+");				// open input file 
	if (inputfile == NULL) 						// error in opening file
	{
		printf("No input file\n");				// print error
		return 0;						// exit
	}
	for(;;)								// run infinitely
	{
		c = fgetc(inputfile);					// get next character
		if(c == EOF)						// file end
			break;						// exit
		
 		helloFound = parseForHello(c);				// SM function
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

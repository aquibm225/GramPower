all : parse

parse : parse.o
	gcc -o parse parse.o 

parse.o : parseCMD.c
	gcc -c parseCMD.c

clean :
	rm parse *.o

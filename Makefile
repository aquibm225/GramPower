all : parseCMD

parse : parseCMD.o
	gcc -o parseCMD parseCMD.o 

parse.o : parseCMD.c
	gcc -c parseCMD.c

clean :
	rm parseCMD *.o

all : parseTEXT

parse : parseTEXT.o
	gcc -o parseTEXT parseTEXT.o 

parse.o : parseTEXT.c
	gcc -c parseTEXT.c

clean :
	rm parseTEXT *.o

all: executavel

executavel: main.o in-out.o forca-bruta.o
	gcc -g main.o in-out.o forca-bruta.o -o executavel

main.o: main.c
	gcc -c main.c

in-óut.o: in-out.c
	gcc -c in-out.c

forca-bruta.o: forca-bruta.c
	gcc -c forca-bruta.c

clean:
	rm -f *.o executavel
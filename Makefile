all: tp3

tp3: main.o in-out.o forca-bruta.o shift-and-exato.o
	gcc -g main.o in-out.o forca-bruta.o shift-and-exato.o -o tp3

main.o: main.c
	gcc -c main.c

in-out.o: in-out.c
	gcc -c in-out.c

forca-bruta.o: forca-bruta.c
	gcc -c forca-bruta.c

shift-and-exato.o: shift-and-exato.c
	gcc -c shift-and-exato.c

clean:
	rm -f *.o executavel
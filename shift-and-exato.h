#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** criaMascara(int l, int c);
void freeMascara(int** mascara, int l, int c);
void preencheMascara(int** mascara, char* padrao);
void zeraR(int* R, int tam);
void deslocaR(int* R, int tam);
void RAndMascara(int* R, int tamR, int** mascara, char caracter);
void shiftAnd(char* texto, char* padrao);
void zeraMascara(int** mascara, int l, int c);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//funcoes para o tratamento das mascaras dos caracteres do padrao
int** criaMascara(int l, int c);
void freeMascara(int** mascara, int l, int c);
void preencheMascara(int** mascara, char* padrao);
void zeraMascara(int** mascara, int l, int c);

//funcoes para o tratamento do conjunto R que representa o paralelismo de bit
void zeraR(int* R, int tam);
void deslocaR(int* R, int tam);

//algoritmo que executa a operacao do conjunto R com a mascara do caracter lido
void RAndMascara(int* R, int tamR, int** mascara, char caracter);

//algoritmo principal
void shiftAnd(char* texto, char* padrao);
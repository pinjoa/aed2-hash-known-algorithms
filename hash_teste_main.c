/**
 * @file hash_teste_main.c
 * @author João Carlos Pinto
 * @brief pequeno programa para testar a utilização da função de hash
 * @version 0.1
 * @date 2021-05-16
 *
 * @copyright Copyright (c) 2021, João Carlos Pinto
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_known_algorithms.h"

#define CM 1000

// gerar string aleatória
char *str_rand(char *texto, int tMax) {
    const int iDesvio = 5;
    const int iMax = tMax-1-iDesvio;
    int size = rand() % iMax + iDesvio;  // [iDesvio, iMax[
    texto[0] = 'A' + rand() % 26;    // 'A' = 65   rand() % 26 == 5 ==> 65+5
    for (int i = 1; i < size - 1; i++) {
        texto[i] = 'a' + rand() % 26;
    }
    texto[size-1] = '\0';
    return texto;
}

// default stringHash
int stringHashFunc(char *txt) {
    unsigned int c=SDBMHash(txt, strlen(txt));
    return (c % CM);
}

int main() {
    int iTamanhoMaxString = 21;
    int iTotalStrings = 5;
    char *tempTxt = malloc(iTamanhoMaxString);

    printf("Hello, World!\n");
    printf("HashTable size = %d\n",CM);
    printf("[String hash algorithm: 05 - SDBM Hash Function]\n\n");
    for (int i = 0; i < iTotalStrings; ++i) {
        tempTxt = str_rand(tempTxt, iTamanhoMaxString);
        printf("Iteração (%d) \nTexto = %s \nPosição HashTable = %d\n\n", i+1, tempTxt, stringHashFunc(tempTxt));
        tempTxt[0]='\0';
    }
    // libertar espaço da string temporaria...
    free(tempTxt);

    return 0;
}

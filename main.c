/**
 * @author Carolina
 * @date 2022-04-20
 * @brief Corrida Codigo Reutilizado Prof.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corrida.h"

int main(int argc, char const *argv[])
{

    if (argc != 2)
    {
        return EXIT_FAILURE;
    }

    FILE *f = fopen("results-atec.txt", "r"); // Carregar ficheiro para leitura

    // Verificação de carregamento do ficheiro se for != de 0 retorna ERRO.
    if (f == NULL)
    {
        printf("ERRO! O ficheiro não foi carregado!\n");
        return EXIT_FAILURE;
    }
    if (strcmp(argv[1], "results-atec.txt") != 0)
    {
        printf("ERRO! O ficheiro não foi carregado!\n");
        return EXIT_FAILURE;
    }

    Corrida *c = newCorrida();

    int pos;
    char *esc;
    int posEscal;
    int dorsal;
    char *nome;
    char *sexo;
    char *tempo;
    char *token;
    char linha[1024];
    int contador = 0;
    memset(linha, '\0', 1024);

    while (fgets(linha, 1024 - 1, f))
    {
        if (contador == 0)
        {
            contador++;
            memset(linha, '\0', 1024);
            continue;
        }

        token = strtok(linha, "\t"); // Apanha a linha até ao primero tab
        pos = atoi(token);          // Atoi converte string em inteiros
        esc = strtok(NULL, "\t");
        token = strtok(NULL, "\t");
        posEscal = atoi(token);
        token = strtok(NULL, "\t");
        dorsal = atoi(token);
        nome = strtok(NULL, "\t");
        sexo = strtok(NULL, "\t");
        tempo = strtok(NULL,"\t");

        

        addAtletaInt(c, pos, esc, posEscal, dorsal, nome, sexo, tempo);
       
            memset(linha, '\0', 1024); //preenche a linha com \0
    }
    fclose(f); //Fecho da leitura do fcicheiro .txt
    
    int dorsalinput; //Variavel para guardar o input do utilizador

    do{

        printf("Insira o nº da Dorsal -->"); // Pedido de input do tilizador
        scanf("%i", &dorsalinput); //leitura do input do utilizador
        printListInt(c, dorsalinput); //print da informação dada pelo input
            
    }while (dorsalinput != 0);


    freeList(c); //liberta a memoria da lista

    return EXIT_SUCCESS;
}
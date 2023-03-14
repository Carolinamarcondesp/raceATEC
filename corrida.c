/**
 * @author Carolina
 * @date 2022-04-20
 * @brief Corrida Codigo Reutilizado Prof.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corrida.h"

Corrida *newCorrida()
{
    Corrida *c = malloc(sizeof(Corrida)); //alocação de memoria para a estrutura de lista c
    c->total = 0;
    c->first = NULL;
    c->last = NULL;
    return c;
}

void freeList(Corrida *c) //liberta memoria da lista 
{
    Atleta *tmp, *atleta = c->first;
    while (atleta)
    {
       //liberta memoria dos elementos  
        free(atleta->esc);
        free(atleta->nome);
        free(atleta->sexo);
        free(atleta->tempo);
        tmp = atleta->next;
        free(atleta);
        atleta = tmp;
    }
    free(c);
}

void addAtletaInt(Corrida *c, int pos, char *esc, int posEscal, int dorsal, char *nome, char *sexo, char *tempo)
{
    Atleta *atleta = malloc(sizeof(Atleta)); //Alocação de memoria para estrutura "atleta"

    atleta->pos = pos;
    atleta->esc = malloc(strlen(esc) + 1);        // tamanho da string +1 para ter o \0 no final
    memset(atleta->esc, '\0', (strlen(esc) + 1)); // encher a string com \0
    strcpy(atleta->esc, esc);                     // enche a string com a informação "esc" 
    atleta->posEscal = posEscal;
    atleta->nome = malloc(strlen(nome) + 1);
    memset(atleta->nome, '\0', (strlen(nome) + 1));
    strcpy(atleta->nome, nome);
    atleta->sexo = malloc(strlen(sexo) + 1);
    memset(atleta->sexo, '\0', (strlen(sexo) + 1));
    strcpy(atleta->sexo, sexo);
    atleta->dorsal = dorsal;
    atleta->tempo = malloc(strlen(tempo) + 1);
    memset(atleta->tempo, '\0', (strlen(tempo) + 1));
    strcpy(atleta->tempo, tempo);
    // atleta->num = n;
    // atleta->word = NULL;

    // Quando não há nós na lista
    if (!c->first)
    { // c->first==NULL Primeiro ponteiro da lista é igual a NULL | representa a mesma indicação da linha acima -> notas para mim
        atleta->next = NULL;
        atleta->prev = NULL;
        c->first = atleta;
        c->last = atleta;
        c->total++;
        return;
    }

    Atleta *busca = c->first;
    while (busca)
    {

        // condição se é repetido
        if (busca->dorsal == dorsal)
        {
            free(atleta->esc);
            free(atleta->nome);
            free(atleta->sexo);
            free(atleta->tempo);
            free(atleta);
            return;
        }
        // ver se é a posição
        if (busca->dorsal > dorsal)
            break;
        busca = busca->next;
    }

    // Inserir no fim
    if (busca == NULL)
    {
        atleta->next = NULL;
        atleta->prev = c->last;
        c->last->next = atleta;
        c->last = atleta;
        c->total++;
        return;
    }

    // Inserir no inicio da lista
    if (busca == c->first)
    {
        atleta->prev = NULL;
        atleta->next = c->first;
        c->first->prev = atleta;
        c->first = atleta;
        c->total++;
        return;
    }

    // Se cheguei aqui é no meio
    atleta->next = busca;
    atleta->prev = busca->prev;
    busca->prev = atleta;
    atleta->prev->next = atleta;
    c->total++;
}

void printListInt(Corrida *c, int dorsalinput) // Imprime informações dos elementos da lista
{
    Atleta *atleta = c->first;

    if (dorsalinput < 0) // Se o numero de input do user for menor que zero retorna erro
    {
        printf("ERRO!!! Nº de dorsal inválido!!!\n");
        return;
    }
    if (dorsalinput == 0) // zero para sair da programa
    {
        printf("A Sair... Obrigada\n");
        return;
    }

    
    while (atleta) // Imprime informações dos elementos da lista (input do user: nº dorsal)
    {
        if (dorsalinput == atleta->dorsal)
        {

            printf("---------------------");
            printf("\nAtleta: %s", atleta->nome);
            printf("\nSexo: %s", atleta->sexo);
            printf("\nPosição Geral: %d", atleta->pos);
            printf("\nPosição Escalão: %d", atleta->posEscal);
            printf("\nTempo da Corrida: %s", atleta->tempo);
            printf("---------------------\n");

            return;
        }
        if (atleta->dorsal > dorsalinput)
        {

            printf("Erro!!! Nº de dorsal inválido!!!\n");
            return;
        }

        atleta = atleta->next;
    }
}

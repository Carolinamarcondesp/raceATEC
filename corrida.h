#ifndef CORRIDA_H
#define CORRIDA_H

// Estrutura 1
typedef struct _atleta
{
    
    int pos;
    char *esc;
    int posEscal;
    int dorsal;
    char *nome;
    char *sexo;
    char *tempo;
    struct _atleta *next;
    struct _atleta *prev;
} Atleta;

// Estrutura 2
typedef struct _c
{
    int total; // Elementos presentes na lista
    Atleta *first;
    Atleta *last;
}Corrida;

Corrida *newCorrida(); // criar nova lista

void freeList(Corrida *c);

void addAtletaInt(Corrida *c, int pos, char *esc, int posEscal, int dorsal, char *nome, char *sexo, char *tempo);

void printListInt(Corrida *c, int dorsalinput);

#endif
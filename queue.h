#ifndef QUEUE_H
#define QUEUE_H
#define NMAX 100
#include "linkedList.h"
#include "cliente.h"
#include "strings.h"


#define topo(P) ((P)->queue[(P)->inicio])
#define tamanho_max(P) ((P)->nmax)
#define inicio(P) ((P)->inicio)
#define fim(P) ((P)->fim)

typedef enum {FALSE,TRUE} BOOL;


typedef struct fila { //ter uma fila
  int inicio, fim, nmax;
  CLIENTE* *queue;
} QUEUE;

// criar fila com capacidade para n inteiros
QUEUE *nova_fila(int n);
// colocar valor na fila
void coloca(CLIENTE *c,QUEUE *f);
// retirar valor na fila
CLIENTE *retira(QUEUE *q);
// verificar se a fila está vazia
BOOL fila_vazia(QUEUE *f);
// verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE *f);
// liberta fila
void free_queue(QUEUE *f);

//My give
QUEUE *nova_fila(); //x
int comprimento(QUEUE *f); //x
LISTA *fila_para_lista(QUEUE *f); //x
BOOL e_fila(QUEUE *f); 
BOOL filas_iguais(QUEUE *f1, QUEUE *f2); //x
char *print_queue(QUEUE *q); //x
#endif

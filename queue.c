#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

static void queue_exit_error(char *msg);

static void queue_exit_error(char *msg) {
  fprintf(stderr,"Error: %s.\n",msg);
  exit(EXIT_FAILURE);
}

// criar fila com capacidade para n inteiros
QUEUE *nova_fila(int n)
{
  QUEUE *q = (QUEUE *) malloc(sizeof(QUEUE));
  if (q == NULL) 
    queue_exit_error("sem memoria");

  q -> queue =  (CLIENTE **) malloc(sizeof(CLIENTE)*n);
  if (q -> queue == NULL) 
    queue_exit_error("sem memoria");

  q -> nmax = n;
  q -> inicio = -1;
  q -> fim = 0;
  return q;
}

// libertar fila
void free_queue(QUEUE *q)
{
  if (q != NULL) {
    free(q -> queue);
    free(q);
  } else 
    queue_exit_error("fila mal construida");
}


// colocar valor na fila
void coloca(CLIENTE *v,QUEUE *q)
{  
  if (queue_is_full(q) == TRUE) 
    queue_exit_error("fila sem lugar");

  if (q -> queue == NULL) 
    queue_exit_error("fila mal construida");

  if (fila_vazia(q)==TRUE) 
    q -> inicio = q -> fim; // fila fica com um elemento
  q -> queue[q->fim] = v;
  q -> fim = (q -> fim+1)%(q->nmax); 
}

// retirar valor na fila
CLIENTE *retira(QUEUE *q){
	  
  CLIENTE *aux;
  if (fila_vazia(q) == TRUE) 
    queue_exit_error("fila sem valores");

  if (q -> queue == NULL) 
    queue_exit_error("fila mal construida");

  aux = q ->queue[q ->inicio];
  q -> inicio = (q -> inicio+1)%(q -> nmax);
  if (q -> inicio ==  q -> fim) {  // se só tinha um elemento
    q -> inicio = -1; q -> fim = 0;  
  }
  
  return aux;
}

// verificar se a fila está vazia
BOOL fila_vazia(QUEUE *q)
{ 
  if (q == NULL) 
    queue_exit_error("fila mal construida");

  if (q -> inicio == -1) return TRUE;
  return FALSE;
}

// verificar se a fila não admite mais elementos
BOOL queue_is_full(QUEUE *q)
{ 
  if (q == NULL) 
    queue_exit_error("fila mal construida");

  if (q -> fim == q -> inicio) return TRUE;
  return FALSE;
}

//My Implementation
int comprimento(QUEUE *q){
	if(q->inicio < q->fim)
		return (q->fim - q->inicio);
	else{
		return (q->nmax-q->inicio + q->fim);
	}
}

LISTA *fila_para_lista(QUEUE *q){
	LISTA *lista=NULL;
	int aux = q->inicio;
	
	while(aux!=q->fim){
		lista=addLast(lista,q->queue[aux]);
		aux=(aux+1)%(q->nmax);
	}
	return lista;
}

BOOL filas_iguais(QUEUE *f1, QUEUE *f2){
	int aux1=f1->inicio,aux2=f2->inicio;
	
	while(aux1!=f1->fim && aux2!=f2->fim){
		if(f1->queue[aux1]!=f2->queue[aux2])
			return FALSE;
		aux1=(aux1+1)%(f1->nmax);
		aux2=(aux2+1)%(f2->nmax);					
	}
	return TRUE;
}

char *print_queue(QUEUE *q){//mudar para retornar *char?
    if (fila_vazia(q)) {
        return "< <";
    }

    char *res=NULL;

    cats(&res,"<");

    int aux = q->inicio;

    while(aux!=q->fim) {
        cats(&res,print_cliente(q->queue[aux]));
        aux = (aux+1)%(q->nmax);
    }

    cats(&res,"<");

    return res;
}

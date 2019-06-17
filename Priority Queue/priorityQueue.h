#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#define ELEM(P) ((P) -> elem)
#define PRIORITY(P) ((P) -> priority)
#define NXT(P) ((P) -> next)

typedef enum prioridade{URGENTE, NORMAL} PRIORIDADE;

typedef struct priority_queue{
  int elem;
  PRIORIDADE priority;
  struct priority_queue *next;
} PRIORITY_QUEUE;


// cria nova priorityqueue
PRIORITY_QUEUE *new_priority_queue(int elem, PRIORIDADE pri);
// adiciona um elemento a fila
PRIORITY_QUEUE *coloca(PRIORITY_QUEUE *q, int elem, PRIORIDADE pri);
// retira o elemento com mais prioridade na fila
int retira(PRIORITY_QUEUE *q);
// aumenta a prioridade do 1º elemento da fila NORMAL
void aumenta_prioridade(PRIORITY_QUEUE *q);
// imprime a fila
void print_priority_queue(PRIORITY_QUEUE *q);

#endif

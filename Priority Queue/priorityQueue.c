#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "priorityQueue.h"

PRIORITY_QUEUE *new_priority_queue(int elem, PRIORIDADE pri){
    PRIORITY_QUEUE *q = (PRIORITY_QUEUE *) malloc(sizeof(PRIORITY_QUEUE));
    ELEM(q) = elem;
    PRIORITY(q) = pri;
    NXT(q) = NULL;
    return q;
}

PRIORITY_QUEUE *coloca(PRIORITY_QUEUE *q, int elem, PRIORIDADE pri){
    PRIORITY_QUEUE *prev = NULL;
    PRIORITY_QUEUE *curr = q;
    if(q == NULL){
        return new_priority_queue(elem, pri);
    }
    if(pri == NORMAL){
        while(curr != NULL){
            prev = curr; 
            curr = NXT(curr);
        }
        NXT(prev) = new_priority_queue(elem, pri);
        return q;
    }
    else{ 
        if(PRIORITY(q) == NORMAL){
            PRIORITY_QUEUE *new = new_priority_queue(elem,pri);
            ELEM(new)= ELEM(q);
            NXT(new) = NXT(q);
            PRIORITY(new) = PRIORITY(q);
            ELEM(q)= elem;
            NXT(q)= new;
            PRIORITY(q) = pri;
            return q;
        }
        else{
            while(curr != NULL && PRIORITY(curr) == URGENTE){
                prev = curr;
                curr = NXT(curr);
            }
            PRIORITY_QUEUE * new = new_priority_queue(elem,pri);
            NXT(new) = NXT(prev);
            NXT(prev) = new;
            return q;
        }
    }
}

int retira(PRIORITY_QUEUE *q){
    if(q == NULL){
        printf("Erro! Lista vazia\n");
    }
    int valor = ELEM(q);
    ELEM(q) = ELEM(NXT(q));
    NXT(q) = NXT(NXT(q));
    PRIORITY(q) = PRIORITY(NXT(q));
    return valor;
}

void aumenta_prioridade(PRIORITY_QUEUE *q){
    PRIORITY_QUEUE *curr = q;
    if(q == NULL){
        printf("Fila vazia\n");
        return;
    }
    while(PRIORITY(curr) == URGENTE){
        curr = NXT(curr);
    }
    PRIORITY(curr) = URGENTE;
}

void print_priority_queue(PRIORITY_QUEUE *q){
    PRIORITY_QUEUE *curr = q;
    if(q == NULL) printf("Lista vazia\n");
    while(curr!=NULL){
        printf("Elemento: %d, Prioridade: %d\n", ELEM(curr), PRIORITY(curr));
        curr = NXT(curr);
    }
}

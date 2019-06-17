#include <stdio.h>
#include "priorityQueue.h"

int main(){
    PRIORITY_QUEUE *q = new_priority_queue(6,URGENTE);
    coloca(q,5,NORMAL);
    coloca(q,1,URGENTE);
    coloca(q,8,NORMAL);
    coloca(q,5,NORMAL);
    coloca(q,2,NORMAL);
    coloca(q,1,URGENTE);
    retira(q);
    aumenta_prioridade(q);
    print_priority_queue(q);
    return 0;
}

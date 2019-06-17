#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

LISTA *newList(CLIENTE *c){
	LISTA *new = (LISTA *)malloc(sizeof(LISTA));
	new->elem = c;
	new->next = NULL;
	return new;
}

LISTA *addLast(LISTA *l1,CLIENTE *c){
  LISTA *prev = NULL;
  LISTA *curr = l1;
  if (l1 == NULL) {
    return newList(c);
  }
  while (curr != NULL) {
    prev = curr;
    curr = curr->next;
  }

  prev->next = newList(c);

  return l1;
}

void printList(LISTA *l) {
  while (l != NULL) {
    printf("%s\n ", print_cliente(l->elem));
    l = l->next;
  }
  printf("\n");
}

LISTA *last(LISTA *l) {

  while(l->next!=NULL) {
    l= l->next;
  }

  return l;

}


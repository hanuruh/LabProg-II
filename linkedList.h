#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASH_SIZE 100
#define MULTIPLIER 31

typedef struct list{ 
	CLIENTE *elem;
	struct list *next;
}LISTA;

LISTA *newList(CLIENTE *c);
LISTA *addLast(LISTA *l1,CLIENTE *c);
LISTA *last(LISTA *l);
void printList(LISTA *l);

#endif

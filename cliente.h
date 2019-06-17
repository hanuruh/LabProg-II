#ifndef CLIENTE_H
#define CLIENTE_H


#define artigos(P) ((P)->items)
#define tempo_entrada(P) ((P)->entrada)

typedef struct cliente{
	int items, entrada;
}CLIENTE;

CLIENTE *novo_cliente(int artigos,int entry);
char *print_cliente(CLIENTE *c);

#endif

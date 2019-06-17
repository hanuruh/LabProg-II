#ifndef CAIXA_H
#define CAIXA_H
#include "queue.h"
#include "strings.h"

#define MINPC 1
#define MAXPC 5
#define QSize 20
#define fila_caixa(P) ((P)->queue)
#define numero(P) ((P)->n_caixa)
#define pronta(P) ((P)->pronta_em)
#define clientes(P) ((P)->cts_atend)
#define produtos(P) ((P)->produtos_processados)
#define espera(P) ((P)->total_espera)
#define tempo_processamento(P) ((P)->prods_ut)


typedef struct caixa{
	int n_caixa;
	int pronta_em;
	int cts_atend;
	int produtos_processados;
	int total_espera;
	int prods_ut;
	
	QUEUE *queue;
	
} CAIXA;

CAIXA *nova_caixa(int numero);
void disponivel(CAIXA *n, int valor);
void cliente_atendido(CAIXA *n);
void actualiza_produtos(CAIXA *n, int produtos);
void actualiza_espera(CAIXA *n, int t); 
BOOL vazia(CAIXA *n);
char *print_caixa(CAIXA *c);

#endif


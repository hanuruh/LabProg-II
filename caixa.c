#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "caixa.h"

CAIXA *nova_caixa(int numero){

	CAIXA *c = (CAIXA *) malloc(sizeof(CAIXA));
	
	c->queue= nova_fila(QSize);
	c->n_caixa=numero;
	c->pronta_em=0;
	c->cts_atend=0;
	c->produtos_processados=0;
	c->total_espera=0;
	
	srand(time(0));
	c->prods_ut=(rand()%(MAXPC-MINPC+1)) + MINPC;
	
	return c;

}

void disponivel(CAIXA *n,int valor){
	n->pronta_em=valor;

}

void cliente_atendido(CAIXA *n){
	n->cts_atend++;
}

void actualiza_produtos(CAIXA *n,int produtos){
	n->produtos_processados+=produtos;	
}

void actualiza_espera(CAIXA *n,int valor){
	n->total_espera+=valor;
}

BOOL vazia(CAIXA *n){
	if(fila_vazia(n->queue))
		return TRUE;
	else
		return FALSE;
}

char *print_caixa(CAIXA *c){ //not finished
	char *repr =NULL;

    cats(&repr,"Caixa ");
    cats(&repr,int2str(numero(c)));
    cats(&repr," (");
    cats(&repr,int2str(pronta(c)));
    cats(&repr,"): ");
    cats(&repr,print_queue(fila_caixa(c)));

    return repr;
	
}

#include "simulacao.h"
#include "math.h"
#include "caixa.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//corresponde ao atendimento dos clientes que estão no início das filas das caixas num determinado instante de tempo.
void trata_clientes(int tempo, CAIXA **caixas, int n_caixas){
	int i=0;
	while(i<n_caixas){
		if(!fila_vazia(fila_caixa(caixas[i]))){
			CLIENTE *clt = topo(fila_caixa(caixas[i]));
			int nb_artigos=artigos(clt);
			int t_atendimento = tempo - pronta(caixas[i]);
			int artigos_prcds=nb_artigos/tempo_processamento(caixas[i]);
			
			if(artigos_prcds < t_atendimento){ //o cliente sai da fila da caixa
				int t_entrada_fila = tempo_entrada(clt);
				int t_espera = tempo - t_entrada_fila;
				printf("-->Processado cliente com %d artigos na caixa %d tempo de espera %d. \n",nb_artigos,numero(caixas[i]),t_espera);
				disponivel(caixas[i],tempo+1);
				cliente_atendido(caixas[i]);
				actualiza_produtos(caixas[i],nb_artigos);
				actualiza_espera(caixas[i],t_espera);
				retira(fila_caixa(caixas[i])); //o cliente sai da fila
			}		
		}else
			disponivel(caixas[i],tempo);
		i++;
	}
}

//mostra as estatísticas da execução de programa
void processa_resultados(CAIXA **caixas, int n_caixas){
	int i=0;
	while(i<n_caixas){
		int c = clientes(caixas[i]);
		printf("Caixa %d (%d produtos por ciclo): ", numero(caixas[i]), tempo_processamento(caixas[i]));
		if(c >0)
			printf("%d clientes atendidos, media = %f. \n Tempo médio de espera: %f.\n",c,(float)produtos(caixas[i])/c,(float)espera(caixas[i]));
		else
			printf("Não atendeu clientes.\n");
		i++;
	}
}

//representação externa de cada uma das caixas
void mostra_caixas(CAIXA **caixas, int n_caixas){
	int i=0;
	while(i<n_caixas){
		printf("%s\n", print_caixa(caixas[i]));
		i++;
	}
}

//verificação de caixas vazias
BOOL existem_caixas_com_fila(CAIXA **caixas, int n_caixas){
	int i=0;
	while(i<n_caixas){
		if(!fila_vazia(fila_caixa(caixas[i])))
			return TRUE;
		i++;
	}
	return FALSE;
}

//simula um supermercado com n caixas durante t ciclos, em que os clientes são gerados com uma afluencia e uma apetencia
void simulador(int afluencia, int apetencia, int n_caixas, int ciclos){
	srand(time(0));
	//inicializa caixas
    CAIXA* caixas[n_caixas];

    //inicializar as caixas
    for(int i=0; i<n_caixas; i++){
        caixas[i] = nova_caixa(i);
    }
    int i;
     //inicia simulação
     for(int i=1;i<=ciclos;i++){
		printf("\n== CICLO %d ==\n", i);
		
		//processa clientes nas caixas
		trata_clientes(i,caixas,n_caixas);
		
		
		double aleatorio = (double) rand() / (double)RAND_MAX;
		double limite = (double)afluencia/100;
		
		//cria novo cliente aleatoriamente
		if(aleatorio < limite){
			
			//cria numero de produtos aleatoriamente
			int produtos = (((double) rand() / (double)RAND_MAX) * 3 * apetencia) +1;
			CLIENTE *c= novo_cliente(produtos,i);
			printf("--> Criado cliente com %d produtos.\n", produtos);
			
			//seleciona caixa aleatoriamente
			int nb_cx = ((double) rand() / (double)RAND_MAX) * n_caixas;
			
			//coloca cliente na fila
			coloca(c,fila_caixa(caixas[nb_cx]));		
		}
		
		mostra_caixas(caixas,n_caixas);
	 }
	 
	 //fecho  de simulação
	 printf("\n== FECHO DE CAIXAS ==\n");
	 i= ciclos+1;
	 
	 while(existem_caixas_com_fila(caixas,n_caixas)){
			printf("== CICLO %d ==\n", i);
			trata_clientes(i,caixas,n_caixas);
			mostra_caixas(caixas,n_caixas);
			i++;			
	 }
	 
	 processa_resultados(caixas,n_caixas);
}

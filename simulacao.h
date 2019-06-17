#ifndef SIMULACAO_H
#define SIMULACAO_H
#include "caixa.h"


void simulador(int afluencia, int apetencia, int n_caixas, int ciclos);
void trata_clientes(int tempo, CAIXA **caixas, int n_caixas);
void processa_resultados(CAIXA **caixas, int n_caixas);
void mostra_caixas(CAIXA **caixas, int n_caixas);
BOOL existem_caixas_com_fila(CAIXA **caixas, int n_caixas); 


#endif

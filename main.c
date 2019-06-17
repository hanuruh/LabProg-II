#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "math.h"
#include "caixa.h"
#include "simulacao.h"

int main() {

    int afluencia;
    int apetencia;
    int n_caixas;
    int ciclos;

    printf("Afluencia:\n");
    scanf("%d", &afluencia);
    printf("Apetencia:\n");
    scanf("%d", &apetencia);
    printf("N_Caixas:\n");
    scanf("%d", &n_caixas);
    printf("Ciclos\n");
    scanf("%d", &ciclos);

    simulador(afluencia, apetencia, n_caixas, ciclos);

    return 0;

}

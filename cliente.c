#include "cliente.h"
#include "strings.h"
#include <stdio.h>
#include <stdlib.h>

CLIENTE *novo_cliente(int artigos, int entry){
	
	CLIENTE *c = (CLIENTE *) malloc(sizeof(CLIENTE));
	
	c->items=artigos;
	c->entrada=entry;
		
	return c;
}


char *print_cliente(CLIENTE *c){
	char *res=NULL;

    cats(&res," [");
    cats(&res,int2str(artigos(c)));
    cats(&res,":");
    cats(&res,int2str(tempo_entrada(c)));
    cats(&res,"] ");

    return res;
	
	/*char *str;
	sprintf(str,"[%d:%d]", artigos(c),tempo_entrada(c));
	
	return str;
	* */
}

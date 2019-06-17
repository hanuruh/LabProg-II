
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "strings.h"


char *int2str(int n) {

    if (n==0) {
        return "0";
    }

    int ndigits = (int)log10((double)n) +1;
    char *res = malloc(sizeof(char)*(ndigits+1));
    res[ndigits] = '\0';
    ndigits--;
    do {
        res[ndigits--] = (n%10)+'0';
        n = n/10;
    } while(n!=0);

    return res;

}

void cats(char **str, const char *str2) {
    char *tmp = NULL;

    if (*str == NULL) {
        *str = calloc( strlen(str2)+1, sizeof(char) );
        memcpy( *str, str2, strlen(str2) );
    }

    else {
        tmp = calloc( strlen(*str)+1, sizeof(char) );
        memcpy( tmp, *str, strlen(*str) );
        *str = calloc( strlen(*str)+strlen(str2)+1, sizeof(char) );
        memcpy( *str, tmp, strlen(tmp) );
        memcpy( *str + strlen(*str), str2, strlen(str2) );
        free(tmp);
    }

}

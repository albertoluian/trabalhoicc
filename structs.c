#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Contato {
    char nome[102];
    char nomeRel[102];
    unsigned long long int numero;
    char endereco[302];
    int relacao;
    char email[302];
};

#include "list.c"

int main()
{
    struct Contato contato;

    fgets(contato.nome, 101, stdin);
    scanf("%llu", &contato.numero);
    fgets(contato.endereco , 301,stdin);
    fgets(contato.endereco , 301,stdin);
    fgets(contato.relacao , 301,stdin);
    fgets(contato.email , 301,stdin);
    
    printContact(contato);

    return 0;
}

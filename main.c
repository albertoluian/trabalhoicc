#include "listMethods.c"
#include <stdlib.h>

struct Contato* alocarMais(struct Contato *contatos)
{
    struct Contato *Aux;

    Aux = (struct Contato*) malloc((len + 10) * sizeof(struct Contato));

    int c;
    for(c = 0; c < len; c++)
        Aux[c] = contatos[c];

    return Aux;
} 

int main()
{
    Lista = malloc(sizeof(struct Contato));
    int espaco = 10;
    int n = -1;
    printf("------------------------\nAgenda de contatos\n------------------------\n");
    while(n!=0){
    
    printf("Digite:\n1-Adicionar Contato\n2- Remover contato\n3-Listar contatos\n4-Pesquisar contato por nome\n5-Pesquisar contato por telefone\n0-Sair\n");
    scanf("%d", &n); getchar();
    
    if(n==1)
    {
        if(len * sizeof(struct Contato) == sizeof(Lista))
            Lista = alocarMais(Lista);
        AddContato(criarContato());
    } 
    
    else if(n==2){
        printf("Digite o numero do contato a ser deletado\n");
        long long unsigned temp;
        scanf("%llu", &temp);
        DelContato(temp);
    }
    else if(n==3) listarContatos();
    
    else if(n==4){
        char tempName[100];
        printf("Digite o nome do contato\n");
        fgets(tempName, 100, stdin);
        buscaPorNome(tempName);
    }
    else if(n==5){
        long long unsigned temp;
        printf("Digite o numero do contato\n");
        scanf("%llu", &temp);
        buscaPorNumero(temp);
    }
    else continue;
   
   }

    return 0;
}

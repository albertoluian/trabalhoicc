#include "list.c"
#include <stdlib.h>
int main()
{
    List = malloc(10*sizeof(struct Contato));
    int espaco = 10;
    int n = -1;
    printf("------------------------\nAgenda de contatos\n------------------------\n");
    while(n!=0){
    printf("Digite:\n1-Adicionar Contato\n2- Remover contato\n3-Listar contatos\n4-Pesquisar contato por nome\n5-Pesquisar contato por telefone\n0-Sair\n");
    scanf("%d", &n); getchar();
    if(n==1){
    printf("Digite em sequencia o nome, telefone, endereco, tipo de relacao e email\n");
    AddContact(leContato());
    }
    else if(n==2){
        printf("Digite o numero do contato a ser deletado\n");
        long long unsigned temp;
        scanf("%llu", &temp);
        DelContact(temp);
    }
    else if(n==3){
        listContact();
    }
    else if(n==4){
        char tempName[100];
        printf("Digite o nome do contato\n");
        fgets(tempName, 100, stdin);
        SearchByName(tempName);
    }
    else if(n==5){
        long long unsigned temp;
        printf("Digite o numero do contato\n");
        scanf("%llu", &temp);
        SearchByNumber(temp);
    }
   
   }
    return 0;
}

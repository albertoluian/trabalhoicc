#include "listMethods.c"
#include <stdlib.h>
int main()
{

    // struct Contato contato;

    // fgets(contato.nome, 101, stdin);
    // scanf("%llu", &contato.numero);
    // fgets(contato.endereco , 301,stdin);
    // fgets(contato.endereco , 301,stdin);
    // fgets(contato.relacao , 301,stdin);
    // fgets(contato.email , 301,stdin);
    
    // printContact(contato);


    Lista = malloc(400*sizeof(struct Contato));
    int espaco = 10;
    int n = -1;
    printf("------------------------\nAgenda de contatos\n------------------------\n");
    while(n!=0){
    printf("Digite:\n1-Adicionar Contato\n2- Remover contato\n3-Listar contatos\n4-Pesquisar contato por nome\n5-Pesquisar contato por telefone\n0-Sair\n");
    scanf("%d", &n); getchar();
    
    if(n==1) AddContato(criarContato());
    
    else if(n==2){
        printf("Digite o numero do contato a ser deletado\n");
        long long unsigned temp;
        scanf("%llu", &temp);
        DelContato(temp);
    }
    else if(n==3){
        listarContatos();
    }
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

    // struct Contato aux;
    // int n = 0;

    // while(n != 4)
    // {
    //     scanf("%d", &n);

    //     if(n == 0)
    //     {
    //         strcpy(aux.nome, "aa");
    //         aux.relacao = 1;
    //         AddContato(aux);
    //     }
    //     if(n == 1)
    //     {
    //         strcpy(aux.nome, "bb");
    //         aux.relacao = 1;
    //         AddContato(aux);
    //     }
    //     if(n == 2)
    //     {
    //         strcpy(aux.nome, "aa");
    //         aux.relacao = 2;
    //         AddContato(aux);
    //     }
    //     if(n == 3)
    //     {
    //         strcpy(aux.nome, "bb");
    //         aux.relacao = 2;
    //         AddContato(aux);
    //     }
    //     if(n == 4)
    //     {
    //         listarContatos();
    //     }
    // }

    return 0;
}

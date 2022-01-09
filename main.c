#include "listMethods.c"

int main()
{
    int espaco = 10;
    Lista = malloc(espaco * sizeof(struct Contato));
    
    int n = -1;
    printf("------------------------\nAgenda de contatos\n------------------------\n");
    while(n!=0)
    {
        
        printf("Digite:\n1-Adicionar Contato\n2- Remover contato\n3-Listar contatos\n4-Pesquisar contato por nome\n5-Pesquisar contato por telefone\n0-Sair\n");
        scanf("%d", &n); getchar();
        
        if(n==1)
        {
            if(len == espaco){
                Lista = realloc(Lista, (espaco+10)*sizeof(struct Contato));
                espaco +=10;
            }
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
            printf("Digite o nome do contato\n");
            char tempName[102];
            fgets(tempName, 102, stdin);
            tempName[strlen(tempName) - 1] = '\n';
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
    free(Lista);
    return 0;
}

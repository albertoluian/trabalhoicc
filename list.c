#include <stdio.h>
#include <string.h>
#include "cont.c"

int lenght = 0;

struct Contato *List;
struct Contato leContato(){
   struct Contato aux;
   printf("Digite o nome do contato\n");
   fgets(aux.nome, 100, stdin);
   printf("Digite o telefone\n");
   scanf("%llu", &aux.numero);
   printf("Digite o endereco\n");
   fgets(aux.endereco, 300, stdin);
   printf("tipo\n");
   fgets(aux.relacao, 300, stdin);
   printf("email\n");
   fgets(aux.email, 300, stdin);
   return aux;
}
void printContact(struct Contato item){
    printf("%s %llu %s %s %s", item.nome, item.numero, item.endereco, item.relacao, item.email);
}
void listContact(){
    for(int i=0; i<=lenght; i++)
    printContact(List[i]);
}
void AddContact( struct Contato item )
{
    List[lenght] = item;

    lenght ++; 
}

void DelContact( long long unsigned  number )
{
    int c, flag = 0;
    for(c = 0; c < lenght; c++)
    {
        if(List[c].numero == number)
        {
            flag = 1;
        } 
        if(flag == 1 && c != lenght - 1)
        {
            List[c] = List[c++];
        }
    }

    lenght--;
}

void SearchByName(char a[])
{

}

void SearchByNumber( long long unsigned number )
{
    int c, index = -1;
    for(c = 0; c < lenght; c++)
    {
        if(List[c].numero == number)
        {
            index = c;
            break;
        }
    }

    (index != -1) 
    ?
    ( printContact(List[index]) )
    :
    ( printf("O numero não foi anteriormente registrado") );

    
}
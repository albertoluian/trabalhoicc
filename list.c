#include <stdio.h>
#include <string.h>
#include "cont.c"

int lenght = 0;

struct Contato *List;

void printContact(struct Contato cont)
{   
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n  Nome: %s  Numero: %llu\n  Endereco: %s  Relacao: %s  Email: %s-=-=-=-=-=-=-=-=-=-=-=-=-=-=-", cont.nome, cont.numero, cont.endereco, cont.relacao, cont.email);
}

void AddContact( struct Contato item )
{
    List[lenght] = item;

    lenght ++; 
}

void DelContact( unsigned long long number )
{
    if(lenght <= 0 )
    {
        printf("A lista nao tem contatos");
    }
    else
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
                List[c] = List[c+1];
            }
        }

        lenght--;
    }

}

void SearchByName(char name[])
{
    int c = 0, flag = 0;
    char upperName[100];

    while(1 == 1)
    {
        if( 97 <= name[c] <= 122 )
            upperName[c] = (name[c] - 32);
        else
            upperName[c] = name[c];

        if( name[c] = '\0' ) break;
    }

    for(c = 0; c < lenght; c++)
    {
        if(strcmp( upperName , List[c].nome) == 0)
        {
            printContact(List[c]);
            flag = 1;
            return;
        }
    }

    // if(flag == 1)
    printf("Nome nao encontrado");
}

void SearchByNumber( unsigned long long number )
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

#include <stdio.h>
#include <string.h>
#include "cont.c"

int lenght = 0;

struct Contato *List;

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
    ( printf("O numero não foi anteriormente registrado") )

    
}
#include "structs.c"

int len = 0, lenRelacoes = 0;

struct Contato *Lista; // Lista onde serão salvos os contatos

int relacoes[15][2]; // representam, cada um dos arrays inseridos, a posição onde se encontra o primeiro e 
                                                                 // o ultimo + 1 elementos pertencentes a essa relacao

char Toupper(char nome)
{
        if(nome>='a' && nome<='z')
            nome += 'A' - 'a';
        return nome;
}

void printContato(struct Contato cont) // Função usada para printar um unico contato 
{   
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n  Nome: %s  Numero: %llu\n  Endereco: %s  Relacao: %s  N relacao: %d\n  Email: %s-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n", cont.nome, cont.numero, cont.endereco,cont.nomeRel ,cont.relacao, cont.email);
}

struct Contato criarContato() // Função que recebe os valores que constituem um contato e retorna o contato criado   
{
    struct Contato aux;
    printf("Digite o nome do contato\n");
    fgets(aux.nome, 102, stdin);
    aux.nome[strlen(aux.nome) - 1] = '\n';

    printf("Digite o endereco\n");
    fgets(aux.endereco, 302, stdin);
    aux.endereco[strlen(aux.endereco) - 1] = '\n';
   
    printf("email\n");
    fgets(aux.email, 302, stdin);
    aux.email[strlen(aux.email) - 1] = '\n';

    printf("Tipo de relacao:\n");
    int c;
    for(c = 0; c < lenRelacoes; c++)
    {
        printf("%d- %s", c+1, Lista[relacoes[c][0]].nomeRel);
    }

    if(lenRelacoes < 15)
        printf("%d- Nova relacao\n", lenRelacoes + 1);
    
    scanf("%d", &aux.relacao);
    
    if(aux.relacao == 15 && lenRelacoes == 15)
        aux.relacao = 17;
    
    while(1 > aux.relacao || aux.relacao > lenRelacoes + 1)
    {
        printf("!POR FAVOR DIGITE CORRETAMENTE!\n");
        for(c = 0; c < lenRelacoes; c++)
        {
            printf("%d- %s", c+1, Lista[relacoes[c][0]].nomeRel);
        }
        if(lenRelacoes < 15)
            printf("%d- Nova relacao\n", lenRelacoes + 1);
        scanf("%d", &aux.relacao);
    }

    if(aux.relacao == lenRelacoes + 1)
    {
        printf("Insira o nome da relacao:\n");
        getchar();
        fgets(aux.nomeRel, 102, stdin);
        aux.nomeRel[strlen(aux.nomeRel) - 1] = '\n';
    }
    else
        strcpy(aux.nomeRel, Lista[relacoes[aux.relacao-1][0]].nomeRel);
    
   
    printf("Digite o telefone\n");
    scanf("%llu", &aux.numero);
    int existenciaNumero = 0;
    while(existenciaNumero != 2){
        if(existenciaNumero != 0){
            printf("Digite um numero nao cadastrado anteriormente\n");
            scanf("%llu", &aux.numero);
        }
        existenciaNumero = 2;
        for(c = 0; c<len; c++)
        if(Lista[c].numero == aux.numero){
          existenciaNumero = 1;
          break;
        }
    }

    // A seguir são postos os valores das 3 strings presentes em um contato de forma maiuscula 

    int soma = 0;

    int bool[3] = {0,0,0};
    c = 0;

    while(soma < 3)
    {
        if(bool[0] == 0)
        {
            aux.endereco[c] = Toupper(aux.endereco[c]);
            if(aux.endereco[c+1] == '\n')
            {
                soma++;
                bool[0] = 1;
            }
        }
        if(bool[1] == 0)
        {
            aux.nome[c] = Toupper(aux.nome[c]);
            if(aux.nome[c+1] == '\n')
            {
                soma++;
                bool[1] = 1;
            }            
        }
        if(bool[2] == 0)
        {
            aux.nomeRel[c] = Toupper(aux.nomeRel[c]);
            if(aux.nomeRel[c+1] == '\n')
            {
                soma++;
                bool[2] = 1;
            }
        }
        c++;
    }

   return aux;
}

void listarContatos() // Função que lista todos os contatos presentes no array "Lista"
{
    int i;
    for(i=0; i < len; i++)
        printContato(Lista[i]);
}

void AddContato( struct Contato cont ) // Recebe um contato e o adiciona de acordo com o numero da relação desse contato e a ordem alfabetica
{

    int relIndex = cont.relacao - 1; // Representa o index no array "relacoes" que será usadp

    int c; // Variavel usada para fazer todos os loops
    if(relIndex == lenRelacoes)
    {
        if(lenRelacoes == 0)
        {
            relacoes[0][0] = 0;
            relacoes[0][1] = 0;
        }
        else
        {
            relacoes[relIndex][0] = relacoes[relIndex -1][1];
            relacoes[relIndex][1] = relacoes[relIndex -1][1];
        }

        lenRelacoes++;
    }

    if(relacoes[relIndex][0] == relacoes[relIndex][1]) // Caso os dois valores sejam iguais a relação de index mostrado não tem 
                                                       // nenhum elemento, assim o processo é feito de forma mais simples
    {
        Lista[relacoes[relIndex][1]] = cont;
        relacoes[relIndex][1]++;
    }
    else
    {
        struct Contato aux1, aux2; // Para salvamento do elemento existe a chance de ser preciso deslocar uma casa a frente todos
                                   // os elementos com index superior ao que será inserido o elemento em questão, assim, "aux1" receberá
                                   // o valor do elemento que será substituido pelo anterior e "aux2" salvará o elemento antigo no atual
        
        int listaIndex; // Para "pular uma casa" para todos os elementos será feito um loop e essa variavel representa o valor no qual essa 
                        // mudança iniciará, representando o index onde deve ser salvo o elemento inserido na função + 1
        
        aux2 = Lista[relacoes[relIndex][1]]; // Caso não passe na verificação do for a seguir são postos valores que consideram o salvamento 
                                             // do elemento inserido na função como o ultimo da relação

        listaIndex = relacoes[relIndex][1] + 1;

        for(c = relacoes[relIndex][0]; c < relacoes[relIndex][1]; c++) // Verifica se existe um nome de contato de prioridade menor ou igual 
                                                                       // ao inserido na função de acordo com a ordem alfabetica
        {
            if( 0 <= strcmp(Lista[c].nome, cont.nome))
            {
                aux2 = Lista[c];
                
                listaIndex = c + 1;
                break;
            }
        }

        relacoes[relIndex][1]++;

        for(c = listaIndex; c <= len; c++) // São postos todos os elementos que vem depois do inserido na função uma casa a cima 
        {
            if(c != len)
                aux1 = Lista[c];
            Lista[c] = aux2;
            aux2 = aux1;
        }
        Lista[listaIndex - 1] = cont;
    }

    for(c = relIndex + 1; c < lenRelacoes; c++) // Padroniza os valores das relação seguintes ja que existe um elemento a mais dentro da "Lista"
    {
        relacoes[c][1]++;
        relacoes[c][0]++;
    }

    
    
    len ++; // O comprimento da Lista é incrementado
}

void DelContato( unsigned long long numero ) // Deleta o contato com numero igual ao inserido na função
{
    if(len <= 0 )
        printf("A lista nao tem contatos");
    
    else
    {
        int c, flag = 0, relIndex, excluirRel = 0;
        for(c = 0; c < len; c++)
        {
            if(Lista[c].numero == numero){ // Verifica se o valor desse numero existe ou não
                flag = 1;
              if (c == relacoes[Lista[c].relacao-1][0] && relacoes[Lista[c].relacao-1][1] == relacoes[Lista[c].relacao-1][0]+1)
                excluirRel = 1;
            
                relIndex =  Lista[c].relacao - 1;
            }
            if(flag == 1 && c != len - 1) // Caso exista salva o valor a frente em cima desse e assim por sequencia
                Lista[c] = Lista[c+1];
        }

        if(flag == 0)
        {
            printf("Contato nao encontrado");
        }
        else
        {
            for(c = relIndex; c < lenRelacoes; c++) // Padroniza os valores das relação seguintes ja que existe um elemento a menos dentro da "Lista"
            {
                if(c != relIndex)
                    relacoes[c][0]--;
                relacoes[c][1]--;
            
            

            }
           if(excluirRel == 1){
               for(c = relIndex; c<lenRelacoes-1; c++){
                   relacoes[c][0] = relacoes[c+1][0];
                   relacoes[c][1] = relacoes[c+1][1];
               }     
               for(c = relIndex; c<len-1; c++){
                   Lista[c].relacao -=1;
               }
               
               lenRelacoes--;
           }

            len--;
            
        }
    }

}

void buscaPorNome(char nome[]) // Busca um elemento pelo nome
{
    int c = 0, flag = 0, size = strlen(nome);

    for(c = 0; c < size - 1; c++)
    {
        nome[c] = Toupper(nome[c]);
    }

    printf("%s", nome);

    for(c = 0; c < len; c++)
    {
        if(strcmp( nome , Lista[c].nome) == 0) // Verifica se um contato com tal nome existe
        {
            printContato(Lista[c]);
            flag = 1;
            break;
        }
    }

    if(flag == 0) // Caso não seja encontrado o elemento
        printf("Nome nao encontrado\n");
}

void buscaPorNumero( unsigned long long numero ) // Busca um elemento pelo numero
{
    int c, flag = 0;
    for(c = 0; c < len; c++)
    {
        if(Lista[c].numero == numero) // Verifica se um contato com tal numero existe
        {
            flag = 1;
            printContato(Lista[c]);
            break;
        }
    }

    if(flag == 0) // Caso não seja encontrado o elemento
        printf("O numero nao foi anteriormente registrado");

    
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stddef.h>
#include <locale.h>
#include <ctype.h>

#define TAM 10

int opcao = 0, i = 0;

struct cliente{
    char nome[50];
    int anoNascimento;
    float montante;
};

typedef struct cliente cliente;

cliente lista[TAM];

void menu(){
    system("cls");
    do{
        printf("\n-----------------------------CADASTRO DE CLIENTES-------------------------------");
        printf("\n[ 1 ] - Incluir um novo cliente: ");
        printf("\n[ 2 ] - Atualizar o montante de compras do cliente realizadas no m�s corrente");
        printf("\n[ 3 ] - Zerar todos os montantes de compras por ocasi�o da virada de m�s");
        printf("\n[ 4 ] - Exibir um montante de compras de um cliente espec�fico");
        printf("\n[ 5 ] - Listar clientes");
        printf("\n[ 6 ] - Sair");
        printf("\nOp��o: ");
        scanf("%d", &opcao);
        printf("----------------------------------------------------------------------------------");
        switch(opcao){
            case 1:
                inclusaoCliente();
                break;
            case 2:
                printf("Atualiza�ao");
                break;
            case 3:
                printf("Zerar todos os montantes");
                break;
            case 4:
                //printf("Exibir um montante de compras de um cliente espec�fico\n");
                montanteCliente();
                break;
            case 5:
                listarClientes();
                break;
        }
    }while(opcao != 6);
}

void inclusaoCliente(){
    char cadastrar = 'E';
    printf("\nInclus�o de Clientes: \n");
    do{
        printf("Dados do %d cliente: \n",i+1);
        printf("Nome: ");
        scanf("%s", &lista[i].nome);
        //lista[i].nome = strupr(lista[i].nome);
        printf("Ano Nascimento: ");
        scanf("%d", &lista[i].anoNascimento);
        printf("Montante em R$");
        scanf("%f", &lista[i].montante);
        fflush(stdin);
        i++;
        printf("Cadastrar outro cliente S / N? ");
        scanf("%c", &cadastrar);
        cadastrar = toupper(cadastrar);
        if(cadastrar == 'N'){
            break;
        }
        if( i >= 10){
            printf("Todo clientes j� inclu�dos");
        }
    }while(i < TAM || cadastrar != 'S');
}

void montanteCliente(){
    float soma = 0.0;
    char procuraNome[40];
    printf("\nInforme o nome para procurar montante: ");
    scanf("%s", &procuraNome);
    //procuraNome = strupr(procuraNome);
    //nome = toupper(nome);
    //opcao = toupper(opcao);
    //procuraNome = toupper(procuraNome);
    for(int i = 0; i < 10;i++){
        if(!strcmp(lista[i].nome,procuraNome)){
            soma += lista[i].montante;
        }else{
            printf("Cliente n�o encontrado");
            break;
        }
    }
    printf("\nValor total do montante R$%.2f", soma);
}

listarClientes(){
    printf("\n");
    for(int i = 0; i < TAM;i++){
        printf("Nome: %s\tAno Nascimento %d\tMontante R$%.2f\n", lista[i].nome, lista[i].anoNascimento, lista[i].montante);
    }

}

int main()
{
    //system("cls");
        setlocale(LC_ALL, "Portuguese");
        menu();
        //printf("\nOp��o: ");
        //scanf("%d", &opcao);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stddef.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>

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
        printf("\n[ 1 ] - Incluir um novo cliente ");
        printf("\n[ 2 ] - Atualizar o montante de compras do cliente realizadas no mês corrente");
        printf("\n[ 3 ] - Zerar todos os montantes de compras por ocasião da virada de mês");
        printf("\n[ 4 ] - Exibir um montante de compras de um cliente específico");
        printf("\n[ 5 ] - Listar clientes");
        printf("\n[ 6 ] - Informar melhor comprador");
        printf("\n[ 7 ] - Sair\n");
        printf("----------------------------------------------------------------------------------\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        printf("----------------------------------------------------------------------------------");
        switch(opcao){
            case 1:
                inclusaoCliente();
                break;
            case 2:
                printf("Remover cliente especifico");
                break;
            case 3:
                apagarMontate();
                break;
            case 4:
                //printf("Exibir um montante de compras de um cliente específico\n");
                montanteCliente();
                break;
            case 5:
                listarClientes();
                break;
            case 6:
                printf("Melhor comprador");
                break;
        }
    }while(opcao != 7);
}

void inclusaoCliente(){
    char cadastrar = 'E';
    printf("\nInclusão de Clientes: \n");
    do{
        system("cls");
        printf("Dados do %do cliente: \n",i+1);
        printf("Nome: ");
        scanf("%s", &lista[i].nome);
        //lista[i].nome = strupr(&lista[i].nome);
        //lista[i].nome = toupper(lista[i].nome);
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
            system("cls");
            break;
        }
        if( i >= 10){
            printf("Todo clientes já incluídos");
        }
    }while(i < TAM || cadastrar != 'S');
}

void montanteCliente(){
    system("cls");
    float soma = 0.0;
    char procuraNome[40];
    printf("\nInforme o nome para procurar montante: ");
    scanf("%s", &procuraNome);
    //procuraNome = toupper(procuraNome);
    for(int i = 0; i < TAM;i++){
        if(!strcmp(procuraNome, lista[i].nome)){
            soma += lista[i].montante;
        }
    }
    printf("\nValor total do montante R$%.2f", soma);
}

listarClientes(){
    system("cls");
    printf("\n");
    for(int i = 0; i < TAM;i++){
        printf("Nome: %s\tAno Nascimento: %d\tMontante: R$%.2f\n", lista[i].nome, lista[i].anoNascimento, lista[i].montante);
    }
}

apagarMontate(){
    system("cls");
    char zerar;
    fflush(stdin);
    printf("Deseja zerar todos os montantes [S/N]");
    scanf("%c", &zerar);
    zerar = toupper(zerar);
    if(zerar == 'S' || zerar == 's'){
        for(int i = 0; i < TAM; i++){
            lista[i].montante = 0.0;
        }
    }else{
        printf("Nao havera exclusão");
    }
}

int main()
{
    //system("cls");
        setlocale(LC_ALL, "Portuguese");
        menu();
        //printf("\nOpção: ");
        //scanf("%d", &opcao);
    return 0;
}

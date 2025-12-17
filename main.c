#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Pessoa{
    char nome [50];
    int idade;
};

void criarPessoa(int* numeroDePessoas, struct Pessoa* pessoa){

    printf("\nQual o nome dessa pessoa? ");
    char nome[50];
    scanf(" %49[^\n]", &nome);

    printf("\nQual a idade dessa pessoa? ");
    int idade = 0;
    scanf("%d", &idade);

    strcpy((*pessoa).nome, nome);
    (*pessoa).idade = idade;
    (*numeroDePessoas) += 1;
}

void listarPessoas(int numeroDePessoas, struct Pessoa* pessoa){

    if(numeroDePessoas==0){
        printf("\nNao existem usuarios ainda...");
    }else{
        for(int i = 0; i<= numeroDePessoas-1; i++){
            printf("\n*********************");
            printf("\nPessoa %d: ", i+1);
            printf("\n\nNome: %s", pessoa[i].nome);
            printf("\nIdade: %d", pessoa[i].idade);
            printf("\n*********************\n");
        }
    }
}

int main(){

    int terminou = 0;
    int numeroDePessoas = 0;
    int escolha = 0;
    struct Pessoa pessoa[50];

    
    
    while(terminou != 1){
        printf("\nVoce quer criar um usuario (1), listar os usuarios existentes (2) ou sair do programa (3)?");
        scanf("%d", &escolha);

        switch (escolha){
            case 1:
                criarPessoa(&numeroDePessoas, &pessoa[numeroDePessoas]);
                break;
            case 2:
                listarPessoas(numeroDePessoas, pessoa);
                break;
            case 3:
                printf("\nAdeus...");
                exit(0);
                break;
            default:
                printf("\nIsso nao e uma opcao correta...");
                exit(1);
                break;
        }
        
    }
    
    return 0;
}

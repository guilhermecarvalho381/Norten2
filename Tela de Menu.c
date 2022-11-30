#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caminhos.h"

#define SIZE 200 //Definindo no programa inteiro o numero de linhas SIZE 200
int opcao;

//Funcao Menu
void TelaMenu(){

do{
        system("cls");
        printf("----Menu----\n");
        printf("1- Cadastrar Aluno\n2- Listar Alunos\n3- Cadastrar Professor\n4- Listar Professor\n5- Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
            switch(opcao){
                case 1:
                    CadastrarAluno();
                break;

                case 2:
                    ListarAluno();
                break;

                case 3:
                    CadastrarProf();
                break;

                case 4:
                    ListarProf();
                break;

                case 5:
                    system("cls");
                    MenuDoMenu();
                break;

                default:
                    printf("Opcao Invalida!");
                    getchar();
                    getchar();
                break;
            }
    }while(opcao!=5);
}

//TELA MENU ADM
void TelaMenuADM(){

do{
        system("cls");
        printf("----Menu Administrador NORTEN----\n");
        printf("1- Cadastrar Funcionario\n2- Listar Funcionarios\n3- Cadastrar Usuario\n4- Listar Aluno\n5- Listar Professores\n6- Sair\n");
        printf("Digite sua opcao: ");
        scanf("%d", &opcao);
            switch(opcao){
                case 1:
                    CadastrarFunc();
                break;

                case 2:
                    ListarFuncionario();
                break;

                case 3:
                    cadastrar();
                break;

                case 4:
                    ListarAluno();
                break;

                case 5:
                    ListarProf();
                break;

                  case 6:
                    system("cls");
                    MenuDoMenu();
                break;
                default:
                    printf("Opcao Invalida!");
                    getchar();
                    getchar();
                break;
            }
    }while(opcao!=6);
}


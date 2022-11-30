#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caminhos.h"

#define SIZE 20

int opcao;
//Funções antes da main

//Funcoes de TelaLogin.c
void TelaLogin();
void ListarProf();

void cadastrarADM();
int TelaLoginADM();

//TelaCadastroProf.c
void CadastrarProf();
void ListarProf();

//TelaCadastroCliente.c
void CadastrarAluno();
void CadastrarAluno();

//Tela de Menu.c
void TelaMenu();
void TelaMenuADM();

int main(int argc, char *argv[])
{
    MenuDoMenu();
}

  void MenuDoMenu(){
    printf("---Bem vindo a Norten, escolha seu tipo de Login-----\n");
    printf("Administrador, digite 1\nFuncionario, digite 2\n");
    printf("\nDigite sua opcao:");
        scanf("%d", &opcao);
            switch(opcao){
                case 1:
                    system("cls");
                     TelaLoginADM();
                break;

                case 2:
                    system("cls");
                    TelaLogin();
                break;
                default:
                    printf("Opcao Invalida!");
                    getchar();
                    getchar();
                    system("cls");
                    MenuDoMenu();
                break;
            }while(opcao!=2);
    }


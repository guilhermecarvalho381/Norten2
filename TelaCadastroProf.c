#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caminhos.h"
/*

   [!] Neste Arquivo contém o cadastro de Clientes(Professor e Listagem do mesmo) [!]

*/

//Declarando Struct
typedef struct Professor CadastroP;

typedef struct Professor{
    char p_CPF[16];
    char p_nome[100];
    char p_endereco[100];
    char p_idade[3];
    char p_genero[100];
    char p_curso[100];
    char p_email[100];
    char p_telefone[100];
};


//Declarar variavel
int opcao;
FILE *fp;
FILE *fpb;

void CadastrarProf(){
	CadastroP prof;
	//Para o programa ler
    fp = fopen("ProfCad.txt", "a");

    //para funcionario ler
    fpb = fopen("ProfTradCad.txt", "a");
    if(fp == NULL)
    {
      perror("[!] Problemas com o arquivo AlunoCad.txt");
    }else
    {
        do{
    system("cls");
	printf("---Cadastro de Professor---\n");

    fflush(stdin);
    printf("Digite o NOME: \n");
    gets(&prof.p_nome);

	fflush(stdin);
    printf("Digite o CPF: \n");
    gets(&prof.p_CPF);

    fflush(stdin);
    printf("Digite o EMAIL: \n");
    gets(&prof.p_email);

    fflush(stdin);
    printf("Digite o TELEFONE: \n");
    gets(&prof.p_telefone);

    fflush(stdin);
    printf("Digite o ENDERECO COMPLETO: \n");
    gets(&prof.p_endereco);

    fflush(stdin);
    printf("Digite a IDADE: \n");
    gets(&prof.p_idade);

    fflush(stdin);
    printf("Digite o GENERO: \n");
    gets(&prof.p_genero);

    fflush(stdin);
    printf("Digite o CURSO LECIONADO : \n");
    gets(&prof.p_curso);

    //Preparando Texto com informacoes
    fprintf(fpb, "\n----Cadastro do Professor, %s, Curso: %s------", prof.p_nome, prof.p_curso);
    fprintf(fpb, "\nNome:%s", prof.p_nome);
    fprintf(fpb, "\nCPF:%s", prof.p_CPF);
    fprintf(fpb, "\nEmail:%s", prof.p_email);
    fprintf(fpb, "\nTelefone:%s", prof.p_telefone);
    fprintf(fpb, "\nEndereco:%s", prof.p_endereco);
    fprintf(fpb, "\nGenero:%s", prof.p_genero);
    fprintf(fpb, "\nIdade:%s", prof.p_idade);
    fprintf(fpb, "\nCurso Selecionado:%s", prof.p_curso);

	//Fim cadastro

        //Inicio salvar informações
		fwrite(&prof, sizeof(CadastroP), 1, fp);
        printf("Deseja cadastrar mais Professores(S/N)?");
        getch();

            }while(opcao == 'S' || opcao== 's');
    fclose(fp);
    fclose(fpb);
    }
        TelaMenu();
	}


//Funcao Listando Professores
void ListarProf(){

    CadastroP prof;
        fp = fopen("ProfCad.txt", "rb");
        if(fp == NULL)
        {
      perror("[!] Problemas com o arquivo ProfCad.txt");
        }
        else{
            system("cls");
            printf("---------- Lista de Professores-----------\n");

             while(fread(&prof, sizeof(CadastroP), 1, fp)==1){
                printf("\nNome:%s", prof.p_nome);
                printf("\nCPF:%s", prof.p_CPF);
                printf("\nIdade:%s", prof.p_idade);
                printf("\nGenero:%s", prof.p_genero);
                printf("\nEmail:%s", prof.p_email);
                printf("\nTelefone:%s", prof.p_telefone);
                printf("\nEndereco:%s", prof.p_endereco);
                printf("\nCurso Lecionado:%s", prof.p_curso);
                printf("\n#=========================#\n");
             }
             printf("Pressione ENTER para continuar...");
        }
        fclose(fp);
        getch();
        TelaMenu();
}

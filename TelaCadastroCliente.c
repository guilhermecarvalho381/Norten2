#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caminhos.h"
/*

   [!] Neste Arquivo contém o cadastro de Clientes(Alunos e Listagem do mesmo [!]

*/

//Declarando Struct
typedef struct Aluno Cadastro;

typedef struct Aluno{
    char a_CPF[16];
    char a_nome[100];
    char a_endereco[100];
    char a_idade[3];
    char a_genero[100];
    char a_curso[100];
    char a_email[100];
    char a_telefone[100];
};


//Declarar variavel
int opcao;
FILE *fp;
FILE *fpb;

void CadastrarAluno(){
	Cadastro aluno;
	//Para o programa ler
    fp = fopen("AlunoCad.txt", "a");

    //para funcionarioler
    fpb = fopen("AlunoTradCad.txt", "a");
    if(fp == NULL)
    {
      perror("[!] Problemas com o arquivo AlunoCad.txt");
    }else
    {
        do{
    system("cls");
	printf("--Cadastro de Alunos----\n");

    fflush(stdin);
    printf("Digite o NOME: \n");
    gets(&aluno.a_nome);

	fflush(stdin);
    printf("Digite o CPF: \n");
    gets(&aluno.a_CPF);

    fflush(stdin);
    printf("Digite o EMAIL: \n");
    gets(&aluno.a_email);

    fflush(stdin);
    printf("Digite o TELEFONE: \n");
    gets(&aluno.a_telefone);

    fflush(stdin);
    printf("Digite o ENDERECO COMPLETO: \n");
    gets(&aluno.a_endereco);

    fflush(stdin);
    printf("Digite a IDADE: \n");
    gets(&aluno.a_idade);

    fflush(stdin);
    printf("Digite o GENERO: \n");
    gets(&aluno.a_genero);

    fflush(stdin);
    printf("Digite o CURSO SELECIONADO: \n");
    gets(&aluno.a_curso);

    //Preparando Texto com informacoes
    fprintf(fpb, "\n----Cadastro do Aluno, %s, Cpf: %s------", aluno.a_nome, aluno.a_CPF);
    fprintf(fpb, "\nNome:%s", aluno.a_nome);
    fprintf(fpb, "\nCPF:%s", aluno.a_CPF);
    fprintf(fpb, "\nEmail:%s", aluno.a_email);
    fprintf(fpb, "\nTelefone:%s", aluno.a_telefone);
    fprintf(fpb, "\nEndereco:%s", aluno.a_endereco);
    fprintf(fpb, "\nGenero:%s", aluno.a_genero);
    fprintf(fpb, "\nIdade:%s", aluno.a_idade);
    fprintf(fpb, "\nCurso Selecionado:%s", aluno.a_curso);

	//Fim cadastro

        //Inicio salvar informações
		fwrite(&aluno, sizeof(Cadastro), 1, fp);
        printf("Deseja cadastrar mais Alunos(S/N)?");
        getch();

            }while(opcao == 'S' || opcao== 's');
    fclose(fp);
    fclose(fpb);
    }
        TelaMenu();
	}


//Funcao Listando Alunos
void ListarAluno(){

    Cadastro aluno;
        fp = fopen("AlunoCad.txt", "rb+");
        if(fp == NULL)
        {
      perror("[!] Problemas com o arquivo AlunoCad.txt");
        }
        else{
            system("cls");
            printf("---------- Lista de Alunos-----------\n");

             while(fread(&aluno, sizeof(Cadastro), 1, fp)==1){
                printf("\nNome:%s",aluno.a_nome);
                printf("\nCPF:%s",aluno.a_CPF);
                printf("\nIdade:%s",aluno.a_idade);
                printf("\nGenero:%s",aluno.a_genero);
                printf("\nEmail:%s",aluno.a_email);
                printf("\nTelefone:%s",aluno.a_telefone);
                printf("\nEndereco:%s",aluno.a_endereco);
                printf("\nCurso:%s",aluno.a_curso);
                printf("\n#=========================#\n");
             }
             printf("Pressione ENTER para continuar...");
        }
        fclose(fp);
        getch();
        TelaMenu();
}

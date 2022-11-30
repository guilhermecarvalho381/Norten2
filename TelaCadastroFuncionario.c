#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caminhos.h"
/*

   [!] Neste Arquivo contém o cadastro de Funcionarios e Listagem do mesmo [!]

*/

//Declarando Struct
typedef struct funcionario Cadastro;
struct funcionario{
    int ID;
    char fnome [50];
    char fcpf [50];
    char femail[50];
    char ftelefone [50];
    char fendereco [100];
};


//Declarar variavel
int opcao;
FILE *fp;
FILE *fpb;

void CadastrarFunc(){
	Cadastro func;
	//Para o programa ler
    fp = fopen("funcionario.txt", "a");

    //para funcionarioler
    fpb = fopen("functraduc.txt", "a");
    if(fp == NULL)
    {
      perror("[!] Problemas com o arquivo cliente.txt");
    }else
    {
        do{
    system("cls");
	printf("--Cadastro de Funcionarios----\n");

	 fflush(stdin);
    printf("Digite o NOME: \n");
    gets(&func.fnome);

	fflush(stdin);
    printf("Digite o CPF: \n");
    gets(&func.fcpf);

    fflush(stdin);
    printf("Digite o EMAIL: \n");
    gets(&func.femail);

    fflush(stdin);
    printf("Digite o TELEFONE: \n");
    gets(&func.ftelefone);

    fflush(stdin);
    printf("Digite o ENDERECO COMPLETO: \n");
    gets(&func.fendereco);

    //Preparando Texto com informacoes
    fprintf(fpb, "\n----Cadastro do Funcionario, %s------", func.fnome);
    fprintf(fpb, "\nNome:%s", func.fnome);
    fprintf(fpb, "\nCPF:%s", func.fcpf);
    fprintf(fpb, "\nEmail:%s", func.femail);
    fprintf(fpb, "\nTelefone:%s", func.ftelefone);
    fprintf(fpb, "\nEndereco:%s\n", func.fendereco);

	//Fim cadastro

        //Inicio salvar informações
		fwrite(&func, sizeof(Cadastro), 1, fp);
        printf("Deseja cadastrar mais Funcionarios(S/N)?");
        getch();

            }while(opcao == 'S' || opcao== 's');
    fclose(fp);
    fclose(fpb);
    }
        TelaMenu();
	}


//Funcao Listando Funcionario
void ListarFuncionario(){

    Cadastro func;
        fp = fopen("funcionario.txt", "rb");
        if(fp == NULL)
        {
      perror("[!] Problemas com o arquivo funcionario.txt");
        }
        else{
            system("cls");
            printf("---------- Lista de Funcionario-----------\n");

             while(fread(&func, sizeof(Cadastro), 1, fp)==1){
                printf("\nNome:%s",func.fnome);
                printf("\nCPF:%s",func.fcpf);
                printf("\nEmail:%s",func.femail);
                printf("\nTelefone:%s", func.ftelefone);
                printf("\nEndereco:%s",func.fendereco);
                printf("\n#=========================#\n");
             }
             printf("Pressione ENTER para continuar...");
        }
        fclose(fp);
        getch();
        TelaMenuADM();
}


/*
//Função Pesquisa
void PesquisaFunc()
{

    char* cpfPesquisa;
    char c;
    char emailPesquisa[50];
    int i; //Linhas

     Cadastro func;
        fp = fopen("funcionario.txt", "r");
        if(fp == NULL)
        {
      perror("[!] Problemas com o arquivo funcionario.txt");
        }
        else{

    while((c = fgetc(fp)) != EOF){

        if(c == cpfPesquisa){
            for(i = 0; i < strlen(cpfPesquisa); i++){
                c = fgetc(fp);
                if( c == EOF)
                    break;
                if(*(cpfPesquisa+i) != c)
                    break;
            }
            if (i == strlen(cpfPesquisa)){
                break;
            }
        }
    }
    fclose(fp);

}

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LOGIN_MAX	64
#define SENHA_MAX	32

struct usuario_t {
	char login[64];
	char senha[32];
};


struct usuarioadm_t {
	char loginadm[64];
	char senhaadm[32];
};

void cadastrar()
{
	FILE *fp;
	struct usuario_t usuario;
	memset(&usuario, 0, sizeof(struct usuario_t));

	printf("----Cadastro de USUARIO---- \n");
	printf("Digite seu Usuario: ");
	scanf("%s", &usuario.login);
	printf("Digite sua senha: ");
	scanf("%s", &usuario.senha);

	fp = fopen("login", "wb");
	if (!fp) {
		printf("N�o foi poss�vel criar o arquivo de login");
		return;
	}
	fwrite(&usuario, sizeof(struct usuario_t), 1, fp);
	fclose(fp);
}

int TelaLogin()
{
    FILE *fp;
	struct usuario_t usuario;
	//LOGIN COMUM
	fp = fopen("login", "rb");
	if (!fp) {
		cadastrar();
		fp = fopen("login", "rb");
		if (!fp) {
		    printf("N�o foi possivel encontrar o arquivo de login\n");
		    return 0;
		}
	}
        memset(&usuario, 0, sizeof(struct usuario_t));

        fread(&usuario, sizeof(struct usuario_t), 1, fp);
        fclose(fp);

        int tentativas = 0;
            do {
			char login[LOGIN_MAX];
			char senha[SENHA_MAX];

			printf("Login: ");
			scanf("%s", &login);
			printf("Senha: ");
			scanf("%s", &senha);
			if (!strcmp(login, usuario.login) && !strcmp(senha, usuario.senha)) {
				printf("Bem vindo %s\n", usuario.login);
                TelaMenu();
			}else {
				printf("Usuario ou senha invalidos!\n");
				tentativas++;
			}
		} while (tentativas < 3);
		printf("Numero maximo de tentativas alcancado!\n");
		system("cls");
		MenuDoMenu();
}

//[!] BLOCO DE ADMNISTRADOR [!]
//[!] Cadastro de Usuario de ADM [!]
void cadastrarADM()
{
	FILE *fp;
	struct usuarioadm_t usuarioadm;
	memset(&usuarioadm, 0, sizeof(struct usuarioadm_t));

	printf("----Cadastro de ADMNISTRADOR---- \n");
	printf("Digite seu Usuario: ");
	scanf("%s", &usuarioadm.loginadm);
	printf("Digite sua senha: ");
	scanf("%s", &usuarioadm.senhaadm);

	fp = fopen("loginADM", "wb");
	if (!fp) {
		printf("Nao foi possivel criar o arquivo de login");
		return;
	}
	fwrite(&usuarioadm, sizeof(struct usuarioadm_t), 1, fp);
	fclose(fp);
}

// Tela Login de ADM
int TelaLoginADM()
{
    FILE *fp;
	struct usuarioadm_t usuarioadm;
	//LOGIN COMUM
	fp = fopen("loginADM", "rb");
	if (!fp) {
		cadastrar();
		fp = fopen("loginADM", "rb");
		if (!fp) {
		    printf("Nao foi possivel encontrar o arquivo de login\n");
		    return 0;
		}
	}
        memset(&usuarioadm, 0, sizeof(struct usuarioadm_t));

        fread(&usuarioadm, sizeof(struct usuarioadm_t), 1, fp);
        fclose(fp);

        int tentativas = 0;
            do {
			char loginadm[LOGIN_MAX];
			char senhaadm[SENHA_MAX];

			printf("Login ADM: ");
			scanf("%s", &loginadm);
			printf("SenhaADM: ");
			scanf("%s", &senhaadm);
			if (!strcmp(loginadm, usuarioadm.loginadm) && !strcmp(senhaadm, usuarioadm.senhaadm)) {
				printf("Bem vindo %s\n", usuarioadm.loginadm);
				TelaMenuADM();

			}else {
				printf("Usuario ou senha invalidos!\n");
				tentativas++;

			}
		} while (tentativas < 1);
		printf("Numero maximo de tentativas alcancado!\n");
        system("cls");
        MenuDoMenu();
}


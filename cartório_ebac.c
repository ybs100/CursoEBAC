#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <locale.h>// Biblioteca de aloca��o de texto por regi�o
#include <stdlib.h>// Biblioteca de aloca��o de espa�o em mem�ria
#include <string.h>// Biblioteca respons�vel por cuidar da string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	
	printf("Digite o CPF a ser registrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
	FILE *file; 
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file, cpf); // salva o valor da vari�el
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, "-");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "-");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, "-");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ".");
	fclose(file);
	
	char opcao[5];
	printf("\nDeseja inserir outro CPF? (S/N)");
	scanf("%s", opcao);
	if(scanf("%S" ) == 2)
	printf("yc");
	
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nN�o foi poss�vel localizar o usu�rio.\n\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es encontradas: ");
		printf("%s", conteudo);
		printf("\n\n");

	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	
	if(remove(cpf) == 0)
	{
		printf("\nUsu�rio deletado com sucesso.\n");
		remove(cpf);
		system("pause");
	}
	
	else
	{
		printf("\nUsu�rio n�o encontrado.\n");
		system("pause");
 	}
}


int main()
{
	int opcao=0;
	int x=1;
	
	for(x=1;x=1;)
	{
	
		system("cls");

		setlocale(LC_ALL, "portuguese");

		printf("\t Cart�rio EBAC\n\n"); 
		printf("   Selecione a op��o desejada.\n\n");
		printf("      1 - Registrar nomes\n"); 
		printf("      2 - Consultar nomes\n");
		printf("      3 - Deletar nomes\n");
		printf("      4 - sair do sistema\n");
		printf("\n   Op��o:");
	
		if(scanf("%d", &opcao) != 1)
		{
			while(getchar() !='\n');
			system("cls");
			printf("Op��o inv�lida, tente novamente.\n\n");
			system("pause");
			continue; 
		}
	
		system("cls"); //Respons�el por limpar a tela
	
		switch(opcao)
		{
			case 1:
			registro(); //chamada de fun��o
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema!");
			return 0;
			break;	
			
			case 5:
			default:
			printf("Op��o inv�lida\n");
			system("pause");
		}
	
	}	
}
	

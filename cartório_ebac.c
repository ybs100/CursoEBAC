#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <locale.h>// Biblioteca de alocação de texto por região
#include <stdlib.h>// Biblioteca de alocação de espaço em memória
#include <string.h>// Biblioteca responsável por cuidar da string

int registro()
{
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char opcao[5];
	
	do {
	
		printf("Digite o CPF a ser registrado: ");
		scanf("%s", cpf);
		
		strcpy(arquivo, cpf); //responsável por copiar os valores das string
		
		FILE *file; 
		file = fopen(arquivo, "w"); //cria o arquivo
		fprintf(file, cpf); // salva o valor da variáel
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
		
		printf("\nDeseja inserir outro CPF? (S/N)");
		scanf("%s", opcao);
		
	}while(opcao[0] == 'S');
}

int consulta()
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	char conteudo[200];
	char opcao[1];
	
	do{
		printf("Digite o CPF a ser consultado: ");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("\nNão foi possível localizar o usuário.\n\n");		
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("\nEssas são as informações encontradas: ");
			printf("%s", conteudo);
			printf("\n\n");
		}
		fclose(file);
			
		printf("\nDeseja consultar outro CPF? (S/N)");
		scanf("%s", opcao);

	}while(opcao[0] == 'S');
}

int deletar()
{
	char cpf[40];
	char opcao[2];
	
	do{	
		printf("Digite o CPF do usuário a ser deletado: ");
		scanf("%s", cpf);
		
		FILE *file;
		
		if(remove(cpf) == 0)
		{
			printf("\nUsuário deletado com sucesso.\n");
			remove(cpf);
			system("pause");
		}
		
		else
		{
			printf("\nUsuário não encontrado.\n");
	 	}
	 	printf("\nDeseja deletar outro CPF? (S/N)");
		scanf("%s", opcao);
		system("cls");
	 	
	}while(opcao[0] == 'S');
}


int main()
{
	int opcao=0;
	int x=1;
	char senha[10] = "a";
	int comparacao;
	
	printf("Cartório EBAC\n\n");
	printf("Login de administrador\n\n");
	printf("Digite sua senha:");
	scanf("%s", senha);
	
	comparacao = strcmp(senha, "admin");
	
	if(comparacao == 0)
	{
		system("cls");
	
		for(x=1;x=1;)
		{	
	
		system("cls");

		setlocale(LC_ALL, "portuguese");

		printf("\t Cartório EBAC\n\n"); 
		printf("   Selecione a opção desejada.\n\n");
		printf("      1 - Registrar nomes\n"); 
		printf("      2 - Consultar nomes\n");
		printf("      3 - Deletar nomes\n");
		printf("      4 - sair do sistema\n");
		printf("\n   Opção:");
	
		if(scanf("%d", &opcao) != 1)
			{
			while(getchar() !='\n');
			system("cls");
			printf("Opção inválida, tente novamente.\n\n");
			system("pause");
			continue; 
			}
	
				system("cls"); //Responsáel por limpar a tela
		
				switch(opcao)
				{
				case 1:
				registro(); //chamada de função
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
				printf("Opção inválida\n");
				system("pause");
				}
			}
	}
		else
		printf("Senha incorreta");
}

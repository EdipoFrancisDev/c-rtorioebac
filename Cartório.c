#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include<locale.h> //biblioteca de aloca��es de texto por regi�o
#include<string.h> //biblioteca responsavel pelos string

int registro() //Respos�vel por cadastrar os usus�rios no sistema
{
	//inicio de cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");

}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usu�rio n�o se encontra no sistema, deletado com sucesso!.\n");
    	system("pause");
	}
	
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //difinindo a linguagem 
	
	char cpf[40];
    char conteudo [200];
    
    printf("Digite o cpf a ser consultado: ");
    scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
    }
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	    system("pause");
}

int main()
{
	int opcao=0; //definindo as variaveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{

	system("cls");
	
	setlocale(LC_ALL, "Portuguese"); //difinindo a linguagem 
	
	printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	printf("Escolha a Op��o Desejada do Menu:\n\n");
	printf("\t1 - Registrar Nomes\n");
	printf("\t2 - Deletar Nomes\n");
	printf("\t3 - Consultar Nomes\n\n");
	printf("\t4 - sair do sistema\n\n");
	printf("op��o: "); // fim do menu
	
	scanf("%d", &opcao); // guardando as escolhas do usuario

    system("cls"); //respons�vel por limpar a tela
    
       switch(opcao)
       {
	
       case 1:
       registro(); //chamada de fun��es
	   break;
   
       case 2: 
       deletar();
       break;
       
	   case 3:
       consultar();
       break;
       
       case 4:
       	printf("Obrigado por ultilizar o sistema!\n");
       	return 0;
       	break;
       	
       
       default:
       printf("essa op��o n�o esta disponivel!\n");
	   system("pause");
	   break;
	   //fim da chamada de fun��es
	
       }
    
    }





}


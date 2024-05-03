#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include<locale.h> //biblioteca de alocações de texto por região
#include<string.h> //biblioteca responsavel pelos string

int registro() //Resposável por cadastrar os ususários no sistema
{
	//inicio de criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variaveis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
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
	
	printf("Digite o cpf do usuário a ser deletado: ");
	scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usuário não se encontra no sistema, deletado com sucesso!.\n");
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
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n");
    }
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
	
	printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	printf("Escolha a Opção Desejada do Menu:\n\n");
	printf("\t1 - Registrar Nomes\n");
	printf("\t2 - Deletar Nomes\n");
	printf("\t3 - Consultar Nomes\n\n");
	printf("\t4 - sair do sistema\n\n");
	printf("opção: "); // fim do menu
	
	scanf("%d", &opcao); // guardando as escolhas do usuario

    system("cls"); //responsável por limpar a tela
    
       switch(opcao)
       {
	
       case 1:
       registro(); //chamada de funções
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
       printf("essa opção não esta disponivel!\n");
	   system("pause");
	   break;
	   //fim da chamada de funções
	
       }
    
    }





}


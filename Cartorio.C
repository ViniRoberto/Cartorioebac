#include <stdio.h> // Biblioteca de comunicação com o usúario
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings


int registro() // Função responsavel po cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado:"); // Coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); // responsável por copiar os valores das string
    
    FILE *file; // cria o arquivo 
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // salvo o valor da variavel
    fclose(file); // fecha o arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado:");
    scanf("%s" , nome);
    
    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);
    
     file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s" , sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Difite o cargo a ser cadastrado:");
    scanf("%s" , cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);
    
    system("pause");   

}
    

int consulta()
{
	setlocale(LC_ALL, "portuguese"); 
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF ser consultado:");
    scanf("%s" , cpf);
    
    FILE *file;
    file = fopen(cpf, "r");
    
    if(file == NULL)
    {
    	printf("Não foi possilvel abrir o arquivo, não localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s" , conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);

}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF do usuário a ser deletado:");
    scanf("%s",cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
	
}



int main()
{
	
	int opcao=0; //Definindo Variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
	system("cls");
	
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem 
	
	
	printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	printf ("Escolha a opção desejada do menu: \n\n");
	printf("\t1 - Registrar Nomes\n");
	printf("\t2 - Consultar Nomes\n");
	printf("\t3 - Deletar Nomes\n"); 
	printf("Opção:");//Fim do menu
	
	scanf("%d" , &opcao ); //Armazenando a escolha do usuário
	
	system("cls"); //Responsavel por limpar a tela
	
	switch(opcao) // inicio da seleção do menu
	{
		case 1:
		registro();//chamada de funções
		break;
		
		case 2:
		consulta();
		break;
		
		case 3:	
		deletar();
		break;

		default:
		printf("Essa opção não esta disponivel!\n");
		system("pause");
		break;
	} // fim da seleção
	
	
    }	
}

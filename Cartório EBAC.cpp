#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar dos string

    int registro()//Fun��o responsavel por cadastrar usuarios no sistema
	{
		//inicio da cria��o das variaveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//final da cria��o das variaveis/string
		
		printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usuario
		scanf("%s", cpf);//refere-se a string (armazenando a string)
		
		strcpy(arquivo,cpf);//responsavel por copiar os valores da string
		
		FILE *file; // cria o arquivo
		file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
		fprintf(file, cpf); //salva o valor da varialvel
		fclose(file); // fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o nome a ser cadastrado: ");
		scanf("%s",nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file, ",");
		fclose(file);
		
		printf("Digite o sobrenome a ser cadastrado: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file, sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o cargo a ser cadastrado: ");
		scanf("%s", cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file, cargo);
		fclose(file);
		
		system("pause");
		
			
	}
	int consulta()
	{
		setlocale(LC_ALL, "Portuguese");
		
		char cpf[40];
		char conteudo[200];
		
		printf("Digite o cpf a ser consultado: \n");
		scanf("%s",cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("N�o foi possivel localizar esse CPF. \n");
		}
		
		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("Essas s�o as informa��es do usu�rio:");
			printf("%s", conteudo);
			printf("\n\n");
		}
		
		system("pause");
	}
	int deletar()
	{
		
		char cpf[40];
		
		printf("Digite o CPF do usuario a ser deletado: ");
		scanf("%s", cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf, "r");
		
		if(file == NULL)
		{
			printf("O usuario n�o se encontra no sistema! \n");
			system("pause");
		}
	}
    
        int main()
    {
        int opcao=0;//definindo variaveis
        int laco=1;
    
        for(laco=1;laco=1;)
    {

        system("cls");
	
	    setlocale(LC_ALL, "Portuguese");//escolha da linguagem
	
	    printf("### Cart�rio da EBAC ### \n\n");//Inicio do menu
	    printf("Escolha a op��o desejada do menu: \n\n");
    	printf("\t1 - Registar nomes\n");
    	printf("\t2 - Consultar nomes\n");
    	printf("\t3 - Deletar nomes\n\n");
    	printf("\t4 - Sair do sistema!\n\n");
        printf("Op��o: ");//Fim do menu
    
        scanf("%d", &opcao);//armazenamento da escolha do usuario 
    
        system("cls"); //resposavel por deletar a tela
      
      
        switch(opcao)//inicio da sele��o do menu
        {
        	case 1:
            registro();//chamada de fun��o
        	break;
        	
        	case 2:
        	consulta();
	    	break;
	    	
	    	case 3:
	   	    deletar();
    		break;
    		
    		case 4:
    		printf("Obrigado por ultilizar o sistema!");
    		return 0;
    		break;	
    		
    		default:
    		printf("Est� op��o n�o est� disponivel!\n");
    		system("pause");
			break;
				
    	}
      

	}
}

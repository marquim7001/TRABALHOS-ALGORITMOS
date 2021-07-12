/*
Nome: MARCOS ANTONIO SOARES DE SOUZA
Matrícula: uc21105922
Curso: Engenharia de software
*/

#include<stdio.h> //biblioteca que importa função printf e scanf
#include<ctype.h> // biblioteca para importar função toupper
#include<stdlib.h>// biblioteca usada para importar a função limpar tela
#include<locale.h> // bibliotec para formatçaõ de textos
#include<string.h> // biblioteca com funçoes para trabalhar com strings
#include <math.h> //biblioteca para funçoes matematicas
#include <stdbool.h> // biblioteca para manipular variaveis logicas

// DEFINIÇÃO USADA PARA DEFINIR AS CORES, NA QUAL BASTA DEFINIR O CODIGO DA COR QUE A COR MUDA NO TERMINAL  
#define GREEN "\x1b[32m" // define cor verde
#define BLUE "\x1b[34m" // define cor azul
#define RED "\x1b[91m" // define cor vermelha
#define RESET "\x1b[0m" // volta a cor normal
	

int main(){ // inicio do algoritmo
	setlocale(LC_ALL, "Portuguese");
	
	// declaração de variaveis 
	
	/*
    Um nome longo e descritivo é melhor do que um nome pequeno e enigmático, por isso segundo o livro CODIGO LIMPO é sempre 
    importante esbanjar na descrição, para que nao corra o risco de ficar algo vago e desconexo para as demais pessoas que verem seu codigo
    Se um nome requer um comentário, então ele não revela seu propósito!
    */
    
	char nomeDestino[100], nomeCliente[100], retorno, cpf[12], opcaoMenu;
    int opcaoId, quantdAssento=0, idadeCliente, i=0, j=0, contador=0, contadorCrianca=0;
	int poltronaEscolhida, id_contadorReserva=0, reservado=0, qtddPoltronasReservar;
	int contadorReservado=0, contadorConfirmado=0, contadorCancelado=0;
	float valorPassagem, valorTotal, passagemDesconto;
	
	/*
    mensagem de apresentação para o usuario;
	uma boa interação com o usuario garante um nivel de entendimento muito maior do seu codigo, segundo o livro "CODIGO LIMPO"
    */
		printf(" #====================================================#\n");
    	printf(" |                 CADASTRO DO VOO                    |\n ", nomeDestino);
    	printf("#====================================================#\n");
		
		// laço para validação do destino da passagem que não pode ser nulo o nome
		do{
			printf("\nQUAL O DESTINO DA PASSAGEM: ");
			fgets(nomeDestino, 100, stdin);// usado para ler strings
			nomeDestino[strlen(nomeDestino) - 1] = '\0'; // le a quantidade de letras da string, nesse caso o -1 esta tirando a posição ocupada pelo vetor
				if(strlen(nomeDestino) == 0) // sempre que ler a quantidade de letras e ela for = 0, emite a mensagem 
					printf("O NOME DO DESTINO NÃO PODE SER NULO!");
   		} while(strlen(nomeDestino) == 0); // sempre que ler a quantidade de letras e ela for = 0, repete o laço
   		 
   	
   		printf("\n-----------------------------------------------------\n");
    	printf("\n        SEU DESTINO ESCOLHIDO FOI %s                 \n ", nomeDestino);
    	printf("\n-----------------------------------------------------\n");
    	
    	//laço para validação do valor da passagem, que nao pode ser negativo, nem conter caracteres
    	do{
			printf("\n\nQUAL O VALOR DA PASSAGEM PARA %s :",nomeDestino);
			scanf("%f", &valorPassagem); // aloca espaço na memoria para guardar a varivel tipo float
			fflush(stdin);// limpar buffer de memoria 
				if(valorPassagem<=0){
					printf("\nO VALOR DA PASSAGEM NÃO PODE SER NEGATIVO, NEM CARACTERES");}
		}while(valorPassagem<=0); // sempre a passagem receber o valor negativo o laço repete 
    	
    	
  		// laço para validar a quantidade de assentos do avião, que tem que estar no intervalo de [90- 200]
    	do{
    		printf("\n\nQUAL A QUANTIDADE DE ASSENTOS NO VOO PARA ESSE DESTINO: ");
    		scanf("%d", &quantdAssento);
    		fflush(stdin);
    			if(quantdAssento< 90 || quantdAssento >200){
    				printf("\nQUANTIDADE DE ASSENTOS NÃO ACEITA! DEVE ESTAR ENTRE 90 - 200\n");
    			}
		}while(quantdAssento< 90 || quantdAssento>200);// sempre que o valor for maior que 200 ou mneor que 90 o laço se repete 
	
		
		
		int reservaPoltronas[quantdAssento]; // declaração de array, que vai receber exatemente a quantidade que o usuario digitar 
		char situacaoAssento[quantdAssento];

		// validação responsavel por deixar todos os assentos como disponives no começo do programa, visto que nenhuma reserva tera se efetivado ainda
		for(i = 0;i <quantdAssento ;i++){ 
			situacaoAssento[i] = 'D';	
		}
				
			
		system("cls");// limpa a tela 
		
		
	do{	
		do{ // menu para apresentação da compania aerea 
			printf("#===========================================#\n");
			printf("#        SALUMAR LINHAS AEREAS              #\n");
			printf("#===========================================#\n");
			printf("\n");
			printf("#===========================================#\n");
			printf("|                   MENU                    |\n");
			printf("|===========================================|\n");
			printf("| [1]    >>    CADASTRAMENTO CLIENTE        |\n");
			printf("| [2]    >>         OCUPAÇAO                |\n");
			printf("| [3]    >>      EFETUAR RESERVA            |\n");
			printf("| [4]    >>     CONFIRMAR RESERVA           |\n");
			printf("| [5]    >>      CANCELAR RESERVA           |\n");
			printf("| [6]    >>         RELATORIO               |\n");
			printf("| [7]    >>      Sair do programa           |\n");
			printf("#===========================================#\n");
			printf("DIGITE O NUMERO CORRESPONDENTE AO MENU:");//Mensagem a ser escrita na tela
			scanf("%c",&opcaoMenu);//expressão de controle

			if(opcaoMenu == '5' && contadorReservado == '0' ){//logica que nao deixa o usuario cancelar uma reserva, antes de ser feito uma reserva primeiramente
				printf(RED "\nREALIZAR PRIMEIRAMENTE A RESERVA\n"RESET);//ESTRUTURA QUE ALTERA A COR DA MENSAGEM IMPRESSA NO TERMINAL, INICIAR COM A COR QUE DESEJA COLORIR, DEPOIS RESET PARA VOLTAR A ORIGINAL
			}	
		}while(opcaoMenu == '5' && contadorReservado == '0');//Comandos a serem repetidos
		

	
		switch(opcaoMenu){ // guarda as opções que o usuario pode escolher
			
			case '1':
				
			system("cls");//limpa tela 
			
			printf("#=============================================#\n");
       		printf("|              CADASTRO CLIENTE               |\n");
       		printf("#=============================================#\n");
       		
			
			//laço que valida o nome do cliente, este tambem não pode ser nulo// mesmo processo da validação do destino
			do{
				printf("\nQUAL NOME DO CLIENTE:"); 
				fflush(stdin);
				fgets(nomeCliente, 100, stdin);  
				nomeCliente[strlen(nomeCliente) - 1] = '\0'; 
					if(strlen(nomeCliente) == 0)
						printf("\nO NOME DO CLIENTE NÃO PODE SER NULO!");
   			} while(strlen(nomeCliente) == 0);
	
		
			// laço para a validaão da idade do cliente, que deve estar entre [1-150], para limitar um valor real de idade para humanos
			do{
				printf("\nQUAL A IDADE DO(A) CLIENTE %s:", nomeCliente);
				scanf("%d", &idadeCliente);
				fflush(stdin);
					if(idadeCliente < 1 || idadeCliente > 150)
						printf("\nNÃO É POSSIVEL REGISTRAR ESSA IDADE!");
			}while (idadeCliente < 1 || idadeCliente > 150);
			
			
			//condição para quando o cliente tiver 5 anos para baixo, pois ira receber desconto de 50% no valor da passagem 
				if(idadeCliente <= 5){
					contadorCrianca++; // conta quantas crianças fizeram um cadastro
				 	valorPassagem = valorPassagem / 2; 
				}

			// validação do cpf, que deve ter exatamente 11 caracteres
       		do{
        		printf("\nQUAL O (CPF) DO CLIENTE %s:", nomeCliente); 
        		fgets(cpf, 12, stdin);
           		if (strlen(cpf) != 11) // le a quantidade de caracteres e sempre que for diferente de 11, imprime a mensagem 
                	printf("\nCPF COM A QUANTIDADE INCORRETA DE DIGITOS!:\n");
       		}while (strlen(cpf) != 11);
       		
       		printf(GREEN "\nCADASTRO REALIZADO COM SUCESSO!\n" RESET);// imprime a mensagem de verde
       		      		
       		break;
		
		
			case '2':
				
				system("cls"); 
        		
        		printf("#=============================================#\n");
       			printf("| VERIFIQUE A OCUPAÇÃO DAS POLTRONAS DO AVIÃO |\n");
       			printf("#=============================================#\n");

			
			// laço responsavel por percorrer e imprimir o mapa de poltronas
			for(i = 0;i < quantdAssento ;i++){
				if(i%4==0){ // SEMPRE QUE TIVER UM MULTIPLO DE 4, QUEBRA UMA LINHA / ELE RECEBE O RESTO DA DIVISÃO EXATA PARA ISSO ACONTECER
		   			printf("\n\n");
				}		
					if(situacaoAssento[i] == 'R'){ 
						printf(RED "\t%d%c " RESET, i+1, situacaoAssento[i]);// sempre que a situação do assento for 'R', pinta no mapa de vermelho
					}
					else if(situacaoAssento[i] == 'C') {
						printf(BLUE "\t%d%c " RESET, i+1, situacaoAssento[i]); // sempre que a situação do assento for 'C', pinta no mapa de azul
					}
					else {
						printf(GREEN "\t%d%c " RESET, i+1, situacaoAssento[i]); // se nao for nenhuma das duas ele pinta de verde, que representa as passagens disponiveis
					}	
            }
                		
			;break;


			case '3': 
			
				system("cls"); //limpa tela 
        		
        		printf("#=================================#\n");
       			printf("| FAÇA AQUI A RESERVA DA POLTRONA |\n");
       			printf("#=================================#\n");

		
			do{
				//laço que valida a poltrona escolhida, para que ela esteja dentro da quantidade de poltronas digitado pelo usuario
				// não permite com que o usuario selecione uma poltrona que ja foi selecionada
				do{
					printf("\nQUAL ASSENTO DESEJA RESERVAR: ");
    				scanf("%d", &poltronaEscolhida); // validar tem que ser >=1 e <= qtdd assentos
    				fflush(stdin);// limpa buffer de memoria
					
    		 		if(poltronaEscolhida<1)
    					printf("NÃO ESTA DENTRO DA QUANTIDADE DE POLTRONAS DO AVIÃO ");
    				else if (poltronaEscolhida > quantdAssento) // quando o numero da poltrona for maior que a quantidade de poltronas disponiveis
    					printf("NÃO ESTA DENTRO DA QUANTIDADE DE POLTRONAS DO AVIÃO ");
        			else if(situacaoAssento[poltronaEscolhida-1] != 'D') // quando o usuario selecionar uma poltrona que não esta disponivel 
    					printf("NÃO FOI POSSIVEL REALIZAR A RESERVA, ESSE ASSENTO JA ESTA RESERVADO ");
    			}while((poltronaEscolhida<1 || poltronaEscolhida > quantdAssento) || situacaoAssento[poltronaEscolhida-1] != 'D');// sempre que acontecer uma dessas condiçoes, o laço se repete
    	
    			/*
    			Nessa logica usada abaixo, podemos observar a aplicação de conceitos expressos no livro CODIGO LIMPO
    			Especificamente onde se fala do "Keep it simple stupid" que diz da importancia de criação de funções e logicas o mais
    			simples possivel, sem exesso de conficionais e repetições for por exemplo
    			*/
                   		    
    			situacaoAssento[poltronaEscolhida-1]= 'R'; //quando escolher uma poltrona  se subtrai uma porque o vetor começa em 0 e a situação do assento passa a ser "R"
                reservaPoltronas[id_contadorReserva] = poltronaEscolhida;// emite um numero id para cada reserva feita 
    			id_contadorReserva++; // contador que garante com que o id nunca seja igual e comece em 1 
    			
    			if(situacaoAssento[poltronaEscolhida-1]= 'R'){ 
    				contadorReservado++; // conta quantas poltronas foram reservadas, para ser mostrado no relatorio final 
    			}
    	
    			for(i = 0;i < quantdAssento ;i++){
					if(i%4==0){ // SEMPRE QUE TIVER UM MULTIPLO DE 8, QUEBRA UMA LINHA / ELE RECEBE O RESTO DA DIVISÃƒO EXATA PARA ISSO ACONTECER
		   				printf("\n\n");
					}	
					if(situacaoAssento[i] == 'R'){
						printf(RED "\t%d%c " RESET, i+1, situacaoAssento[i]); // sempre que a situação do assento for 'R', pinta no mapa de vermelho
					}
					else{
						printf(GREEN "\t%d%c " RESET, i+1, situacaoAssento[i]);//se nao for nenhuma das duas ele pinta de verde, que representa as passagens disponiveis
					}
				}

		        printf(RED "\n\n\nID PARA CONFIRMAÇÃO DA POLTRONA %d: [%d]\n" RESET, poltronaEscolhida, id_contadorReserva); // emissão do id necessario para confirmar e cancelar poltrona
				printf("\nDESEJA REALIZAR OUTRA RESERVA? SIM [S]- NÃO [N]\n ");
				fflush(stdin);
				scanf("%c", &retorno);
			}while(retorno =='S');// opção para quando o usuario quiser reservar mais de uma poltrona
			
			;break; 
		
	
			case '4':
				
        		system("cls"); 
        		
        		printf("#================================================#\n");
       			printf("| FAÇA AQUI A CONFIRMAÇÃO DE RESERVA DA POLTRONA |\n");
       			printf("#================================================#\n");
       			printf(RED"\nATENÇÃO!!! A CONFIRMAÇÃO DA POLTRONA É FEITA UMA DE CADA VEZ\n"RESET);
        		printf("\nDIGITE O NUMERO IDENTIFICADOR DA RESERVA DO CLIENTE (ID) PARA CONFIRMAR A RESERVA: ");//id de cada reserva deve ser digitado para confirmar a reserva
        		
        		// laço de validação para id, uma vez que esse nao pode ser negativo, nem maior que o contador de reservas
        		do{
        			fflush(stdin);
        			scanf("%d",  &opcaoId);//validar n > 0 && n < contadorReserva
        				if(opcaoId<0 && opcaoId>contadorReservado)
        					printf("\nID NÃO É VÁLIDO");
        		}while(opcaoId<0 && opcaoId>contadorReservado);
        		
        		
                situacaoAssento[reservaPoltronas[opcaoId-1]-1] = 'C'; //confirma protona de acordo com o id guardado o vetor de id
                contadorConfirmado++; // sempre que passar por esse case, o contador que recebe quantas passagens foram confirmadas, recebe +1
				contadorReservado--;// sempre que uma reserva é confirmada é subtraido um numero do contador de reservas, pois o status da poltrona muda
                	
				printf("#==================================================================#\n");
                printf(GREEN "POLTRONA FOI CONFIRMADA COM SUCESSO!! SUA POLTRONA É A %d   \n" RESET, reservaPoltronas[opcaoId-1]);
				printf("#==================================================================#\n");
					
				
			;break;

            case '5':
				
			//confirmar reservas
        		system("cls"); 
        		
        		printf("#=========================================#\n");
       			printf("| FAÇA AQUI O SEU CANCELAMENTO DE RESERVA |\n");
       			printf("#=========================================#\n");
       			printf(RED"\nATENÇÃO!!! A CANCELAMENTO DA POLTRONA É FEITA UMA DE CADA VEZ\n\n"RESET);// imprime com a cor vermelha
        		printf("DIGITE O NUMERO IDENTIFICADOR DO CLIENTE (ID) PARA CANCELAR A RESERVA:");//id de cada reserva deve ser digitado para confirmar a reserva
        		scanf("%d",  &opcaoId);//validar n > 0 && n < contadorReserva so quando for confirmada e reservada
        		
                situacaoAssento[reservaPoltronas[opcaoId-1]-1] = 'D'; //cancela poltrona de acordo com o id guardado o vetor de id e volta o status dela como disponivel
                contadorReservado--; // empre que uma reserva é cancelada é subtraido um numero do contador de reservas, pois o status da poltrona muda

                
                printf(GREEN "\n\nSUA POLTRONA %d FOI CANCELADA COM SUCESSO!\n" RESET, reservaPoltronas[opcaoId-1]);	
		
			;break;
			
			case '6':
				system("cls"); 
				
				// valor da passagem
				valorTotal = (contadorConfirmado+contadorReservado-contadorCrianca)*valorPassagem + (contadorCrianca*valorPassagem)/2;
       			
       			
       			printf("-----------------------------------------\n");
       			printf("|               OCUPAÇÃO                |\n");
       			printf("-----------------------------------------\n");
       			
       			for(i = 0;i < quantdAssento ;i++){
					if(i%4==0){ // SEMPRE QUE TIVER UM MULTIPLO DE 4, QUEBRA UMA LINHA / ELE RECEBE O RESTO DA DIVISÃƒO EXATA PARA ISSO ACONTECER
		   				printf("\n\n");// mantem os espaços organizados
					}
					if(situacaoAssento[i] == 'R'){
						printf(RED "\t%d%c " RESET, i+1, situacaoAssento[i]);// sempre que a situação do assento for 'R', pinta no mapa de vermelho
					}
					else if(situacaoAssento[i] == 'C') {
						printf(BLUE "\t%d%c " RESET, i+1, situacaoAssento[i]);// sempre que a situação do assento for 'C', pinta no mapa de azul
					}
					else {
						printf(GREEN "\t%d%c " RESET, i+1, situacaoAssento[i]);
					}	
           		}
           		
           		
           		printf("\n\n\n#===========================================#\n");
       			printf("|               RELATÓRIO FINAL             |\n");
       			printf("#===========================================#\n");
       			
				printf("#===========================================#\n");
       			printf("DESTINO DO VOO: %s                          \n", strupr(nomeDestino)); // função que coloca o dado de saida em maiusculo
       			printf("QUANTIDADE DE ASSENTOS DO VOO: %d           \n", quantdAssento);
       			printf("NOME CLIENTE: %s                            \n", strupr(nomeCliente));
       			printf("IDADE DO CLIENTE: %d                        \n", idadeCliente);
       			printf("PREÇO PASSAGEM PARA ESSE CLIENTE R$ %.2f    \n", valorPassagem); // de acordo com a idade do passageiro
       			printf("#===========================================#\n");
       			printf("\n");
       			printf("#===========================================#\n");
       			printf("VALOR TOTAL ARRECADADO R$ %.2f             	\n", valorTotal);// soma do valor de todas as passagens 
       			printf("PASSAGENS RESERVADAS: %d                    \n", contadorReservado); // quantas poltronas estão reservadas
       			printf("PASSAGENS CONFIRMADAS: %d                   \n", contadorConfirmado);// quantas poltronas estão confirmadas
       			printf("PASSAGENS DISPONIVEIS: %d                   \n", quantdAssento - contadorReservado - contadorConfirmado);
       			printf("#==========================================#\n");


			;break;
			

			case '7' : 
			 return 0; // fecha o pragrama caso selecionado 
			;break;
		}// fim do switch
        
        
        printf("\nDeseja retornar ao menu?");
        fflush(stdin);
        scanf("%c",&opcaoMenu); 
        
        system("cls");// limpa tela
		
	}while(opcaoMenu != 'N'); // toda vez que o usuario digitar algo diferente de "N" tudo que acontece dentro do laço se repete

	return 0; // retorno da função 
} // final do programa

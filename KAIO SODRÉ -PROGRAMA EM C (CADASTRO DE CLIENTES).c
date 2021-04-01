#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10
int qnt;
struct cadastro {
	char nome[50];
 	char cpf[40];
 	char tel[20];
 	float cred;
 	float div;
 	char obs[50];
 	int cod;
};

struct cadastro clientes[MAX];
	int i;
	int quantidade = 0;
	


void cadastraCliente(struct cadastro cliente) {
 clientes[quantidade] = cliente;
 quantidade++;

}


struct cadastro leitura() {
	
	struct cadastro b;
	
	printf("\n DIGITE UM CODIGO MAIOR QUE ZERO\t");
	scanf("%d",&b.cod);
	if (b.cod>0){
		printf("\n DIGITE SEU NOME \t");
 			setbuf(stdin,NULL);
 		gets(b.nome);
 		
		printf("\n DIGITE SEU CPF\t");
		setbuf(stdin,NULL);
 		gets(b.cpf);
 	
		printf("\n DIGITE SEU TELEFONE\t");
		setbuf(stdin,NULL);
 		gets(b.tel);
 	
		printf("\n DIGITE SEU CREDITO\t");
 		scanf("%f", &b.cred);
 	
		printf("\n DIGITE SUA DIVIDA\t");
 		scanf("%f",&b.div);
 	
 		printf("\n DIGITE SUA OBSERVACAO\t");
 		setbuf(stdin,NULL);
 		gets(b.obs);
 	
 	
	 	return b;
	}
	else {
		printf("\n\n	INFORME UM CODIGO MAIOR QUE ZERO\n");
	 	return b;
	}
 	
 	
 	
}

void imprimeClientes() {

 for (i=0; i<quantidade; i++) {
 	if (clientes[i].cod!=0){
	 
	printf("CODIGO: %d \n",clientes[i].cod);
 	printf("\n Nome: %s", clientes[i].nome);
 	printf("\n CPF....: %s", clientes[i].cpf);
 	printf("\n TELEFONE...: %s", clientes[i].tel);
 	printf("\n CREDITO..: %.2f", clientes[i].cred);
 	printf("\n OBSERVACAO.: %s \n\n", clientes[i].obs);
 }
 }
}

int alterar(){
	int opcao = 0; 
	
		
	printf("\n=============ALTERAR CLIENTE=============");
	printf("\n[1] - Alterar CODIGO");
	printf("\n[2]- Alterar Nome");
	printf("\n[3]- Alterar CPF");
	printf("\n[4]- Alterar Telefone");
	printf("\n[5]- Alterar Credito");
	printf("\n[6]- Alterar Observacao");
	printf("\n[0]- Concluir");
	printf("\n\nOpçao Escolhida: \t");
	scanf("%d", &opcao);	
	printf("\n=========================================");
	
	return opcao;
}

void remover(int posicao) {
 
 int in;
 int i = 0;
 
 if ( posicao < 0) {
 	printf("\nPosicao invalida!\n");
 	return;
 }
 for(i=0;i<quantidade;i++){
 	if (posicao == clientes[i].cod) {
 		clientes[i]=clientes[100];
 	return;
 	}
 }
 

}

int main(){
 
 struct cadastro auxiliar;
 int n , codigo , x , y , p , cod1,alt,op;
 struct cadastro novo;
 int r,i,j;
 char copianome[20],copiacpf[40];
 float pagamento , debito ;
 
 do {
 	
 	
 	printf("\n\n ------------MENU DE OPCOES------------\n");
 	printf("\n PARA SAIR DIGITE - [0] ");
 	printf("\n PARA INSERIR DADOS - [1]");
 	printf("\n PARA EXIBIR DADOS - [2]");
 	printf("\n PARA ALTERAR DADOS - [3]");
 	printf("\n PARA EXCLUIR DADOS - [4]");
 	printf("\n PARA PESQUISAR CLIENTE - [5]");
 	printf("\n PARA FAZER PAGAMENTO OU ADICIONAR DEBITO - [6]");
 	printf("\n PARA EXIBIR A LISTA DE DEVEDORES - [7]");
 	printf("\n LISTAR EM ORDEMAALFABETICA - [8]");
 	printf("\n LISTAR EM ORDEM DIVIDAS - [9]");
 	printf("\n ---------------------------------------\n");
 	
 	printf("\n O que deseja fazer? \t ");
 	
 	scanf("%d", &n);
 
 
 switch(n) {
 
 	case 0: /*para fechar programa*/
 		printf("\n PROGRAMA FECHADO");
 	
	 break;
 
 	case 1: /*para incluir dados*/
 		system("cls");
 		int qnt=0;
 		qnt=qnt+1;
		if (quantidade == MAX) {
 		printf("\n BANCO DE DADOS LOTADO!\n");
 	
		break;
 		}
		novo= leitura();
 		cadastraCliente(novo);
 		break;
 
 	case 2: /*para exibir dados*/
 		system("cls");
 		printf ("\n\n	-----------LISTA DE CLIENTES-----------\n\n ");
	 	imprimeClientes();
 		printf ("\n\n	------^^^^ LISTA DE CLIENTES ACIMA ^^^^------\n\n ");
	 	break;
 	case 3:
 		printf("\n\nDigite o codigo do Cliente:");
		scanf("%d", &cod1);
		
		for (i=0 ; i<quantidade ; i++){
			if(cod1 == clientes[i].cod){
				
					do{
					alt = alterar();
					
					switch(alt){
					case 1: 
					printf("\nDigite o Novo codigo: ");
						fflush(stdin);
						scanf("%d",&clientes[i].cod);
						break;
					case 2:
						printf("\nDigite o Novo Nome    :");
						fflush(stdin);
						fgets(clientes[i].nome,50,stdin);
						break;
					case 3:
						printf("\nDigite o Novo CPF     :");
						fflush(stdin);
						fgets(clientes[i].cpf,40,stdin);
						break;
					case 4:
						printf("\nDigite o Novo Telefone__:");
						fflush(stdin);
						fgets(clientes[i].tel,20,stdin);	
						break;					
					case 5:
						printf("\nDigite o Novo Credito___:");
						scanf("%f", &clientes[i].cred);
						break;
					case 6:
						printf("\nDigite a Nova Observacao:");
						fflush(stdin);
						fgets(clientes[i].obs,50,stdin);
						break;					
					case 0:
						break;	
						
					default:
						printf("\nDigite uma opçao valida.");
					}
					}
					while(alt);
					printf("\n\n *****CLIENTE ALTERADO *****\n\n");
					break;
				}
			}
		break;
		
				
	case 4: /*para excluir dados*/
 
 		printf("Digite O CODIGO DO CLIENTE QUE DESEJA EXCLUIR: ");
 		scanf("%d", &r);
 		remover(r);
 	
		break;
	 
	case 5:
		
		printf("\n PESQUISA POR CODIGO - 1");
		printf("\n PESQUISA POR NOME - 2");
		printf("\n PESQUISA POR CPF - 3");
		printf("\n DIGITE AQUI \t");
		scanf("%d",&p);
		
		switch (p){
			case 1 :
				printf("\n DIGITE SEU CODIGO DE USUARIO \t");
				scanf("%d",&codigo);
		
				
		
					for (i=0; i<quantidade ; i++){
						if(codigo== clientes[i].cod){
							printf("\n CODIGO : %d",clientes[i].cod);
							printf("\n Nome: %s", clientes[i].nome);
 							printf("\n CPF: %s", clientes[i].cpf);
 							printf("\n TELEFONE: %s", clientes[i].tel);
 							printf("\n CREDITO: %.2f", clientes[i].cred);
 							printf("\n DIVIDA : %.2f", clientes[i].div);
 							printf("\n OBSERVACAO : %s \n\n", clientes[i].obs);
 					}	
			
		}
			break;
			
			case 2 :
				
				system("cls");
				
				printf("\n DIGITE SEU NOME: \t");
				setbuf(stdin , NULL);
				gets(copianome);
				
					for (i=0 ; i<quantidade ; i++){
						
						if(strcmp(clientes[i].nome , copianome)==0){
						
							printf("\n CODIGO : %d",clientes[i].cod);
							printf("\n Nome: %s", clientes[i].nome);
 							printf("\n CPF: %s", clientes[i].cpf);
 							printf("\n TELEFONE: %s", clientes[i].tel);
 							printf("\n CREDITO: %.2f", clientes[i].cred);
 							printf("\n DIVIDA : %.2f", clientes[i].div);
 							printf("\n OBSERVACAO : %s \n\n", clientes[i].obs);
 							break;
 							system("pause");
 						}
 						
					}
					if(strcmp(clientes[i].nome , copianome)!=0){
						printf ("\n CLIENTE NAO ENCONTRADO! VERIFIQUE POSSIVEL ERRO NA DIGIRATCAO. ");
 						break;
					}
 		
 				break;
				
				
			
			case 3 :
				system("cls");
				printf("\n DIGITE SEU CPF: \t");
				setbuf(stdin , NULL);
				gets(copiacpf);
				
		
					for (i=0 ; i<quantidade ; i++){
						
						if(strcmp(clientes[i].cpf , copiacpf)==0){
						
							printf("\n CODIGO : %d",clientes[i].cod);
							printf("\n Nome: %s", clientes[i].nome);
 							printf("\n CPF: %s", clientes[i].cpf);
 							printf("\n TELEFONE: %s", clientes[i].tel);
 							printf("\n CREDITO: %.2f", clientes[i].cred);
 							printf("\n DIVIDA : %.2f", clientes[i].div);
 							printf("\n OBSERVACAO : %s \n\n", clientes[i].obs);
 							break;
 						}
 				        
 					}
 					if(strcmp(clientes[i].cpf, copiacpf)!=0){
						 	
 						printf ("\n CLIENTE NAO ENCONTRADO! VERIFIQUE POSSIVEL ERRO NA DIGIRATCAO. ");
 						break;
						 
					}
				break ;
			default :
				printf("\nOPCAO INVALIDA!! ");
				break;
				
		}
		break;
	
	case 6 :
		system("cls");
		printf("\n--------------------- MENU ---------------------\n");
		printf("\n	PARA PAGAMENTO digite [1]\n\n	PARA AUMENTAR A DIVIDA digite [2]\n");
		printf("--------------------- ---- ---------------------\n");
		scanf("%d",&op);
		
		if (op==1){
		
			printf("\n ATENCAO OS VALORES DE PAGAMENTO NAO PODEM ULTRAPASSAR O VALOR DA DIVIDA\n");
		
			printf("\n Pagamento - Digite o valor R$ do pagamento\n \t");
			scanf("%f",&pagamento);
		
		
			if (pagamento > 0  ){
		
				printf("\n DIGITE SEU CODIGO DE USUARIO \t");
				scanf("%d",&codigo);
		
			
		
				for (i=0 ; i<quantidade ; i++){
					
					if(codigo==clientes[i].cod){
						if((pagamento<=clientes[i].div)&&(pagamento<=clientes[i].cred)){
							
							clientes[i].div = clientes[i].div - pagamento;
							clientes[i].cred=clientes[i].cred-pagamento;
							if (clientes[i].div >= 0){
						
								printf("\n\n Ola %s , seu credito eh de R$ %.2f e sua divida :R$ %.2f \n  \t", clientes[i].nome , clientes[i].cred , clientes[i].div   );
								printf("\n\n----** PAGAMENTO CONCLUIDO **----\n\n");
								break;
							}
							
						}
						if(pagamento>clientes[i].div) {
							printf("\n	-----** O PAGAMENTO ULTRAPASSA O VALOR DA DIVIDA! **-----");
							break;
						}
						if(pagamento>clientes[i].cred){
							printf("\n	-----** O PAGAMENTO ULTRAPASSA O VALOR DO CREDITO DISPONIVEL!** -----");
							break;
						}
					}
				}
		
			}
			else{
				printf("\n **INFORME UM VALOR MAIOR QUE ZERO**");
			}
		}
		if (op==2){
			printf("\n  - digite o valor R$ a ser adicionado a sua divida  \t");
			scanf("%f",&debito);
			
			if(debito > 0 ){
		
				printf("\n\n DIGITE SEU CODIGO DE USUARIO \t");
				scanf("%d",&codigo);
				for (i=0 ; i<quantidade ; i++){
				
					if(codigo==clientes[i].cod){
						if ((clientes[i].cred>=(debito+clientes[i].div))){
							clientes[i].div=clientes[i].div+debito;
							
							printf ("\n	Ola %s,sua divida atual eh de  R$ %.2f \n	seu credito eh de R$ %.2f \n\n *Realize o pagamento antes do vencimento!*",clientes[i].nome, clientes[i].div,clientes[i].cred);
							printf("\n\n----** ADICAO DE DIVIDA CONCLUIDA **----\n\n");
							break;
						}
						else{
							printf("\n\n	-----*** O VALOR ULTRAPASSA O LIMITE DE CREDITO ***-----\n\n");
							break;
						}
						
						
						
					}
				}
			}
			else{
				printf("\n **INFORME UM VALOR MAIOR QUE ZERO**");
			}
		}	
		break;
		
		
		
	
	case 7: /*lista de devedores*/
		printf ("\n\n -----LISTA DE DEVEDORES-----\n\n");
	
		for (i=0 ; i < 10 ; i++){
			if(clientes[i].div>0){
				printf("\n O cliente %s deve %.2f _ codigo %d", clientes[i].nome , clientes[i].div, clientes[i].cod);
			}
		}
		printf("\n\n----------------------------------------\n");
	break;
		
	case 8:
		
		for(i = 0;i < quantidade; i++){
			for(j = i + 1;j < quantidade;j++){
				if(strcmp(clientes[i].nome,clientes[j].nome) > 0){
					
					auxiliar.cod = clientes[i].cod;
					strcpy(auxiliar.nome , clientes[i].nome);
					strcpy(auxiliar.cpf, clientes[i].cpf);
					strcpy(auxiliar.tel,clientes[i].tel);
					auxiliar.cred = clientes[i].cred;
					auxiliar.div = clientes[i].div;
					strcpy(auxiliar.obs , clientes[i].obs);
									
					clientes[i].cod = clientes[j].cod;
					strcpy(clientes[i].nome , clientes[j].nome);
					strcpy(clientes[i].cpf,clientes[j].cpf);
					strcpy(clientes[i].tel, clientes[j].tel);
					clientes[i].cred 	= clientes[j].cred;
					clientes[i].div		= clientes[j].div;
					strcpy(clientes[i].obs 	, clientes[j].obs);
									
					clientes[j].cod 		= auxiliar.cod;
					strcpy(clientes[j].nome , auxiliar.nome);
					strcpy(clientes[j].cpf, auxiliar.cpf);
					strcpy(clientes[j].tel, auxiliar.tel);
					clientes[j].cred 	= auxiliar.cred;
					clientes[j].div 		= auxiliar.div;
					strcpy(clientes[j].obs 	, auxiliar.obs);
				}
			}
		}
		printf ("\n\n	-----CLIENTES EM ORDEM ALFABETICA-----\n\n");
		for(i = 0;i < quantidade; i++){
			if(clientes[i].nome!=""){
			
			printf("CODIGO: %d \n",clientes[i].cod);
 			printf("\n Nome: %s", clientes[i].nome);
 			printf("\n CPF....: %s", clientes[i].cpf);
 			printf("\n TELEFONE...: %s", clientes[i].tel);
 			printf("\n CREDITO..: %.2f", clientes[i].cred);
 			printf("\n OBSERVACAO.: %s \n\n", clientes[i].obs);
			}
		}
		printf("----------------------------------------");
		
		break;
	case 9:
		for(i = 0;i < quantidade; i++){
			for(j = i + 1;j < quantidade;j++){
				if(clientes[i].div<clientes[j].div){
					
					auxiliar.cod = clientes[i].cod;
					strcpy(auxiliar.nome , clientes[i].nome);
					strcpy(auxiliar.cpf, clientes[i].cpf);
					strcpy(auxiliar.tel,clientes[i].tel);
					auxiliar.cred = clientes[i].cred;
					auxiliar.div = clientes[i].div;
					strcpy(auxiliar.obs , clientes[i].obs);
									
					clientes[i].cod = clientes[j].cod;
					strcpy(clientes[i].nome , clientes[j].nome);
					strcpy(clientes[i].cpf,clientes[j].cpf);
					strcpy(clientes[i].tel, clientes[j].tel);
					clientes[i].cred 	= clientes[j].cred;
					clientes[i].div		= clientes[j].div;
					strcpy(clientes[i].obs 	, clientes[j].obs);
									
					clientes[j].cod 		= auxiliar.cod;
					strcpy(clientes[j].nome , auxiliar.nome);
					strcpy(clientes[j].cpf, auxiliar.cpf);
					strcpy(clientes[j].tel, auxiliar.tel);
					clientes[j].cred 	= auxiliar.cred;
					clientes[j].div 		= auxiliar.div;
					strcpy(clientes[j].obs 	, auxiliar.obs);
					
				}
			}
		}
		printf ("\n\n	-----CLIENTES EM ORDEM DIVIDAS-----\n\n");
		for(i = 0;i < quantidade; i++){
			if(clientes[i].nome!=""){
			
			printf("CODIGO: %d \n",clientes[i].cod);
 			printf("\n Nome: %s", clientes[i].nome);
 			printf("\n CPF....: %s", clientes[i].cpf);
 			printf("\n TELEFONE...: %s", clientes[i].tel);
 			printf("\n CREDITO..: %.2f", clientes[i].cred);
 			printf("\n DIVIDA..: %.2f", clientes[i].div);
 			printf("\n OBSERVACAO.: %s \n\n", clientes[i].obs);
			}
		}
		printf("-----^^^^LISTA DE DIVIDAS ACIMA^^^^-----");
		
		break;
		
 	default:
 	
	 printf("----- OPCAO INVALIDA -----");
 }
}
 while (n != 0);
 
 return 0;
}

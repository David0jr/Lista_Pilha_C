#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct no{
	int info; 
	struct no *prox; 
};

//Pilha.
void push(struct no **Pilha,int v){
  	struct no *p;
  	
  	//Alocar espaço de memória para o novo nó
  	p = (struct no *) malloc(sizeof(struct no));
  	//Colocar a informação no novo nó
  	p->info = v;
  	
  	//Fazer o Encadeamento do novo nó no início da Lista (Pilha)
  	//O novo nó deve apontar para o primeiro nó, o qual será o segundo
  	p->prox = *Pilha;
  	//E fazer o Pilha apontar para o novo nó que passa a ser o Primeiro
  	*Pilha = p;  	
}//Fim push()

int pop(struct no **Pilha){
	struct no *p;
	int v;
	
	//Colocar a informacao do nó a ser removido no v
	v = (*Pilha)->info;
	
	//Fazer o Encadeamento
	//Guardar o endereço do primeiro nó em p
	p = *Pilha;
	//Fazer o Pilha apontar para o segundo nó, que passa a ser o primeiro
	*Pilha = p->prox;
	//Remover/Desalocar a memória do nó sendo removido
	free(p);

	return v; //retorna a informação do nó removido
}//Fim pop()

void mostrarPilha(struct no **Pilha){
	struct no *PAux=NULL; //Pilha Auxiliar
	int val;

    if (*Pilha==NULL){
    	printf("Pilha Vazia!");
    	return;
		}

		val = pop(Pilha);	//retirei o primeiro da Pilha Original
    printf("%i",val);
    push(&PAux,val); //Guardei na Pilha Auxiliar
  	
  	while (*Pilha!=NULL){
			val = pop(Pilha);	//retira da Pilha Original
	    printf("\n        %i",val);
 		  push(&PAux,val); //Guardei na Pilha Auxiliar
  	}
  	 
		//Remover da Pilha Auxiliar e colocar na Pilha Original
		while (PAux!=NULL) {
			val = pop(&PAux); //Retira da Pilha Auxiliar
			push(Pilha,val);  //Coloca na Pilha Original
		}	
  	  	  	  	
}//Fim mostrarLista()

int qtdeMaiorQueMedia(struct no **Pilha){
	struct no *PAux=NULL; //Pilha Auxiliar
	int val, cont=0, soma=0;
	float media;
	
    if (*Pilha==NULL){
    	return 0;
		}
  	
  	while (*Pilha!=NULL){
			val = pop(Pilha);	//retira da Pilha Original
	    soma = soma + val;
	    cont++;
 		  push(&PAux,val); //Guardei na Pilha Auxiliar
  	}
  	 
  	media = (float)soma/cont; 
  	
  	cont=0;
		//Remover da Pilha Auxiliar e colocar na Pilha Original
		while (PAux!=NULL) {
			val = pop(&PAux); //Retira da Pilha Auxiliar
			if (val>media){ //maior que a média
				cont++; 
			}
			push(Pilha,val);  //Coloca na Pilha Original
		}	
  		
  	return cont;	
}//Fim qtdeMaiorQueMedia()

int localizaValorPilha(struct no **Pilha, int procurado){
	struct no *Paux=NULL;
	int posicao=0, achou=0,val;
	
	//Retirar da Pilha Original e colocar na Pilha auxiliar
	//enquanto não encontrar ou chegar no fim da Pilha
	while((!achou)&&(*Pilha!=NULL)){
		val = pop(Pilha);  //Retira da Pilha original
		posicao++;  //Incrementa a posição
		push(&Paux,val); //Guarda na Pilha Auxiliar
		if (val==procurado){
			achou=1;  //Encontrou
		}
	}
	
	//Voltar valores na Pilha auxiliar para a Pilha original
	while(Paux!=NULL){
		val=pop(&Paux); //Remove da Pilha Auxiliar
		push(Pilha,val); //Volta para a Pilha Original
	}	
	
	//Se encontrou retorna a posição
	if (achou!=0){
		return posicao;
	}else{ //Se não encontrou retorna 0
		return 0;
	}
	
}//Fim localizaValorPilha()

int tamanhoPilha(struct no **Pilha){
	struct no *Paux=NULL;
	int posicao=0, val=0;
	
	//Retirar da Pilha Original e colocar na Pilha auxiliar
	//enquanto não chegar no fim da Pilha
	while(*Pilha!=NULL){
		val = pop(Pilha);  //Retira da Pilha original
		posicao++;  //Incrementa a posição
		push(&Paux,val); //Guarda na Pilha Auxiliar
	}
	
	//Voltar valores na Pilha auxiliar para a Pilha original
	while(Paux!=NULL){
		val=pop(&Paux); //Remove da Pilha Auxiliar
		push(Pilha,val); //Volta para a Pilha Original
	}	
	
	return posicao;
	
}//Fim tamanhoPilha()

//Lista.
void mostrarLista(struct no *L) {
	struct no *p;
	
	if(L == NULL) {
		printf("\n\n Lista Vazia...");
	}
	
	//Aponta p para o primeiro nó da lista
	p = L;
	
	while(p!=NULL) {
		//Imprimir a informação do nó apontado por p
		printf("%i -> ",p->info);
		
		//Passar o p para o próximo nó
		p = p->prox;
	}
	
}//Fim mostrarLista()

void inserirNoInicio(struct no **L, int v) { 
	struct no *p;
	
	//Alocar espa�o de memoria para o novo no
	p = (struct no *) malloc(sizeof(struct no));
	
	p->info = v;
	
	p->prox = *L;
	
	//Fazer o Lista (L) apontar para o novo no, que passara a ser o primeiro
	*L = p;
	
}//Fim inserirNoInicio

void inserirNoFim(struct no **L, int v) { 
	struct no *n, *p;
	
	n = (struct no *) malloc(sizeof(struct no));
	
	n->info = v;
	
	n->prox = NULL;
	
	if(*L == NULL) { //Caso a Lista for vazia
		*L = n; //Aponta L para o novo nó que será o último e também o primeiro
	}
	else {
	
		p = *L;
		while(p->prox != NULL) {
			p = p->prox; //Passa o p para o próximo nó da Lista;
		}
		
		//Colocar o endereço do novo nó no prox do ultimo nó, apontado por p
		p->prox = n;
	}
	
}//Fim inserirNoFim()

void inserirOrdemCrescente(struct no **L, int v) {
	struct no *n, *p, *q;
	int achou;
	
	//Alocar espaço de memória para o novo nó
	n = (struct no *) malloc(sizeof(struct no));
	
	//Colocar a informação no novo nó
	n->info = v;
	
	if(*L == NULL) { //Caso a Lista for vazia
		*L = n; //Aponta L para o novo nó que será o último e também o primeiro
		n->prox = NULL;
	}
	else if((*L)->info >= v) { //Caso tenha que inserir no inicio
		n->prox = *L;
		*L = n;
	}
	else {
		//Fazer o ENCADEAMENTO do novo nó no início da Lista:
		
		//Localizar a posição a ser inserido o novo nó
		p = *L;
		while((p->prox != NULL) && (v >= p->info)) {
			q = p; //Passa o valor de p para o a, guardando sempre o nó anterior;
			p = p->prox; //Passa o p para o próximo nó da Lista;	
		}
		//Caso o novo nó for ser inserido no fim
		if((p->prox == NULL) && (v > p->info)){
			p->prox = n;
			n->prox = NULL;
		}
		else {
			q->prox = n;
			n->prox = p;	
		}	
	}
	
}//Fim inserirOrdemCrescente();

int removerDoInicio(struct no **L) {
	struct no *p;
	int v;
	
	//Colocar a informação do primeiro nó a ser removido no v
	v = (*L)->info;
	
	//Fazer o ENCADEAMENTO
	
	//Guardar o endereço do primeiro nó em p
	p = *L;
	
	//Fazer o L apontar para o segundo nó que passa a ser o primeiro
	*L = (*L)->prox;
	
	//Remover / Desalocar a memória do nó sendo removido
	free(p);
	
	return v; //Retorna a informação do nó removido
}//Fim removerDoInicio()

int removerDoFim(struct no **L) {
	struct no *p, *q;
	int v;
	
	//Encontrar o ultimo nó da Lista
	p = *L;
	while(p->prox != NULL) {
		p = p->prox; //Passa o p para o próximo nó da Lista;
	}
	
	//Colocar a informação do ultimo nó a ser removido no v
	v = p->info;
	
	//Caso Especial: Lista só tem um 1 nó
	if((*L)->prox == NULL) {
		*L = NULL;
	}
	else {
		//Posicionar um outro ponteiro q antes do p
		q = *L;
		while(q->prox != p) {
			q = q->prox; //Passa o p para o próximo nó da Lista;
		}	
		
		//Colocar NULL no prox do nó apontado por q, o qual será o último nó
		q->prox = NULL;
	}
	
	//Remover / Desalocar a memória do nó sendo removido
	free(p);
	
	return v;

}//Fim removerDoFim()

int comprimento(struct no *L) {
	struct no *p;
	int cont = 0;
	
	//Aponta p para o primeiro nó da lista
	p = L;
	
	while(p!=NULL) {
		//Acrescenta 1 no contador
		cont ++;
		
		//Passar o p para o próximo nó
		p = p->prox;
	}
	
	return cont;
	
}//Fim comprimento()

int existe(struct no *L, int v) {
	struct no *p;
	int achou = 0;
	
	//Aponta p para o primeiro nó da lista
	p = L;
	
	while((p!=NULL) && (achou == 0)) {
		
		//Verifica se o valor de V é o mesmo do nó
		if(p->info == v){
			achou = 1;
		}
		
		//Passar o p para o próximo nó
		p = p->prox;
	}
	
	return achou;
}//Fim existe()

//Trabalho Avaliativo.
int removerMaiorDaPilha(struct no **Pilha) { //Feito!
	struct no *PAux = NULL; 
	int val, maior;
	
	val = pop(Pilha); //Retirei o primeiro da Pilha Original
	push(&PAux, val); //Guardei na Pilha Auxiliar
	maior = val;
	
	while(*Pilha!=NULL) {
		val = pop(Pilha); 
		push(&PAux, val); 
		if(maior < val) {
			maior = val;
		}
	}
	
	//Remover da Pilha Auxiliar e colocar na Pilha Original
	while(PAux!=NULL) {
		val = pop(&PAux); 
		if(val != maior) {
			push(Pilha, val); 
		}	
	}
	
	return maior;	
}//Fim removerMaiorDaPilha()

void invertePilhaUsandoLista(struct no **Pilha) { //Feito!
	struct no *ListaAux = NULL; 
	int val;
	
	val = pop(Pilha); 
	inserirNoInicio(&ListaAux, val);
	
	while(*Pilha!=NULL) {
		val = pop(Pilha); 
		inserirNoInicio(&ListaAux, val); 
	}
	
	//Remover da Lista Auxiliar e colocar na Pilha Original
	while(ListaAux!=NULL) {
		val = removerDoFim(&ListaAux); 
		push(Pilha, val); 
	}
	
}//Fim invertePilhaUsandoLista()

void clonaImparLista(struct no **Lista) { //Feito!
	struct no *ListaAux = NULL; //Lista auxiliar
	int val;
	
	while(*Lista!=NULL) {
		val = removerDoInicio(Lista); 
		inserirNoFim(&ListaAux, val); 
		if(val%2==1) {
			inserirNoFim(&ListaAux, val); 
		}
	}
	
	//Remover da Lista Auxiliar e colocar na Lista Original
	while(ListaAux!=NULL) {
		val = removerDoInicio(&ListaAux); 
		inserirNoFim(Lista, val); //Guardei na Lista Original
	}
	
}//Fim clonaImparLista()

void removeRepetidos(struct no **Lista) { //Feito!
	struct no *ListaAux = NULL; 
	int val;
	
	val = removerDoInicio(Lista); 
	inserirNoFim(&ListaAux, val); 
	
	while(*Lista!=NULL) {
		val = removerDoInicio(Lista); //Retirei o primeiro da Lista Original
		if(existe(ListaAux, val)!=1) {
			inserirNoFim(&ListaAux, val); //Guardei na Lista Auxiliar caso n�o exista ainda nela
		}
	}
	
	//Remover da Lista Auxiliar e colocar na Lista Original
	while(ListaAux!=NULL) {
		val = removerDoInicio(&ListaAux); //Retirei o primeiro da Lista Auxiliar
		inserirNoFim(Lista, val); //Guardei na Lista Original
	}
}//Fim removeRepetidos()


//Menus de Acessos.
 int menuPilha(void){
	struct no *Pilha; //Guarda o endereço do Topo da Pilha
	int op,val,retorno;
	
	Pilha = NULL; //Lista vazia

	do{
	
		printf("\n\n########   P i l h a   ################");
		printf("\n# 1) Inserir na Pilha (push)            #");
		printf("\n# 2) Mostrar Pilha                      #");
		printf("\n# 3) Remover da Pilha (pop)             #");
		printf("\n# 4) Qtde maior que a Media na Pilha    #");
		printf("\n# 5) Verifica se um valor esta na Pilha #");
		printf("\n# 6) Numero de itens da Pilha           #");
		printf("\n# 7) Remover Maior da Pilha             #");
		printf("\n# 8) Inverter os Valores da Pilha       #");
		printf("\n# 0) Sair                               #");
		
		printf("\nOpcao-> ");
		fflush(stdin); scanf("%i",&op);
		
		switch(op){
			case 1: //Inserir na Pilha - push()
				printf("\nInserir N Pilha:");
				printf("\nDigite o valor: ");
				fflush(stdin); scanf("%i",&val);
				push(&Pilha,val);
				break;
				
			case 2: //Mostrar a Pilha
				printf("\n\nPilha-> ");
				mostrarPilha(&Pilha);
				
				printf("\n\n Clique em qualquer tecla para voltar ao menu...");
				getch();
				break;
				
			case 3: //Remover da Pilha - pop() 
				printf("\nRemover da Pilha:");
				if (Pilha==NULL){//Pilha vazia
					printf("\nPilha Vazia. Impossivel remover!");
				}else{
					val = pop(&Pilha);
					printf("\nInformacao do no removido: %i",val);
				}
				break;
				
			case 4: //Mostra qtde de elementos maiores que a Média
				printf("\nQtde elementos Maiores que a media: %i",qtdeMaiorQueMedia(&Pilha));
				break;
				
			case 5: //Verifica se um valor está na Pilha
				printf("\nDigite o valor a ser localizado: ");
				fflush(stdin); scanf("%i",&val);
				retorno = localizaValorPilha(&Pilha,val);
				if (retorno==0){
					printf("\nO valor %i NAO foi localizado na Pilha!",val);
				}else{
					printf("\nO valor %i foi localizado na posicao %i da Pilha.",val,retorno);
				}
				break;
				
			case 6:
				retorno = tamanhoPilha(&Pilha);
				printf("\n Qtd de itens da pilha: %i", retorno);
				break;
				
			case 7: //Remover o maior valor da pilha
			printf("\n Remover o Maior Valor da Pilha: ");
				if(Pilha == NULL) { 
					printf("\n\n Pilha Vazia...");
					printf("\n Impossivel Remover!");
				}
				else {
					val = removerMaiorDaPilha(&Pilha);
					printf("\n\n Valor %i removido com sucesso!", val);				
				}
				break;
				
			case 8: //Inverter Valores
				printf("\n Inverter os Valores da Pilha: ");
				if(Pilha == NULL) { 
					printf("\n\n Pilha Vazia...");
					printf("\n Impossivel Inverter!");
				}
				else {
					invertePilhaUsandoLista(&Pilha);
					printf("\n\n Pilha invertida com sucesso!");		
				}
				break;
				
			default:
				break;
			}
		system("cls");
		}while(op!=0);
}//Fim menuPilha()

int menuLista(void) {
	struct no *Lista; //Guarda o endereço do PRIMEIRO nó da Lista
	int op, val;
	
	Lista = NULL; //Lista inicia vazia
	
	do {
		printf("\n\n");
		printf("\n ############## LISTA ##############   \n");
		printf("\n# 1) Mostrar Lista                      #");
		printf("\n# 2) Inserir no Inicio                  #");
		printf("\n# 3) Inserir no Fim                     #");
		printf("\n# 4) Inserir em Ordem Crescente         #");
		printf("\n# 5) Remover do Inicio                  #");
		printf("\n# 6) Remover do Fim                     #");
		printf("\n# 7) Comprimento da Lista               #");
		printf("\n# 8) Existe valor na Lista?             #");
		printf("\n# 9) Clonar Valores Impares da Lista    #");
		printf("\n# 10) Remover Valores Repetidos         #");
		printf("\n# 0) Sair                               #");
		printf("\n\n Opcao ---> ");
		fflush(stdin); scanf("%i", &op);
		
		switch(op) {
			case 1: //Mostrar Lista
				printf("\n Lista -> ");
				mostrarLista(Lista);
				
				printf("\n\n Clique em qualquer tecla para voltar ao menu...");
				getch();
				break;
				
			case 2: //Inserir no Início da Lista
				printf("\n Inserir No Inicio: ");
				printf("\n Digite o valor: ");
				fflush(stdin); scanf("%i",&val);
				inserirNoInicio(&Lista, val);
				printf("\n Valor inserido com sucesso...");
				break;
				
			case 3: //Inserir no Fim da Lista
				printf("\n Inserir No Fim: ");
				printf("\n Digite o valor: ");
				fflush(stdin); scanf("%i",&val);
				inserirNoFim(&Lista, val);
				printf("\n Valor inserido com sucesso...");
				break;
				
			case 4: //Inserir em Ordem Crescente
				printf("\n Inserir em Ordem Crescente: ");
				printf("\n Digite o valor: ");
				fflush(stdin); scanf("%i",&val);
				inserirOrdemCrescente(&Lista, val);
				printf("\n Valor inserido com sucesso...");				
				break;
				
			case 5: //Remover do Início da Lista
				printf("\n Remover do Inicio: ");
				if(Lista == NULL) { //Caso a lista for vazia
					printf("\n\n Lista Vazia...");
					printf("\n Impossivel Remover...");
				}
				else {
					val = removerDoInicio(&Lista);
					printf("\n\n Valor %i removido com sucesso...", val);				
				}			
				break;
				
			case 6: //Remover do Fim da Lista
				printf("\n Remover do Fim: ");
				if(Lista == NULL) { //Caso a lista for vazia
					printf("\n\n Lista Vazia...");
					printf("\n Impossivel Remover...");
				}
				else {
					val = removerDoFim(&Lista);
					printf("\n\n Valor %i removido com sucesso...", val);				
				}
				break;
				
			case 7: //Comprimento da Lista
				printf("\n Comprimento da Lista: %i elementos.", comprimento(Lista));
								
				printf("\n\n Clique em qualquer tecla para voltar ao menu...");
				getch();				
				break;
				
			case 8: //Existe valor na Lista
				printf("\n Existe Valor na Lista? ");
				printf("\n Digite o valor: ");
				fflush(stdin); scanf("%i",&val);
				
				if(existe(Lista, val) == 1) {
					printf("\n O valor %i existe na Lista.", val);
				}
				else {
					printf("\n O valor %i nao existe na Lista.", val);
				}
				
				printf("\n\n Clique em qualquer tecla para voltar ao menu...");
				getch();
				break;
				
			case 9: //Clonar Valores Impares da Lista
				printf("\n Clonar Valores Impares da Lista: ");
				if(Lista == NULL) { //Caso a lista for vazia
					printf("\n\n Lista Vazia...");
					printf("\n Impossivel Clonar...");
				}
				else {
					clonaImparLista(&Lista);
					printf("\n\n Valores impares clonados com sucesso...");				
				}				
				break;
				
			case 10: //Remover Valores Repetidos
			printf("\n Remover Valores Repetidos: ");
				if(Lista == NULL) { //Caso a lista for vazia
					printf("\n\n Lista Vazia...");
					printf("\n Impossivel Remover...");
				}
				else {
					removeRepetidos(&Lista);
					printf("\n\n Valores repetidos removidos com sucesso...");				
				}	
			
			default:
				break;
		}
	system("cls");
	} while(op!=0);
	
}//Fim menuLista()

int main(void) {
	int op;
	
	do {
		printf("\n\n");
		printf("\n ##### MENU PRINCIPAL ######\n");
		printf("\n# 1) Menu Lista              #");
		printf("\n# 2) Menu Pilha              #");
		printf("\n  0) Sair                    #");
		printf("\n\n Opcao ---> ");
		fflush(stdin); scanf("%i", &op);
		
		switch(op) {
			case 1: //Menu Lista
				system("cls");
				menuLista();
				
				printf("\n\n Clique em qualquer tecla para voltar ao menu principal.");
				getch();
				break;
				
			case 2: //Menu Pilha
				system("cls");
				menuPilha();
				
				printf("\n\n Clique em qualquer tecla para voltar ao menu principal.");
				getch();
				break;
				
			default:
				break;
		}
	system("cls");
	} while(op!=0);
	
}//Fim main()		

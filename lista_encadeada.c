#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include <string.h>

struct Lista {
	  int id; //identificador
      char  *nome; // nome
      struct Lista *prox;      
   } Lista; // n?
   
typedef struct Lista tplista;   


//Fun??es para estrutura da lisa
//--------------------------------------------

tplista *lista;  // Primeiro ponteiro da lista


tplista * inicia_lista() {
   lista = (tplista *) malloc (sizeof(tplista)); // inicio da pilha
   lista->id=0;
   lista->nome=NULL;
   lista->prox = NULL; 
   return lista;
}

void insere_na_lista (tplista *lista, int id, char *nome) { 
   tplista *novo, *aux, *ant;
   //cria o novo nó para a lista
   novo = (tplista *) malloc (sizeof (tplista));
   novo->id=id;
   novo->nome=(char *) malloc (sizeof (nome));
   strcpy(novo->nome, nome);
   novo->prox  = NULL;
   
   //insere o novo nó na posição correta da lista
   aux=lista; // pega o ponteiro para a lista 
   
   //procura a posição correta paar inserir   
   while((aux->id < id) &&(aux->prox!=NULL)){
   		ant=aux;
   		aux=aux->prox;
   }
    	
   //Supondo que já  achou a posição correta ou chegou no final da lista
   if(aux->prox!=NULL) 	
   	novo->prox=aux->prox;
   	   	
   //Insere o item novo na posição subsequente	
   if(aux->id < id)
   		aux->prox=novo;   
   else	{
   		novo->prox=aux;   
   		ant->prox=novo;
   }
}

//verifica se a lista está vazia
int lista_vazia(void){
	return ((lista==NULL)||(lista->id==0 && lista->prox==NULL));
}

int retira_da_lista (tplista *lista, int id) {
	if(!lista_vazia()){ // Verifica se a lista está vazia
   		tplista *aux, *ant;
	    aux=lista;   
		ant=NULL;		
   		//procura a posição correta paar inserir   
    	while((aux->id != id) &&(aux->prox!=NULL)){
			ant=aux;
    		aux=aux->prox;
    	}
    	//Supondo que já  achou a posição ou chegou no final da lista
    	if(aux->id!=id){
     		printf("Identificador não encontrado!");
     		return 0;
   		}else{
   			ant->prox=aux->prox;
   			free (aux);
   			printf("Identificador %d excluído com sucesso!",id);
   			return 1; 
   		}
   	}
}


void libera_lista(tplista *lista){
	//Desempilha todos os itens da pilha
	if(!lista_vazia()) {	
		libera_lista(lista->prox);
		free(lista->prox);
	}
}


//--------------------------------------------



tplista *Plista;

//função de impressão da lista
void read_lista_recursivo(tplista **lista) {
   if (*lista != NULL) {
   	  if((*lista)->id>0)
      	printf ("Id: %d Nome: %s \n", (*lista)->id,(*lista)->nome);   	
      read_lista_recursivo (&(*lista)->prox);
   }
}

//Função contar lista recursivo
int contar_nos(tplista *lista){
	if(lista->prox==NULL)
		return 0;
	else
		return 1 + contar_nos(lista->prox);
}


 int main(void){

	int id, opcao;
	char nome[200];
    setlocale(LC_ALL, "Portuguese");
    printf("Lista encadeada\n");
    Plista=inicia_lista();
    do {
	    printf("\nDigite uma opção: 1 Inserir na lista; 2 Remover da lista; 4 Imprimir lista ; 5 Sair:");
        scanf("%d", &opcao);
        if (opcao == 1){
           printf("\nDigite um id: ");
           scanf("%d", &id);
           printf("\nDigite um nome: ");
           scanf("%s", nome);           
           insere_na_lista(Plista,id, nome);
        } else if  (opcao == 2){
           printf("\nDigite um id: ");
           scanf("%d", &id);
           retira_da_lista(Plista,id);
        } else if  (opcao == 4){
        	read_lista_recursivo(&Plista);
      }
      
	}while (opcao !=5);
	
}
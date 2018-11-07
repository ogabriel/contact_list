#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int id;
	
	struct Node *prox;
} no;

int tam;

void inicia(no *LISTA);
int menu();
void opcao(no *LISTA, int op);
no *aloca();
void insereFim(no *LISTA);
void insereInicio(no *LISTA);
void exibe(no *LISTA);
void libera(no *LISTA);
void insere (no *LISTA);
void retiraInicio(no *LISTA);
void retiraFim(no *LISTA);
void retira(no *LISTA);

main()
{
	no *LISTA = (no *) malloc(sizeof(no));
	if(!LISTA)
	{
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else
	{
	inicia(LISTA);
	int opt;
		do
		{
		opt=menu();
		opcao(LISTA,opt);
	    }
		while(opt);
	free(LISTA);
	}
}

int menu()
{
	int opt;
	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar lista\n");
	printf("2. Exibir lista\n");
	printf("3. Adicionar um NO no inicio\n");
	printf("4. Adicionar um NO final\n");
	printf("5. Escolher onde inserir um NO\n");
	printf("6. Retirar um NO do inicio\n");
	printf("7. Retirar um NO do fim\n");
	printf("8. Escolher de onde tirar um NO\n");
	printf("Opcao: "); 
	scanf("%d", &opt);
	return opt;
	
}

void opcao(no *LISTA, int op)
{
	switch(op){
		case 0:
			libera(LISTA);
			break;
		case 1:
			libera(LISTA);
			inicia(LISTA);
			break;
		case 2:
			exibe(LISTA);
			break;
		case 3:
			insereInicio(LISTA);
			break;		
		case 4:
			insereFim(LISTA);
			break;
		case 5:
			insere(LISTA);
			break;
		case 6:
			retiraInicio(LISTA);
			break;
		case 7:
			retiraFim(LISTA);
			break;
		case 8:
			retira(LISTA);
			break;
		default:
			printf("Comando invalido\n\n");
	}
}

void inicia(no *LISTA)
{
	LISTA->prox = NULL;
	tam=0;
}

int vazia(no *LISTA)
{
	if(LISTA->prox == NULL)
		return 1;
	else
		return 0;
}

no *aloca()
{
	no *novo=(no *) malloc(sizeof(no));
	if(!novo)
	{
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	else
	{
		printf("Novo elemento: "); 
		scanf("%d", &novo->id);
		return novo;
	}
}


void insereFim(no *LISTA)
{
	no *novo = aloca();
	novo->prox = NULL;
	if(vazia(LISTA))
		LISTA->prox = novo;
	else
	{
		no *tmp = LISTA->prox;
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		tmp->prox = novo;
	}
	tam++;
}

void insereInicio(no *LISTA)
{
	no *novo = aloca();	
	no *oldInic = LISTA->prox;
	LISTA->prox = novo;
	novo->prox = oldInic;
	tam++;
}

void exibe(no *LISTA)
{
	system("cls");
	if(vazia(LISTA))
	{
		printf("Lista vazia\n\n");
		return ;
	}
	no *tmp;
	tmp = LISTA->prox;
	printf("Lista:");
	while( tmp != NULL)
	{
		printf("%5d", tmp->id);
		tmp = tmp->prox;
	}
	printf("\n\n");
}

void libera(no *LISTA)
{
	if(!vazia(LISTA))
	{
		no *proximo,
		   *atual;
		atual = LISTA->prox;
		while(atual != NULL)
		{
			proximo = atual->prox;
			free(atual);
			atual = proximo;
		}
	}
}

void insere(no *LISTA)
{
	int pos,count;
	printf("Em que posicao, [de 1 ate %d] voce deseja inserir: ", tam);
	scanf("%d",&pos);
	if(pos>0 && pos <= tam)
	{
		if(pos==1)
			insereInicio(LISTA);
		else
		{
			no *atual = LISTA->prox,
			   *anterior = LISTA; 
			no *novo=aloca();
			for(count=1 ; count < pos ; count++)
			{
				anterior=atual;
				atual=atual->prox;
			}
			anterior->prox = novo;
			novo->prox = atual;
			tam++;
		}
			
	}
	else
	printf("Elemento invalido\n\n");		
}

void retiraInicio(no *LISTA)
{
	if(LISTA->prox == NULL)
	{
		printf("Lista vazia\n");
	}
	else
	{
		no *tmp = LISTA->prox;
		LISTA->prox = tmp->prox;
		tam--;
	}
				
}

void retiraFim(no *LISTA)
{
	if(LISTA->prox == NULL)
	{
		printf("Lista vazia\n\n");
	}
	else
	{
		no *ultimo = LISTA->prox,
		   *penultimo = LISTA;
			 
		while(ultimo->prox != NULL)
		{
			penultimo = ultimo;
			ultimo = ultimo->prox;
		}
		penultimo->prox = NULL;
		tam--;
	}
}

void retira(no *LISTA)
{
	int opt,count;
	printf("Que posicao, [de 1 ate %d] voce deseja retirar: ", tam);
	scanf("%d", &opt);
	if(opt>0 && opt <= tam)
	{
		if(opt==1)
			return retiraInicio(LISTA);
		else
		{
			no *atual = LISTA->prox,
			   *anterior = LISTA; 
				 
			for(count=1 ; count < opt ; count++)
			{
				anterior=atual;
				atual=atual->prox;
			}
			
		anterior->prox=atual->prox;
		tam--;
		}
	}
	else
	{
		printf("Elemento invalido\n\n");
	}
}

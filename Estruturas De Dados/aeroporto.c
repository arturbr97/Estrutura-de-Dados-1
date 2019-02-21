
#include"aeroporto.h"

void pressione_enter(){
	printf("\nPressione ENTER para continuar...\n");
	fflush(stdin);
	getchar();
}

void opcoes(){
	int opcao;

	NoFila* passageiros = NULL;
	NoLista* lista_embarque = NULL;

	do{
		system("cls");
		printf("\n---- MENU DO AEROPORTO ----");
		printf("\n1. Checkin.\n2. Embarque.\n3. Mostrar Fila de Passageiros.\n4. Mostrar Passageiros na Aeronave.\n5. Passageiro fez checkin?\n6. Passageiro embarcou?\n7. Passageiro com Menos malas.\n8. Passageiro com Mais malas.\n0. Sair\n");
		printf("\nOpcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				passageiros = cadastrar_passageiro(passageiros);
				pressione_enter();
				break;
			case 2:
				lista_embarque = menu_embarque(&passageiros, lista_embarque);
				pressione_enter();
				break;
			case 3:
				imprimir_fila(passageiros);
				pressione_enter();
				break;
			case 4:
				imprimir_lista(lista_embarque);
				pressione_enter();
				break;
			case 5:
				checkin_busca_seq(passageiros);
				pressione_enter();
				break;
			case 6:
				lista_embarque_busca_seq(lista_embarque);
				pressione_enter();
				break;
			case 7:
				printf("\nPassageiro com a menor quantidade de malas: ");
				passageiro_qtd_malas(lista_embarque, 0);
				pressione_enter();
				break;
			case 8:
				printf("\nPassageiro com a maior quantidade de malas: ");
				passageiro_qtd_malas(lista_embarque, 1);
				pressione_enter();
				break;
			case 0:
				printf("Saindo...\n");
				break;
			default:
				printf("\nOpcao invalida.\n");
				pressione_enter();
		}
	}while(opcao != 0 || opcao != 0);
}

NoFila* cadastrar_passageiro(NoFila* fila){
	char nome[100], cor_mala[20];
	int idade, id, qtd, i=0, idPassageiro;
	float peso;

	printf("\nPrimeiro nome: ");
	scanf("%s",  nome);
	printf("Idade:  ");
	scanf("%d",&idade);

	int res = 1;

    printf("Id: ");
    scanf("%d",&id);
   

	NoPilha* pilha_malas = NULL;

    printf("\nQuantidade de malas: ");
	scanf("%d", &qtd);

	while(i < qtd){
		printf("\nCor da mala %d: ", i+1);
		scanf("%s", cor_mala);
		printf("Peso da mala %d: ",i+1);
		scanf("%f", &peso);
		printf("\n");

		NoPilha* novo = alocar_elem_pilha(cor_mala, peso);
		pilha_malas = inserir_nova_mala(pilha_malas,novo);
		i++;
	}
	imprimir_pilha(pilha_malas);

	NoFila* novo = alocar_elem_fila(nome, idade, id, pilha_malas);
	fila = inserir_fila(fila, novo);
	return fila;
}

NoFila* alocar_elem_fila(char* n, int i, int id, NoPilha* mala){
	NoFila* novo = (NoFila*)malloc(sizeof(NoFila));
	Pessoa* p = (Pessoa*)malloc(sizeof(Pessoa));
	strcpy(p->nome, n);
	p->idade = i;

	novo->passageiro = p;
	novo->prox = NULL;
	novo->idPassageiro = id;
	novo->mala = mala;

	return novo;
}

NoFila* inserir_fila(NoFila* fila, NoFila* novo){

	if(fila == NULL)
		return novo;

	NoFila* aux = fila;
	while(aux->prox != NULL)
		aux = aux->prox;

	aux->prox = novo;
	return fila;
}

NoFila* remover_elem_fila(NoFila* fila, NoFila* elem){
	NoFila* aux = fila;
	NoFila* nova_fila = NULL;

	while(aux != NULL){
		if(aux->idPassageiro != elem->idPassageiro){
			NoFila* n = alocar_elem_fila(aux->passageiro->nome, aux->passageiro->idade, aux->idPassageiro, aux->mala);
			nova_fila = inserir_fila(nova_fila, n);
		}
		aux = aux->prox;
	}
	return nova_fila;
}

void imprimir_fila(NoFila* fila){
	NoFila* aux = fila;

	if(fila == NULL)
		printf("Nao ha passageiros...\n");

	while(aux != NULL){
		printf("\nNome: %s. Idade: %d. Id: %d. Qtd Malas: %d.", aux->passageiro->nome, aux->passageiro->idade, aux->idPassageiro, qtd_malas(aux->mala));
		aux = aux->prox;
	}
}

NoPilha* alocar_elem_pilha(char* c, float p){
	NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
	strcpy(novo->cor, c);
	novo->peso = p;
	novo->prox = NULL;
	return novo;
}

NoPilha* inserir_nova_mala(NoPilha* pilha, NoPilha* novo){
	novo->prox = pilha;
	return novo;
}

void imprimir_pilha(NoPilha* pilha){
	NoPilha* aux = pilha;
	int i = 0;
	while(aux != NULL){
		printf("\nMala %d: %s. %.2f KG.", i+1, aux->cor, aux->peso);
		aux = aux->prox;
		i++;
	}
}

NoLista* alocar_elem_lista(NoFila passageiro, NoPilha* malas){
	NoLista* novo = (NoLista*)malloc(sizeof(NoLista));
	novo->passageiro = passageiro;
	novo->mala = malas;
	novo->prox = NULL;
	novo->ant  = NULL;
	return novo;
}

NoLista* inserir_lista(NoLista* lista, NoLista* novo){

	if(lista == NULL)
		return novo;

	novo->ant = lista;
	lista->ant = novo;

	NoLista* aux = lista;
	while(aux->prox != NULL){
		aux = aux->prox;
	}
	aux->prox = novo;

	return lista;
}

void imprimir_lista(NoLista* lista_embarque){
	NoLista* aux = lista_embarque;
	if (lista_embarque==NULL){
		return;
	}
	while(aux != NULL){
		printf("\nPassageiro: %s - %d anos. Id: %d", aux->passageiro.passageiro->nome, aux->passageiro.passageiro->idade, aux->passageiro.idPassageiro);
		imprimir_pilha(aux->mala);
		aux = aux->prox;
		printf("\n");
	}
}

NoLista* menu_embarque(NoFila** fila, NoLista* lista){
	int opcao;

	do{
		if(*fila == NULL){
			printf("\nNao ha passageiros...");
			return lista;
		}
		system("cls");
		printf("\n---- OPCOES DE EMBARQUE ----");
		printf("\n1. Por Id -> Ordem Crescente (selection sort) -> Menor Id primeiro.\n2. Por Id -> Ordem Crescente (selection sort) -> Maior Id primeiro.\n3. Por Id -> Ordem Decrescente (selection sort) -> Menor Id primeiro.\n4. Por Id -> Ordem Decrescente (selection sort) -> Maior Id primeiro.\n");
		printf("\n5. Por Id -> Ordem Crescente (merge sort) -> Menor Id primeiro.\n6. Por Id -> Ordem Crescente (merge sort) -> Maior Id primeiro.\n7. Por Id -> Ordem Decrescente (merge sort) -> Menor Id primeiro.\n8. Por Id -> Ordem Decrescente (merge sort) -> Maior Id primeiro.\n");
		printf("\n9. Por Mala -> Ordem Crescente (selection sort) -> Menor Mala primeiro.\n10. Por Mala -> Ordem Crescente (selection sort) -> Maior Mala primeiro.\n11. Por Mala -> Ordem Decrescente (merge sort) -> Menor Mala primeiro.\n12. Por Mala-> Ordem Decrescente (merge sort) -> Maior Mala primeiro.\n");
		printf("\n0. Voltar.\n\nOpcao: ");
		scanf("%d", &opcao);

		switch(opcao){
			case 1:
				printf("\n---Passageiros ordenados por Id (selection Sort) em Ordem Crescente (Obs.: Menor Id embarca Primeiro):");
				*fila = selection_sort_crescente_id(*fila);
				imprimir_fila(*fila);
				lista = embarcar_passageiro(fila, lista, 0);
				pressione_enter();
				break;
			case 2:
				printf("\n---Passageiros ordenados por Id (selection Sort) em Ordem Crescente (Obs.: Maior Id embarca Primeiro):");
				*fila = selection_sort_crescente_id(*fila);
				imprimir_fila(*fila);
				lista = embarcar_passageiro(fila, lista, 1);
				pressione_enter();
				break;
			case 3:
				printf("\n---Passageiros ordenados por Id (selection Sort) em Ordem Decrescente (Obs.: Menor Id embarca Primeiro):");
				*fila = selection_sort_decrescente_id(*fila);
				imprimir_fila(*fila);
				lista = embarcar_passageiro(fila, lista, 1);
				pressione_enter();
				break;
			case 4:
				printf("\n---Passageiros ordenados por Id (selection Sort) em Ordem Decrescente (Obs.: Maior Id embarca Primeiro):");
				*fila = selection_sort_decrescente_id(*fila);
				imprimir_fila(*fila);
				lista = embarcar_passageiro(fila, lista, 0);
				pressione_enter();
				break;
			case 5:
				printf("\n---Passageiros ordenados por Id (Merge Sort) em Ordem Crescente (Obs.: Menor Id embarca Primeiro):");
				merge_sort_id(fila, 0);
				imprimir_fila(*fila);
				lista = embarcar_passageiro(fila, lista, 0);
				pressione_enter();
				break;
			case 6:
				printf("\n---Passageiros ordenados por Id (Merge Sort) em Ordem Crescente (Obs.: Maior Id embarca Primeiro):");
				merge_sort_id(fila, 0);
				imprimir_fila(*fila);
				lista = embarcar_passageiro(fila, lista, 1);
				pressione_enter();
				break;
			case 7:
				printf("\n---Passageiros ordenados por Id (Merge Sort) em Ordem Decrescente (Obs.: Menor Id embarca Primeiro):");
				merge_sort_id(fila, 1);
				imprimir_fila(*fila);
				lista = embarcar_passageiro(fila, lista, 1);
				pressione_enter();
				break;
			case 8:
				printf("\n---Passageiros ordenados por Id (Merge Sort) em Ordem Decrescente (Obs.: Maior Id embarca Primeiro):");
				merge_sort_id(fila, 1);
				imprimir_fila(*fila);
				lista = embarcar_passageiro(fila, lista, 0);
				pressione_enter();
				break;

            case 9:
				printf("\n---Passageiros ordenados por Malas (selection Sort) em Ordem Crescente (Obs.: Menor Mala embarca Primeiro):");
				*fila = selection_sort_crescente_mala(*fila);
				imprimir_fila(*fila);
				lista = embarcar_passageiro(fila, lista, 0);
				pressione_enter();
				break;
			case 10:
				printf("\n---Passageiros ordenados por Malas (selection Sort) em Ordem Crescente (Obs.: Maior Mala embarca Primeiro):");
				*fila = selection_sort_crescente_mala(*fila);
				imprimir_fila(*fila);
				lista = embarcar_passageiro(fila, lista, 1);
				pressione_enter();
				break;
			case 11:
				printf("\n---Passageiros ordenados por Malas (selection Sort) em Ordem Decrescente (Obs.: Menor Mala embarca Primeiro):");
				*fila = selection_sort_decrescente_mala(*fila);
				imprimir_fila(*fila);
				lista = embarcar_passageiro(fila, lista, 1);
				pressione_enter();
				break;
			case 12:
				printf("\n---Passageiros ordenados por Malas (selection Sort) em Ordem Decrescente (Obs.: Maior Mala embarca Primeiro):");
				*fila = selection_sort_decrescente_mala(*fila);
				imprimir_fila(*fila);
				lista = embarcar_passageiro(fila, lista, 0);
				pressione_enter();
				break;

			case 0:
				printf("Voltando...\n");
				break;
			default:
				printf("\nOpcao invalida.\n");
				pressione_enter();
		}
	}while(opcao != 0);

	return lista;
}

NoFila* selection_sort_crescente_id(NoFila* passageiros){
	NoFila *aux = passageiros;
	NoFila *i, *j, *prox_i;
	for(i=aux; i!=NULL && i->prox!=NULL; i=i->prox){
		NoFila* menor = i;
		for(j=i; j!=NULL; j=j->prox)
			if(j->idPassageiro < menor->idPassageiro)
				menor = j;

		if(menor != i){
			Pessoa* pess_tmp;
			int id_tmp;

			pess_tmp = menor->passageiro;
			id_tmp = menor->idPassageiro;

			menor->passageiro = i->passageiro;
			menor->idPassageiro = i->idPassageiro;

			i->passageiro = pess_tmp;
			i->idPassageiro = id_tmp;
		}
	}
	return aux;
}

NoFila* selection_sort_decrescente_id(NoFila* passageiros){
	NoFila *aux = passageiros;
	NoFila *i, *j, *prox_i;
	for(i=aux; i!=NULL && i->prox!=NULL; i=i->prox){
		NoFila* menor = i;
		for(j=i; j!=NULL; j=j->prox)
			if(j->idPassageiro > menor->idPassageiro)
				menor = j;

		if(menor != i){
			Pessoa* pess_tmp;
			int id_tmp;

			pess_tmp = menor->passageiro;
			id_tmp = menor->idPassageiro;

			menor->passageiro = i->passageiro;
			menor->idPassageiro = i->idPassageiro;

			i->passageiro = pess_tmp;
			i->idPassageiro = id_tmp;
		}
	}
	return aux;
}

NoFila* selection_sort_crescente_mala(NoFila* passageiros){
	NoFila *aux = passageiros;
	NoFila *i, *j, *prox_i;
	for(i=aux; i!=NULL && i->prox!=NULL; i=i->prox){
		NoFila* menor = i;
		for(j=i; j!=NULL; j=j->prox)
			if(qtd_malas(j->mala) < qtd_malas(menor->mala))
				menor = j;

		if(menor != i){
			Pessoa* pess_tmp;
			int id_tmp;
			NoPilha* mala_tmp;

			pess_tmp = menor->passageiro;
			id_tmp = menor->idPassageiro;
			mala_tmp = menor->mala;

			menor->passageiro = i->passageiro;
			menor->idPassageiro = i->idPassageiro;
			menor->mala = i->mala;

			i->passageiro = pess_tmp;
			i->idPassageiro = id_tmp;
			i->mala = mala_tmp;
		}
	}
	return aux;
}

NoFila* selection_sort_decrescente_mala(NoFila* passageiros){
	NoFila *aux = passageiros;
	NoFila *i, *j, *prox_i;
	for(i=aux; i!=NULL && i->prox!=NULL; i=i->prox){
		NoFila* menor = i;
		for(j=i; j!=NULL; j=j->prox)
			if(qtd_malas(j->mala) > qtd_malas(menor->mala))
				menor = j;

		if(menor != i){
			Pessoa* pess_tmp;
			int id_tmp;
			NoPilha* mala_tmp;

			pess_tmp = menor->passageiro;
			id_tmp = menor->idPassageiro;
			mala_tmp = menor->mala;

			menor->passageiro = i->passageiro;
			menor->idPassageiro = i->idPassageiro;
			menor->mala = i->mala;

			i->passageiro = pess_tmp;
			i->idPassageiro = id_tmp;
			i->mala = mala_tmp;
		}
	}
	return aux;
}

void merge_sort_id(NoFila** headRef, int ordem){
	NoFila* head = *headRef;
  	NoFila* a;
  	NoFila* b;

  	if((head == NULL) || (head->prox == NULL)){
    	return;
  	}

  	dividir_fila(head, &a, &b);

  	merge_sort_id(&a, ordem);
  	merge_sort_id(&b, ordem);

  	*headRef = juntar_filas(a, b, ordem);
}

NoFila* juntar_filas(NoFila* a, NoFila* b, int ordem){
	NoFila* result = NULL;

  	if(a == NULL)
    	return(b);
  	else if(b == NULL)
    	return(a);

 	if(ordem == 1){ //ordem decrescente
		if (a->idPassageiro >= b->idPassageiro){
	  		result = a;
	    	result->prox = juntar_filas(a->prox, b, ordem);
	    }
	  	else{
	    	result = b;
	    	result->prox = juntar_filas(a, b->prox, ordem);
	  	}
	}
	else{
		if (a->idPassageiro <= b->idPassageiro){
		    result = a;
		    result->prox = juntar_filas(a->prox, b, ordem);
		}
		else{
		    result = b;
		    result->prox = juntar_filas(a, b->prox, ordem);
		}
	}
  	return(result);
}

void dividir_fila(NoFila* source, NoFila** frontRef, NoFila** backRef){
	NoFila* fast;
  	NoFila* slow;
  	if (source==NULL || source->prox==NULL){
    	*frontRef = source;
    	*backRef = NULL;
  	}
  	else{
    	slow = source;
    	fast = source->prox;

	    while (fast != NULL){
	    	fast = fast->prox;
	      	if (fast != NULL){
	        	slow = slow->prox;
	        	fast = fast->prox;
	      	}
	    }

	    *frontRef = source;
	    *backRef = slow->prox;
	    slow->prox = NULL;
	}
}

NoLista* embarcar_passageiro(NoFila** fila_original, NoLista* lista_embarque, int ordem){
	int qtd, i=0,op;


	NoFila* passageiros = *fila_original;

	if(ordem == 1){ //maior primeiro
		while(passageiros->prox != NULL)
			passageiros = passageiros->prox;
	}

	printf("\n\nDeseja embarcar o passageiro %s? (1-Sim/2-Nao): ", passageiros->passageiro->nome);
	scanf("%i", &op);
	if(op == 1 ){

		NoFila passageiro_atual;
		NoFila* n;
		n = alocar_elem_fila(passageiros->passageiro->nome, passageiros->passageiro->idade, passageiros->idPassageiro, passageiros->mala);
		passageiro_atual = *n;

		NoLista* novo = alocar_elem_lista(passageiro_atual, passageiros->mala);
		lista_embarque = inserir_lista(lista_embarque, novo);
		*fila_original = remover_elem_fila(*fila_original, passageiros);
	}
	return lista_embarque;
}

void checkin_busca_seq(NoFila* fila){
	int id, res = 1;
	printf("\nId do Passageiro: ");
	scanf("%d", &id);

	NoFila* aux = fila;
	while(aux != NULL){
		if(aux->idPassageiro == id){
			res = 0;
			break;
		}
		aux = aux->prox;
	}
	if (res == 0)
		printf("\nPassageiro %s fez o checkin.\n", aux->passageiro->nome);
	else
		printf("\nPassageiro nao fez o checkin ou nao existe");
}

void lista_embarque_busca_seq(NoLista* lista){
	int id, res = 1;
	printf("\nId do Passageiro: ");
	scanf("%d", &id);

	NoLista* aux = lista;
	while(aux != NULL){
		if(aux->passageiro.idPassageiro == id){
			res = 0;
			break;
		}
		aux = aux->prox;
	}
	if (res == 0)
		printf("\nPassageiro %s ja embarcou.\n", aux->passageiro.passageiro->nome);
	else
		printf("\nPassageiro nao embarcou ou nao existe");
}

int qtd_malas(NoPilha* malas){
	int qtd = 0;
	NoPilha *aux = malas;

	while(aux!=NULL){
		qtd++;
		aux=aux->prox;
	}
	return qtd;
}

void passageiro_qtd_malas(NoLista* lista_embarque, int operacao){
	NoLista* aux = lista_embarque;
	int qtd = 0;
	char* nome;

	if(aux==NULL)
		return;

	int m = qtd_malas(aux->mala);
	nome = aux->passageiro.passageiro->nome;

	while(aux != NULL){
		qtd = qtd_malas(aux->mala);

		if(operacao==0){ //verifica o menor
			if(qtd < m){
				m = qtd;
				strcpy(nome, aux->passageiro.passageiro->nome);
			}
		}
		else{ //verifica o maior
			if(qtd > m){
				m = qtd;
				strcpy(nome, aux->passageiro.passageiro->nome);
			}
		}

		aux = aux->prox;
	}
	printf("%s. Qtd de Malas: %d.", nome, m);
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pessoa Pessoa;
typedef struct noFila NoFila;
typedef struct noPilha NoPilha;
typedef struct noLista NoLista;

struct pessoa{
	char nome[100];
	int idade;
};
struct noFila{
	Pessoa
	*passageiro;
	NoFila *prox;
	NoPilha *mala;
	int idPassageiro;
};
struct noPilha{
	float peso;
	int idMala;
	char cor[20];
	Pessoa *donoMala;
	NoPilha *prox;
};
struct noLista{
	NoFila passageiro;
	NoPilha *mala;
	NoLista *prox, *ant;
};

void pressione_enter();
void opcoes();
NoFila* cadastrar_passageiro(NoFila* f);
NoFila* alocar_elem_fila(char* n, int i, int id, NoPilha* p);
NoFila* inserir_fila(NoFila* f, NoFila* n);
NoFila* remover_elem_fila(NoFila* f, NoFila* e);
void imprimir_fila(NoFila* f);
NoPilha* alocar_elem_pilha(char* c, float p);
NoPilha* inserir_nova_mala(NoPilha* p, NoPilha* n);
void imprimir_pilha(NoPilha* p);
NoLista* alocar_elem_lista(NoFila p, NoPilha* m);
NoLista* inserir_lista(NoLista* l, NoLista* n);
void imprimir_lista(NoLista* l);
NoLista* menu_embarque(NoFila** f, NoLista* l);

NoLista* embarcar_passageiro(NoFila** f, NoLista* l, int o);
NoFila* selection_sort_crescente_id(NoFila* f);
NoFila* selection_sort_decrescente_id(NoFila* f);
NoFila* selection_sort_crescente_mala(NoFila* passageiros);
NoFila* selection_sort_decrescente_mala(NoFila* passageiros);

void merge_sort_id(NoFila** headRef, int o);
NoFila* juntar_filas(NoFila* a, NoFila* b, int o);
void dividir_fila(NoFila* source, NoFila** frontRef, NoFila** backRef);

void checkin_busca_seq(NoFila* f);
void lista_embarque_busca_seq(NoLista* l);

int qtd_malas(NoPilha* malas);
void passageiro_qtd_malas(NoLista* lista_embarque, int operacao);

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
	float payload;
	struct No* prox;
} No_t;

typedef struct
{
	struct No* inicio;
	struct No* fim;
} Fila_t;

Fila_t* criar(void)
{
	Fila_t* fila = (Fila_t*)malloc(sizeof(Fila_t));
	fila->inicio = fila->fim = NULL;
	return fila;
}

/* função auxiliar: inserir no fim */
No_t* ins_fim(No_t* fim, float v) 
{
	No_t* p = (No_t*) malloc(sizeof(No_t));
	p->payload = v;
	p->prox = NULL;
	if (fim != NULL) // verifica se a lista não estava vazia
		fim->prox = p;
	return p;
}

void inserir(Fila_t* f, float v)
{
	f->fim = ins_fim(f->fim,v);
	if (f->inicio == NULL) // fila antes vazia?
		f->inicio = f->fim;
}

/* função auxiliar: retirar do início */
No_t* ret_ini(No_t* inicio) 
{
	No_t* p = inicio->prox;
	free(inicio);
	return p;
}

float retirar(Fila_t* f) 
{
	float v;

	if (vazia(f)) 
	{
		printf("Fila vazia!\n");
		exit(1); // aborta programa 
	}
	v = f->inicio->payload;
	f->inicio = ret_ini(f->inicio);
	if (f->inicio == NULL) // fila ficou vazia?
		f->fim = NULL;
	return v;
}


int vazia(Fila_t* f)
{
	return(f->inicio == NULL);
}

void imprimir(Fila_t* f)
{
	No_t* q;

	for (q = f->inicio; q != NULL; q = q->prox)
		printf("%f\n", q->payload);
}

void liberar(Fila_t* f) 
{
	No_t* q = f->inicio;
	while(q != NULL) 
	{
		No_t* t = q->prox;
		free(q);
		q = t;
	}
	free(f);
}


void main(void)
{
	Fila_t* fila;

	fila = criar();
	inserir(fila, 1.1);
	inserir(fila, 2.1);
	inserir(fila, 3.1);
	inserir(fila, 4.1);
	imprimir(fila);
	liberar(fila);
}

#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
	float info;
	struct No* anterior;
} No_t;

typedef struct {
	No_t* topo;
} Pilha;

//Utiliza alocacao dinamica para manter notacao de ponteiro em todo o codigo e facilita
//movimentacao do ponteiro de topo
Pilha* criar(void)
{
	Pilha *p;
	
	p = (Pilha*)malloc(sizeof(Pilha));
	p->topo = NULL;
	return p;
}

No_t* push(Pilha *p, float v)
{
	No_t* novo;
	novo = (No_t*)malloc(sizeof(No_t));
	novo->info = v;
	novo->anterior = p->topo;
	p->topo = novo;
	return novo;
}

float pop(Pilha *p)
{
	float v;
	No_t* topo_atual;

	if (vazia(p))
	{
		printf("Erro: Pilha vazia!\n");
		exit(1); 
	}
	v = p->topo->info;
	topo_atual = p->topo;
	p->topo = topo_atual->anterior;
	free(topo_atual);
	return v;
}

int vazia(Pilha *p)
{
	return (p->topo == NULL);
}

void liberar(Pilha *p)
{
	while (p->topo != NULL)
	{
		No_t *anterior = p->topo->anterior;

		free(p->topo);
		p->topo = anterior;
	}
	free(p);
}

void imprimir(Pilha* p) 
{
	No_t* q;

	for (q = p->topo; q != NULL; q = q->anterior)
		printf("%4.2f\n", q->info);
}

void main(void)
{
	Pilha* p = criar();
	push(p,20.0);
	push(p,20.8);
	push(p,20.3);
	push(p,44.5);
	push(p,33.3);
	push(p,20.9);
	imprimir(p);
	printf("Retirado: %4.2f\n", pop(p));
	printf("Retirado: %4.2f\n", pop(p));
	printf("Configuracao da fila:\n");
	imprimir(p);
	liberar(p);
}

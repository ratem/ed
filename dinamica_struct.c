#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TAMVET 5
#define	TAM_NOME	32
#define	TAM_NOME_S	"32"

typedef struct 
{
	char nome[TAM_NOME];
	uint16_t tamanho;
} impressao_t;

impressao_t* aloca_fila_impressao(void)
{	
	impressao_t* fila;

	fila = (impressao_t*)malloc(TAMVET*sizeof(impressao_t));
	if(!fila)
	{
		printf("\nNao ha memoria disponivel para alocar fila de impressao! Saindo do programa!\n");
		exit(1);
	}
	return fila;
}

void obtem_arquivos_impressao(impressao_t* fila)
{
	uint8_t i;

	for(i = 0; i < TAMVET; i++)
	{
		printf("Entre com o nome do arquivo: ");
		scanf(" %" TAM_NOME_S "[^\n]", fila[i].nome);
		printf("Entre com o tamanho do arquivo: ");
		scanf("%d", (int*)&fila[i].tamanho);
	}
}

void desaloca_fila_impressao(impressao_t* fila)
{
	free(fila);
}

void imprime_fila_impressao(impressao_t* fila)
{
	uint8_t i;

	printf("Fila de impressao:\n");
	for(i = 0; i < TAMVET; i++)
		printf("Arquivo [%d]: %s, tamanho %d\n", i, fila[i].nome, fila[i].tamanho);
}

int main(void)
{
	impressao_t* fila_impressao;

	fila_impressao = aloca_fila_impressao();
	obtem_arquivos_impressao(fila_impressao);
	imprime_fila_impressao(fila_impressao);
	desaloca_fila_impressao(fila_impressao);
	exit(0);
}

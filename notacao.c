#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TAMANHO 5

typedef struct
{
	uint8_t	a;
	char	b;

} pacote;

pacote* aloca(uint8_t tamanho)
{
	pacote* pacotes;

	pacotes = (pacote*)malloc(tamanho*sizeof(pacote));
	if(!pacotes) return 0;
	return pacotes;
}

void acessa_como_vetor(pacote vetor[], uint8_t tamanho)
{
	uint8_t i;

	for(i = 0; i < tamanho; i++)
	{	
		vetor[i].a = i;
		vetor[i].b = 'a' + i;
		printf("\n %u, %c \n", 	(unsigned)vetor[i].a, vetor[i].b);
	}
}

void acessa_como_ponteiro(const pacote* p, uint8_t tamanho)
{
	pacote* t;
	uint8_t i;

	t = p;
	for(i = 0; i < tamanho; i++)
	{	
		t->a = i;
		t->b = 'a' + i;
		printf("\n %u, %c \n", 	(unsigned)t->a, t->b);
		t++;
	}
}

int main()
{
	pacote* p;
	
	p = aloca(TAMANHO);
	acessa_como_vetor(p, TAMANHO);
	acessa_como_ponteiro(p, TAMANHO);
	return 0;
}

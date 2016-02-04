#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define TAMVET 5

int main(void)
{
	int16_t *inteiros;
	uint8_t i;

	inteiros = (int16_t*)malloc(TAMVET*sizeof(int16_t));
	if(!inteiros)
	{
		printf("\nNao ha memoria disponivel! Saindo do programa!\n");
		exit(1);
	}
	for(i = 0; i < TAMVET; i++)
		inteiros[i] = 10*i;
	for(i = 0; i < TAMVET; i++)
		printf("Conteudo de inteiros[%d]: %d\n", i, inteiros[i]);
	free(inteiros);
	exit(0);
}

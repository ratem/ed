#include <stdio.h>
#include <stdint.h>

#define	TAMVETOR	5

void main(void)
{
	uint8_t i;
	uint16_t x, *px;
	uint32_t y, *py;

	x = 10;
	y = 20;
	px = &x;
	py = &y;
	printf("Valor de px: %p, conteudo de px: %u \n", px, (unsigned)*px);
	printf("Valor de py: %p, conteudo de py: %d \n", py, *py);
	for(i = 0; i < TAMVETOR; i++)
	{
		printf("Valor de px (em decimal): %lu \n", (unsigned long)px);
		px++;
	}
	printf("\n");
	for(i = 0; i < TAMVETOR; i++)
	{
		printf("Valor de py (em decimal): %lu \n", (unsigned long)py);
		py++;
	}
}

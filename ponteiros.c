#include <stdio.h>
#include <stdint.h>

void main(void)
{
	uint16_t x, *px;
	uint32_t y, *py;

	x = 10;
	y = 20;
	px = &x;
	py = &y;
	printf("Valor de px: %p, conteudo de px: %u \n", px, (unsigned)*px);
	printf("Valor de py: %p, conteudo de py: %d \n", py, *py);
}

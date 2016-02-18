/*
	Este programa simula a preparacao para transmissao via rede de um frame composto por um campo de um byte 
	e outro de dois bytes, onde o primeiro representa um booleano (apenas um bit) e o segundo endereca ateh
	1024 (usando 10 bits). O frame eh entao compactado para caber em apenas 11 bits, cuja representacao minima 
	eh uma variavel de 16bits.
*/
#include <stdint.h>
#include <stdio.h>

typedef struct
{
	uint8_t type;
	uint16_t address;	
} frame_t;

typedef struct
{
	uint16_t data;
} packet_t;

packet_t pack(frame_t frame)
{
	packet_t packet;
	uint16_t buffer;

	packet.data = frame.address;		//Copia os 10 primeiros bits
	buffer = frame.type;				//Guarda o boolean num buffer de 16 bits
	buffer = buffer << 15;				//Desloca o bit para a extrema esquerda
	packet.data = packet.data | buffer;	//Funde os dois valores
	return packet;
}

frame_t unpack(packet_t packet)
{
}

void print16bits(uint16_t data)
{
	int8_t i;

	for(i = 15; i >= 0; i--)
		printf("%u ", data&(1 << i) ? 1 : 0);//Seleciona bit a bit e imprime apenas esse bit usando o ? 
	printf("\n");
}

int main(void)
{
	frame_t frame;
	packet_t packet;

	frame.type = 1;
	frame.address = 8;
	packet = pack(frame);
	print16bits(packet.data);	
	return 0;
}


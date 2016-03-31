#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef union
{
	float fm; 
	int32_t im;
} float_integer_t;

int main(void)
{
	float_integer_t fi;	
	fi.im = 1061997773;
	printf("%f \n", fi.fm);
	fi.fm = 2345.5678;
	printf("%lu \n", (unsigned long)fi.im);
	fi.im = 1158846742;
	//Now you can proceed to your bitwise operations...
	//But... note the rounding problem!
	printf("%f \n", fi.fm);
	printf("%.4f \n", fi.fm);
	//:-(
	//Another solution
	float f;
	uint8_t *fp;
	uint8_t i;
	uint8_t floatarray[sizeof(float)];

	f = 2345.5678;
	//Going to...
	fp = (uint8_t*)&f;
	for(i = 0; i < sizeof(float); i++) floatarray[i] = fp[i];
	//Checking... note that it is byte to byte, not the float bit division 1, 8, 23
	for(i = 0; i < sizeof(float); i++) printf("%u ", (unsigned)floatarray[i]);
	//Comming from...
	float g;
	uint8_t* gp;
	gp = (uint8_t*)&g;
	for(i = 0; i < sizeof(float); i++) gp[i] = floatarray[i];
	printf("\nThere comes the rounding again... %f \n", g);
}

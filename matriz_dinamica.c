#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int16_t* allocate_matrix(uint8_t nlines, uint8_t ncolumns)
{
	int16_t  *matrix;

	matrix = (int16_t*)malloc(nlines*ncolumns*sizeof(int16_t));
	if(!matrix)
	{
		printf("\nNo memory for the matrix\n");
		exit(1);
	}
	return matrix;
}

void fill_in_matrix(uint8_t nlines, uint8_t ncolumns, int16_t* matrix)
{
	int16_t line, column;
	int16_t m_test[3][3] = {{1,1,1},{2,2,2},{3,3,3}};

	for(line = 0; line < nlines; line++)
		for(column = 0; column < ncolumns; column++)
		{
//			printf("Enter the value in position [%d][%d]\n", line, column);
//			scanf("%d", matrix[line*sizeof(int16_t)*ncolumns + column*sizeof(int16_t)]);
			matrix[line*sizeof(int16_t)*ncolumns + column*sizeof(int16_t)] = m_test[line][column];
		}
}

void print_matrix(uint8_t nlines, uint8_t ncolumns, uint16_t* matrix)
{
	uint8_t line, column;

	for(line = 0; line < nlines; line++)
		for(column = 0; column < ncolumns; column++)
               printf("%d     ", matrix[line*sizeof(int16_t)*ncolumns + column*sizeof(int16_t)]);
    printf("\n");
}

void deallocate(int16_t* matrix)
{
	free(matrix);
}

int main()
{
	int16_t *matrix;
	int columns, lines;
/*
	printf("Enter with the number of lines: ");
	scanf("%d", &lines);
	printf("Enter with the number of columns: ");
	scanf("%d", &columns);
*/
//	printf("\n %d %d ", lines, columns);
	lines = columns = 3;
	matrix = allocate_matrix(lines, columns);
	fill_in_matrix(lines, columns, matrix);
	print_matrix(lines, columns, matrix);
	deallocate(matrix);
	return 0;
}

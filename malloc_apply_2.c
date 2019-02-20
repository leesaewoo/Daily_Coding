#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, x, y;
	
	int **pp = (int **)malloc(sizeof(int*)*10);
	
	for(i=0;i<10;i++)
	{
		*(pp + i)=(int *)malloc(sizeof(int)*8);
	}
	
	for(y=0;y<10;y++)
	{
		for(x=0;x<8;x++)
		{
			*(*(pp+y)+x) = 8*y + x;
		}
	}
	
	for(y=0;y<10;y++)
	{
		for(x=0;x<8;x++)
		{
			printf("%3d",*(*(pp+y)+x));
		}
		printf("\n");
	}
	
	for(y=0; y<10;y++)
	{
		free(*(pp+y));
	}
	
	return 0;
}

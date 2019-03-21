#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j;
	int** pt;
	
	pt = (int**)malloc(sizeof(int*)*10);
	
	for(i=0;i<10;i++)
	{
		*(pt+i) = (int*)malloc(sizeof(int)*8);
	}
	
	for(j=0;j<10;j++)
	{
		for(i=0;i<8;i++)
		{
			*(*(pt+j)+i) = 8*j + i;
		}
	}

	for(j=0;j<10;j++)
	{
		for(i=0;i<8;i++)
		{
			printf("%3d",*(*(pt+j)+i));
		}
		printf("\n");
	}
	
	for(i=0;i<10;i++)
	{
		free(*(pt+i));
	}
	
	return 0;
}

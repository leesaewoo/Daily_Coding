#include <stdio.h>
#include <stdlib.h>

void Heapify(int* heapArrayAddress, int n);

int main(void)
{
	int heapSize;
	scanf("%d", &heapSize);
	
	int *heapArray = (int*)malloc(sizeof(int) * heapSize);
	int i;
	for(i = 0 ; i < heapSize ; i++)
	{
		scanf("%d", &*(heapArray + i));
	}
	
	int heapHalfSize;
	if(heapSize % 2 == 0)
	{
		heapHalfSize = heapSize / 2;
	}
	else
	{
		heapHalfSize = (heapSize + 1) / 2;
	}
	
	for(i = heapHalfSize - 1 ; i >= 0 ; i--)
	{
		Heapify(heapArray, heapHalfSize);
	}
	
	
	return 0;
}

void Heapify(int* heapArray, int n)
{
	
}

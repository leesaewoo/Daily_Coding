#include <stdio.h>
#include <stdlib.h>

void Heapify(int* heapArrayAddress, int heapSize, int halfHeapSize);

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
	
	int halfHeapSize;
	if(heapSize % 2 == 0)
	{
		halfHeapSize = heapSize / 2;
	}
	else
	{
		halfHeapSize = (heapSize + 1) / 2;
	}
	
	for(i = 0 ; i <= halfHeapSize ; i++) // �ִ� �� ����
	{
		Heapify(heapArray, heapSize,halfHeapSize - i);
	}
	
	//�ְ��� �迭�� ������(���������̱� ����)�� ���� ���� ���� ������ ���� �ְ��� �ִ� �ڸ��� ���� Heapify
	int *arrayASC = (int*)malloc(sizeof(int) * heapSize); // �ְ����� ä���ִ� �迭 
	
	for(i = heapSize - 1 ; i >= 0 ; i--) // ���� ���Կ��� 
	{
		arrayASC[i] = heapArray[0];
		
		if(i != 0)
		{
			heapArray[0] = heapArray[i];
			Heapify(heapArray, i, 1);
		}
	}
	
	//check 
	for(i = 0 ; i < heapSize ; i++)
	{
		printf("arrayASC[%d] = %d\n", i, arrayASC[i]);
	}
	//check
	
	free(heapArray);
	free(arrayASC);
	
	return 0;
}

void Heapify(int* heapArray, int heapSize, int halfHeapSize)
{
	int temp;
	if(halfHeapSize != 0)
	{
		if(heapArray[(halfHeapSize - 1) * 2 + 1] > heapArray[halfHeapSize - 1] && (halfHeapSize - 1) * 2 + 1 < heapSize)
		{
			temp = heapArray[(halfHeapSize - 1) * 2 + 1];
			heapArray[(halfHeapSize - 1) * 2 + 1] = heapArray[halfHeapSize - 1];
			heapArray[halfHeapSize - 1] = temp;
			
			Heapify(heapArray, heapSize, halfHeapSize * 2);
		}
		if(heapArray[(halfHeapSize - 1) * 2 + 2] > heapArray[halfHeapSize - 1] && (halfHeapSize - 1) * 2 + 2 < heapSize)
		{
			temp = heapArray[(halfHeapSize - 1) * 2 + 2];
			heapArray[(halfHeapSize - 1) * 2 + 2] = heapArray[halfHeapSize - 1];
			heapArray[halfHeapSize - 1] = temp;
			
			Heapify(heapArray, heapSize, halfHeapSize * 2 + 1);
		}
		
		//check
		int i;
		printf("----\n");
		for(i = 0 ; i < heapSize ; i++)
		{
			printf("%d\n", heapArray[i]);
		}
		printf("----\n");
		//check
	}
}

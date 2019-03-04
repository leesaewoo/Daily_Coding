#include <stdio.h>
#include <stdlib.h>


//TO DO LIST//
// 1. �迭�� ���Ұ� 0~100 ������ ���� �̹Ƿ�, ���Ұ� ���ڸ�, ���ڸ� �� �� pT �� ���ϴ� �˰��� ¥���� 
// 2. ���� p���� �ڿ����� �ް� �ִµ�, p���� R��D�� �̷���� ���ڿ���, �����ؾ��� 
// 3. �Էµ� p���� ���� �ش� case�� �迭�� �����ϴ� �˰���� ���� OUTPUT �˰��� ¥���� 

void R(int *array, int *length); // R(������) �Լ� ����
void D(int *array, int *length); // D(������) �Լ� ���� 

int main(void)
{
	int i, j, k;
	int T; // T�� Test case
	while(1)
	{
		scanf("%d",&T);
		if(T >= 0 && T <= 100)
		{
			break;
		}
	}
	
	int *pn;
	pn = (int*)malloc(sizeof(int) * T); // �� test case �� n ���� ���� ����(�迭) �Ҵ� 
	int *pp;
	pp = (int*)malloc(sizeof(int) * T); // �� test case �� p ���� ���� ����(�迭) �Ҵ� 
	
	int **pT = (int**)malloc(sizeof(int) * T);
	for(i = 0 ; i < T ; i++)
	{
		scanf("%d", (pp + i));
		scanf("%d", (pn + i));
		*(pT + i) = (int*)malloc(sizeof(int) * *(pn + i));
		char *pTemp;
		pTemp = (char*)malloc(sizeof(char) * ((*(pn + i) * 2) + 1));
		scanf(" %[^\n]s", pTemp);
		for(j = 0 ; j < *(pn + i) ; j++)
		{
			*(*(pT + i) + j) = *(pTemp + 2 * j + 1) - '0';
		}
		
		for(k = 0 ; k < *(pn + i) * 2 + 1 ; k++) // OUTPUT FOR CHECK
		{
			printf("*(pTemp + %d) = %c\n", k, *(pTemp + k));
		}
		
		free(pTemp);
	}
	
///////////////////////////// OUTPUT FOR CHECK /////////////////////////////
	printf("T = %d\n", T);
	for(i = 0; i < T ; i++)
	{
		printf("(pn + %d) = %d\n", i, *(pn + i));
	}
	for(i = 0 ; i < T ; i++)
	{
		for(j = 0 ; j < *(pn + i) ; j++)
		{
			printf("*(*(pT + %d) + %d) = %d\n", i, j, *(*(pT + i) + j));
		}
	}
	
	free(pn); // *pn �����Ҵ� ����
	free(pp); // *pp �����Ҵ� ����
	for(i = 0 ; i < T ; i++) // *pT �����Ҵ� ����
	{
		free(*(pT + i));
	}

	return 0;
}

void R(int *array, int *length)
{
	int i;
	int tempR;
	if(*length != 0)
	{
		for(i = 0 ; i < *length / 2 ; i++)
		{
			tempR = *(array+i);
			*(array + i) = *(array + *length - i - 1);
			*(array + *length -i -1) = tempR;
		}
	}
}

void D(int *array, int *length)
{
	int i;
	if(*length != 0)
	{
		for(i = 0 ; i < *length ; i++)
		{
			*(array + i) = *(array + i + 1);
		}
		*length--;
	}
	else if(*length == 0)
	{
		printf("error\n"); // ***�������**** 
	}
}

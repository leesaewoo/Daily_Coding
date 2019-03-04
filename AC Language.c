#include <stdio.h>
#include <stdlib.h>


//TO DO LIST//
// 1. 배열의 원소가 0~100 사이의 정수 이므로, 원소가 두자리, 세자리 일 때 pT 값 구하는 알고리즘 짜야함 
// 2. 현재 p값을 자연수로 받고 있는데, p값은 R과D로 이루어진 문자열임, 수정해야함 
// 3. 입력된 p값에 따라 해당 case의 배열을 연산하는 알고리즘과 최종 OUTPUT 알고리즘 짜야함 

void R(int *array, int *length); // R(뒤집기) 함수 선언
void D(int *array, int *length); // D(버리기) 함수 선언 

int main(void)
{
	int i, j, k;
	int T; // T는 Test case
	while(1)
	{
		scanf("%d",&T);
		if(T >= 0 && T <= 100)
		{
			break;
		}
	}
	
	int *pn;
	pn = (int*)malloc(sizeof(int) * T); // 각 test case 의 n 값을 넣을 공간(배열) 할당 
	int *pp;
	pp = (int*)malloc(sizeof(int) * T); // 각 test case 의 p 값을 넣을 공간(배열) 할당 
	
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
	
	free(pn); // *pn 동적할당 해제
	free(pp); // *pp 동적할당 해제
	for(i = 0 ; i < T ; i++) // *pT 동적할당 해제
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
		printf("error\n"); // ***에러출력**** 
	}
}

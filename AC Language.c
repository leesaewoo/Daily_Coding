#include <stdio.h>


//TO DO LIST//
// 1. *pn, *pp, *pT 에 제대로 입력됐는지 확인하는 코드 짜야함
// 2. T == 1 일 때 *pn에 값 입력 시 체크용 아웃풋 무한루프 현상 발생
// 3. line 31~43 에서 에러 발생 

void R(int *array, int *length); // R(뒤집기) 함수 선언
void D(int *array, int *length); // D(버리기) 함수 선언 

int main(void)
{
	int i, j;
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
		scanf("%d", *(pp + i));
		scanf("%d", *(pn + i));
		*(pT + i) = (int*)malloc(sizeof(int) * *(pn + i));
		char *pTemp = (char*)malloc(sizeof(char) * ((*(pn + i) * 2) + 1));
		scanf("%[^\n]s", *pTemp);
		for(j = 0 ; j < *(pn + i) ; j++)
		{
			*(*(pT + i) + j) = *(pTemp + 2 * j + 1) - '0';
		}
		free(pTemp);
	}
	
///////////////////////////// OUTPUT FOR CHECK /////////////////////////////
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
			if(i == *length - 1)
			{
				*(array + i + 1) = 0;
			}
		}
		*length--;
	}
	else if(*length == 0)
	{
		printf("error\n"); // ***에러출력**** 
	}
}

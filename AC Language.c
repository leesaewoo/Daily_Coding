#include <stdio.h>
#include <stdlib.h>

//TO DO LIST//

void R(int *array, int *length); // R(뒤집기) 함수 선언
void D(int *array, int *length); // D(버리기) 함수 선언 

int main(void)
{
	int i, j, k;
	int errorcheck = 0;
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
	char **pp = (char**)malloc(sizeof(char) * T); // 각 test case 의 p 값을 넣을 공간(배열) 할당 
	
	int **pT = (int**)malloc(sizeof(int) * T);
	for(i = 0 ; i < T ; i++)
	{
		*(pp + i) = (char*)malloc(sizeof(char) * 100000);
		scanf(" %[^\n]s", *(pp + i)); // 1 <= pp <= 100000
		scanf("%d", (pn + i)); // 0 <= pn <= 100000
		*(pT + i) = (int*)malloc(sizeof(int) * *(pn + i));
		char *pTemp;
		pTemp = (char*)malloc(sizeof(char) * ((*(pn + i) * 4) + 1));
		scanf(" %[^\n]s", pTemp); // 1 <= 배열에 들어가는 수 <=100
		int temp = 0;
		for(j = 1, k = 0 ; k < *(pn + i) ; k++) // 입력받은 배열값을  **pT(2차원 배열)에 입력 
		{
			if(*(pTemp + j) != ',')
			{
				if(*(pTemp + j + 1) == ',' || *(pTemp + j + 1) == ']')
				{
					temp += (*(pTemp + j) - '0');
					*(*(pT + i) + k) = temp;
					temp = 0;
					j += 2;
				}
				else if(*(pTemp + j + 2) == ',' || *(pTemp + j + 2) == ']')
				{
					temp += (*(pTemp + j) - '0') * 10;
					temp += (*(pTemp + j + 1) - '0');
					*(*(pT + i) + k) = temp;
					temp = 0;
					j += 3;
				}
				else if(*(pTemp + j + 3) == ',' || *(pTemp + j + 3) == ']')
				{
					*(*(pT + i) + k) = 100;
					j += 4;
				}
			}
			else if(*(pTemp + j) == ']')
			{
				break;
			}
		}

		free(pTemp);
	}
	
	
	for(i = 0 ; i < T ; i++)
	{
		//i 번째 케이스에 대해서 pp 함수 순차적 수행 후 출력 (error 나올 시 이후 함수 수행 중단)
		for(j = 0; ; j++)
		{
			if(*(*(pp + i) + j) == 'R')
			{
				R(*(pT + i), pn + i);
			}
			else if(*(*(pp + i) + j) == 'D' && *(pn + i) != 0)
			{
				D(*(pT + i), pn + i);
			}
			else if(*(*(pp + i) + j) == 'D' && *(pn + i) == 0)
			{
				errorcheck = 1; //error 출력하는 스위치 ON 
				break;
			}
			else if(*(*(pp + i) + j + 1) == 0)
			{
				break;
			}
		}

		if(errorcheck == 1)	// pp 함수를 모두 수행한 배열 출력
		{
			printf("error\n");
			errorcheck = 0;
		}
		else if(errorcheck == 0 && *(pn + i) == 0)
		{
			printf("[]\n");
		}
		else if(errorcheck == 0)
		{
			printf("[");
			for(j = 0 ; j < *(pn + i) ; j++) 
			{
				if(j == *(pn + i) - 1)
				{
				printf("%d", *(*(pT + i) + j));
				printf("]\n");
				break;
				}
				printf("%d", *(*(pT + i) + j));
				printf(",");
			}
		}
	}

///////////////////////////// OUTPUT FOR CHECK /////////////////////////////
	printf("pT = %d\n",*(*(pT)+2));
	printf("T = %d\n", T);
	for(i = 0 ; i < T ; i++)
	{
		for(j = 0 ; ; j++)
		{
			if(*(*(pp + i) + j) != 'R' && *(*(pp + i) + j) != 'D')
			{
				i = T;
				break;
			}
			else
			{
				printf("*(*(pp + %d) + %d) = %c\n", i, j, *(*(pp + i) + j));
			}
		}
	}
	for(i = 0 ; i < T ; i++)
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
///////////////////////////// OUTPUT FOR CHECK /////////////////////////////
	
	free(pn); // *pn 동적할당 해제

	for(i = 0 ; i < T ; i++) // *pT, *pp 동적할당 해제
	{
		free(*(pT + i));
		free(*(pp + i));
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
	if(*length != 0) // 이 조건문이 필요하지 않을듯?
	{
		for(i = 0 ; i < *length ; i++)
		{
			if(i == *length - 1)
			{
			*(array + i) = *(array + i + 1);
			*(array + i + 1) = 0;
			break;
			}
			*(array + i) = *(array + i + 1);
		}
		(*length)--;
	}
}

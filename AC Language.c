#include <stdio.h>
#include <stdlib.h>


void R(int *length); // R(뒤집기) 함수 선언
void D(int *length); // D(버리기) 함수 선언 

int R_check = 1;
int D_check_s; // test case가 바뀔 때 마다 0으로 초기화 해야함 
int D_check_e; // 해당 test case 의 *pn 값으로 초기화 해야함 

int main(void)
{
	int i, j, k;
	int error_check = 0;

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
		j = 1;
		for(k = 0 ; k < *(pn + i) ; k++) // 입력받은 배열값을  **pT(2차원 배열)에 입력 
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
		free(pTemp); // *pTemp 동적할당 해제 
	}
	
	
	//i 번째 케이스에 대해서 pp 함수 순차적 수행 후 출력 (error 나올 시 이후 함수 수행 중단)
	for(i = 0 ; i < T ; i++)
	{
		R_check = 1;
		D_check_s = 0;
		D_check_e = *(pn + i);
		
		for(j = 0; ; j++)
		{
			if(*(*(pp + i) + j) == 'R')
			{
				R(pn + i);
			}
			else if(*(*(pp + i) + j) == 'D' && *(pn + i) != 0)
			{
				D(pn + i);
			}
			else if(*(*(pp + i) + j) == 'D' && *(pn + i) == 0)
			{
				error_check = 1; //error 출력하는 스위치 ON 
				break;
			}
			else if(*(*(pp + i) + j + 1) == 0)
			{
				break;
			}
		}

		if(error_check == 1)	// pp 함수를 모두 수행한 배열 출력
		{
			printf("error\n");
			error_check = 0;
		}
		else if(error_check == 0 && *(pn + i) == 0)
		{
			printf("[]\n");
		}
		else if(error_check == 0 && R_check == 1)
		{
			printf("[");
			for(j = D_check_s ; j < D_check_e ; j++) 
			{
				if(j == D_check_e - 1)
				{
					printf("%d", *(*(pT + i) + j));
					printf("]\n");
					break;
				}
				else
				{
					printf("%d", *(*(pT + i) + j));
					printf(",");
				} 
			}
		}
		else if(error_check == 0 && R_check == -1)
		{
			printf("[");
			for(j = D_check_e - 1 ; j >= D_check_s ; j--) 
			{
				if(j == D_check_s)
				{
				printf("%d", *(*(pT + i) + j));
				printf("]\n");
				break;
				}
				else
				{
					printf("%d", *(*(pT + i) + j));
					printf(",");
				}
			}
		}
	}
	
	free(pn); // *pn 동적할당 해제

	for(i = 0 ; i < T ; i++) // *pT, *pp 동적할당 해제
	{
		free(*(pT + i));
		free(*(pp + i));
	}

	return 0;
}

void R(int *length) // timecomplexity = O(1)
{
	if(*length != 0)
	{
		R_check *= -1; // 하나의 test case 가 끝날 때 1로 초기화 해야함
	}
}

void D(int *length) // timecomplexity = O(1)
{
	if(R_check == -1)
	{
		D_check_e--;
		*length = *length - 1;
	}
	else if(R_check == 1)
	{
		D_check_s++;
		*length = *length - 1;
	}
}

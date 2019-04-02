#include <stdio.h>
#include <stdlib.h>

int *pa;
void BUFFERCLEAR(void); // 버퍼 비우는 함수 
void MERGE(int N, int X,int real_N); // MERGE 정렬 함수 

int main(void)
{
	int N;
	scanf("%d", &N);
		
	pa = malloc(sizeof(int) * N);
	
	int i;
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &*(pa + i));
		BUFFERCLEAR;
	}
	
	MERGE(N, 2, N);
	
	for(i = 0 ; i < N ; i++)
	{
		printf("%d\n", *(pa + i));
	}
	
	free(pa);
	return 0;
}

void BUFFERCLEAR(void)
{
	while(getchar() != '\n');
}

void MERGE(int N, int X, int real_N) // real_N값은 고정값(정수의 개수)
{
	int T[real_N]; //MERGE정렬 한번 끝날 때 최종 정렬된 값이 저장, *pa 로 값 복사 
	int A[X]; // 정렬하면서 합쳐지는 값들이 임시 저장될 배열 
	int n; // 정렬하면서 합쳐지는 값들이 몇 덩어리로 나눠질지 
	int check; // 체크용 변수 
	int max1, max2; // 포인터의 최대 이동 가능 횟수 
	int count = real_N; // 합쳐지고 남은 자릿수를 카운트 하는 변수 
	int temp; // 4칸에 들어갈 숫자의 개수가 칸의 수 보다 적을 때 숫자의 갯수가 X 대신 들어가는 변수 
	int check_X; // count - X < 0 일때 1이 되는 변수, 평소엔 0 //체크용 변수임 
	
	if(N % 2 == 1)
	{
		n = (N + 1) / 2;
	}
	else
	{
		n = N / 2;
	}
	
	int ptr1; // 좌측 인덱스 포인터 
	int ptr2; // 우측 인덱스 포인터 
	int i, j;
	
	for(i = 0 ; i < n ; i++)
	{
		max1 = (X / 2) - 1;
		max2 = (X / 2) - 1;
		ptr1 = i * X;
		ptr2 = ptr1 + (X / 2);
		check = 0;
		check_X = 0;
		temp = X;
		
		if(count - X > 0)
		{
			count -= X;
		}
		else if(count - X < 0)
		{
			temp = count;
			check_X = 1;
		}
		
		for(j = 0 ; j < temp ; j++)
		{
			if(ptr2 >= real_N)
			{
				check = 2;
			}
			
			if(check == 1)
			{
				A[j] = *(pa + ptr2);
				ptr2++;
			}
			else if(check == 2)
			{
				A[j] = *(pa + ptr1);
				ptr1++;
			}
			else if(*(pa + ptr1) <= *(pa + ptr2))
			{
				A[j] = *(pa + ptr1);
				
				if(max1 != 0)
				{
					max1--;
					ptr1++;
				}
				else if(max1 == 0)
				{
					check = 1;
				}
			}
			else if(*(pa + ptr1) >= *(pa + ptr2))
			{
				A[j] = *(pa + ptr2);
				
				if(max2 != 0)
				{
					max2--;
					ptr2++;
				}
				else if(max2 == 0)
				{
					check = 2;
				}
			}
		}
		
		if(check_X == 1)
		{	
			for(j = 0 ; j < count ; j++)
			{
				T[i * X + j] = A[j];
			}
		}
		else if(check_X == 0)
		{
			for(j = 0 ; j < X ; j++)
			{
				T[i * X + j] = A[j];
			}
		}
	}
	
	for(i = 0 ; i < real_N ; i++)
	{
		*(pa + i) = T[i];
	}
	
	if(n != 1 && n % 2 == 0)
	{
		MERGE(n, X * 2, real_N);
	}
	else if(n != 1 && n % 2 == 1)
	{
		MERGE(n + 1, X * 2, real_N);
	}
}

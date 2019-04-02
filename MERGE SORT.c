#include <stdio.h>
#include <stdlib.h>

int *pa;
void BUFFERCLEAR(void); // ���� ���� �Լ� 
void MERGE(int N, int X,int real_N); // MERGE ���� �Լ� 

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

void MERGE(int N, int X, int real_N) // real_N���� ������(������ ����)
{
	int T[real_N]; //MERGE���� �ѹ� ���� �� ���� ���ĵ� ���� ����, *pa �� �� ���� 
	int A[X]; // �����ϸ鼭 �������� ������ �ӽ� ����� �迭 
	int n; // �����ϸ鼭 �������� ������ �� ����� �������� 
	int check; // üũ�� ���� 
	int max1, max2; // �������� �ִ� �̵� ���� Ƚ�� 
	int count = real_N; // �������� ���� �ڸ����� ī��Ʈ �ϴ� ���� 
	int temp; // 4ĭ�� �� ������ ������ ĭ�� �� ���� ���� �� ������ ������ X ��� ���� ���� 
	int check_X; // count - X < 0 �϶� 1�� �Ǵ� ����, ��ҿ� 0 //üũ�� ������ 
	
	if(N % 2 == 1)
	{
		n = (N + 1) / 2;
	}
	else
	{
		n = N / 2;
	}
	
	int ptr1; // ���� �ε��� ������ 
	int ptr2; // ���� �ε��� ������ 
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

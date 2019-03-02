#include <stdio.h>

void R(int *array, int length); // R(뒤집기) 함수 선언
int D(int *array, int length); // D(버리기) 함수 선언 

int main(void)
{
	int i;
	int A[5] = {1, 2, 3, 4, 5};
	int *p = A;
	
	R(p, 5);
	
	for(i = 0 ; i < 5 ; i++)
	{
		printf("%d ",*(p + i));
	}
	return 0;
}

void R(int *array, int length)
{
	int i;
	int tempR;
	if(length != 0)
	{
		for(i = 0 ; i < length / 2 ; i++)
		{
			tempR = *(array+i);
			*(array + i) = *(array + length - i - 1);
			*(array + length -i -1) = tempR;
		}
	}
}

int D(int *array, int length)
{
	
}

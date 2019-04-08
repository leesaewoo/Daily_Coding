#include <stdio.h>
#include <stdlib.h>


int *pa;
void BUFFERCLEAR(void);
void QUICKSORT(int start, int end);

int main(void)
{
	int N;
	scanf("%d", &N); BUFFERCLEAR;
	
	pa = malloc(sizeof(int) * N);
	
	int i;
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &*(pa + i));
		BUFFERCLEAR;
	}
	
	// check
	for(i = 0 ; i < N ; i++)
	{
		printf("*(pa + %d) = %d\n", i, *(pa + i));
	}
	// check
	
	QUICKSORT(0, N - 1);
	
	for(i = 0 ; i < N ; i++)
	{
		printf("end *(pa + %d) = %d\n", i, *(pa + i));
	}
	
	return 0;
}

void BUFFERCLEAR(void)
{
	while(getchar() != '\n');
}

void QUICKSORT(int start, int end)
{
	if(start != end)
	{
		int N = end - start + 1;
		int pivot_index = start;
		int temp;
		int ptr_max, ptr_min;
		int i, j;
		
		while(1)
		 {
			for(i = start ; i < end + 1 ; i++)
			{
			 	if(*(pa + pivot_index) < *(pa + i))
			 	{
			 		ptr_max = i;
			 		printf("ptr_max = %d\n", ptr_max);
			 		break;
				}
				else if(i == end)
				{
					ptr_max = pivot_index;
					printf("ptr max = pivot_index : ptr_max = %d\n", pivot_index);
				}
			}
			 
			for(i = end ; i >= start ; i--)
			{
			 	if(*(pa + pivot_index) > *(pa + i))
			 	{
			 		ptr_min = i;
			 		printf("ptr_min = %d\n", ptr_min);
			 		break;
				}
				else if(i == start)
				{
					ptr_min = pivot_index;
					printf("ptr_min = pivot_index : ptr_min = %d\n", pivot_index);
				}
			}
			
			if(ptr_min > ptr_max)
			{
			 	temp = *(pa + ptr_min);
			 	*(pa + ptr_min) = *(pa + ptr_max);
			 	*(pa + ptr_max) = temp;
			 	printf("ptr_min <-> ptr_max : %d <-> %d\n",ptr_min, ptr_max); 
			}
			else if(ptr_min < ptr_max && pivot_index <= ptr_min)
			{
			 	temp = *(pa + pivot_index);
			 	*(pa + pivot_index) = *(pa + ptr_min);
			 	*(pa + ptr_min) = temp;
			 	printf("pivot_index <-> ptr_min : %d <-> %d\n", pivot_index, ptr_min);
			 	pivot_index = ptr_min;
			 	break;
			}
			else
			{
			 	printf("else\n");
			 	break;
			}
		}
		
		if(pivot_index - 1 >= start)
		{
			printf("QUICKSORT(start, pivot_index - 1) = (%d, %d)\n", start, pivot_index - 1);
			QUICKSORT(start, pivot_index - 1);
		}
		
		if(pivot_index + 1 <= end)
		{
			printf("QUICKSORT(pivot_index + 1 , end) = (%d, %d)\n", pivot_index + 1, end);
			QUICKSORT(pivot_index + 1, end);
		}
	}
	else if(start == end);
	{
		printf("start == end : %d == %d\n", start, end);//¨ú¨¡©ö¡ì¡ÆI¥ì¥ì¨úECO 
	}
}

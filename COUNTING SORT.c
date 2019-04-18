#include <stdio.h>

int main(void)
{
	int TOTAL_ARRAY[10001] = {0};
	
	int N;
	scanf("%d", &N);
	
	int i, j;
	int check;
	
	for(i = 0 ; i < N ; i++)
	{
		scanf("%d", &check);
		TOTAL_ARRAY[check]++;
	}
	
	int count = 0;
	
	for(i = 0 ; i < 10001 ; i++)
	{
		if(TOTAL_ARRAY[i] >= 1)
		{
			for(j = 0 ; j < TOTAL_ARRAY[i] ; j++)
			{
				count++;
				printf("%d\n", i);
				if(count == N)
				{
					return 0;
				}
			}
		}
	}
	
	return 0;
}

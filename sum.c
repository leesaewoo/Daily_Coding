#include <stdio.h>

int main(void)
{
	int number;
	int i = 1;
	int j;
	int k = 0;
	
	
	while(i != 0)
	{
		printf("합칠 숫자의 자릿수(N)를 입력해주세요.\nN = ");
		scanf("%d",&number);
	
		if(number>100 || number<=0)
		{
			printf("N은 1이상 100이하여야 합니다.");
		
		}
		else
		{
			i = 0;
		}
	}
	
	char array[number];
	char *p = array;
	
	printf("합칠 숫자를 자릿수에 맞게 입력해주세요.\n");
	
	scanf("%s",p);
	
	for(j = 0; j < number; j++)
	{
		k = k + *(p+j) - '0';
	}
	
	printf("각 자릿수를 더한 값은 %d 입니다.",k);
	
	
	return 0;
}

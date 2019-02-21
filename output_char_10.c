#include <stdio.h>

int main(void)
{
	char a[100];
	char*p = a;
	int i,j;
	
	printf("단어를 입력하세요\n");
	scanf("%s",p);
	
	for(j=0;j<10;j++)
	{
		for(i=0;i<10;i++)
		{
			printf("%c", *(p+10*j+i));
			if(*(p+10*j+i) == 0)
			{
				j=10;
			}
		}
		printf("\n");
	}
	
	return 0;
}

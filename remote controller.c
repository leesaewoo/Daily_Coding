#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Channel_Count(int x); // 원하는 채널 자릿수 구하는 함수 

int main(void)
{
	int i;
	int channel_int, channel_count, button_count;
	char *channel_char;
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p1 = array;
	scanf("%d", &channel_int); // 원하는 채널 입력 
	scanf("%d", &button_count); // 고장난 버튼의 갯수 입력 
	
	channel_count = Channel_Count(channel_int);
	
	char out[(button_count*2)-1];
	char *p2 = out;
	scanf(" %[^\n]s",p2); // 고장난 버튼의 번호 입력 

	for(i=0;i<button_count;i++)
	{
		*(p1+(*(p2+(2*i))-'0')) = -1; // array 배열에서 고장난 버튼의 값을 -1로 바꿈 
	}

	
	printf("%d\n",channel_count);

	for(i=0;i<10;i++) // array에서 잘 빠지나 확인용 
	{
		printf("array(%d) = %d\n",i,*(p1+i));
	}

	for(i=0;i<(button_count*2)-1;i++) // out 확인용 
	{
		printf("out(%d) = %c\n",i,*(p2+i));	
	} 

	return 0;
}

int Channel_Count(int x)
{
	if(x / 100000 >= 1)
	{
		return 6;
	}
	else if(x / 10000 >=1)
	{
		return 5;
	}
	else if(x / 1000 >=1)
	{
		return 4;
	}
	else if(x / 100 >=1)
	{
		return 3;
	}
	else if(x / 10 >=1)
	{
		return 2;
	}
	else
	{
		return 1;
	}
}



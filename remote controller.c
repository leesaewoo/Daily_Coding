#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Channel_Count(int x); // ���ϴ� ä�� �ڸ��� ���ϴ� �Լ� 

int main(void)
{
	int i;
	int channel_int, channel_count, button_count;
	char *channel_char;
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p1 = array;
	scanf("%d", &channel_int); // ���ϴ� ä�� �Է� 
	scanf("%d", &button_count); // ���峭 ��ư�� ���� �Է� 
	
	channel_count = Channel_Count(channel_int);
	
	char out[(button_count*2)-1];
	char *p2 = out;
	scanf(" %[^\n]s",p2); // ���峭 ��ư�� ��ȣ �Է� 

	for(i=0;i<button_count;i++)
	{
		*(p1+(*(p2+(2*i))-'0')) = -1; // array �迭���� ���峭 ��ư�� ���� -1�� �ٲ� 
	}

	
	printf("%d\n",channel_count);

	for(i=0;i<10;i++) // array���� �� ������ Ȯ�ο� 
	{
		printf("array(%d) = %d\n",i,*(p1+i));
	}

	for(i=0;i<(button_count*2)-1;i++) // out Ȯ�ο� 
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



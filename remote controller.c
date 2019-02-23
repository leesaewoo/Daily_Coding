#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Channel_Count(int x); // ���ϴ� ä�� �ڸ��� ���ϴ� �Լ�
int Compare_100(); //100���� +-�θ� ���ϴ� ä�� ���ߴ� ��� 

int main(void)
{
	int i, j, temp;
	int channel_int; //���ϴ� ä��
	int channel_count; //���ϴ� ä���� �ڸ���
	int button_count; // ���峭 ��ư�� ���� 
	int cmp_plus;
	int cmp_minus;
 	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *pa = array;

	scanf("%d", &channel_int); // ���ϴ� ä�� �Է� 
	temp = channel_int;
	
	scanf("%d", &button_count); // ���峭 ��ư�� ���� �Է� 
	char out[(button_count*2)-1];
	char *po = out;
	scanf(" %[^\n]s",po); // ���峭 ��ư�� ��ȣ �Է� 
	for(i=0;i<button_count;i++) // array �迭���� ���峭 ��ư�� ���� -1�� �ٲ� 
	{
		*(pa+(*(po+(2*i))-'0')) = -1;
	}
	
	channel_count = Channel_Count(channel_int); // ���ϴ� ä�� �ڸ��� ���ϱ� 	
	char channel_char[channel_count]; // ���ϴ� ä�� char �迭 ���� 
	char *pcc = channel_char;
	for(i=0;i<channel_count;i++) // ���ϴ� ä���� char �迭�� �Է� 
	{
		*(pcc+i) = temp / pow(10,channel_count -1 -i);
		temp -= pow(10,channel_count -1 -i)*(*(pcc+i));
	}

	for(i=0;i<channel_count;i++) // cmp_plus ���ϱ� 
	{
		if(i == channel_count -1)
		{
			if(*(pa+(*(pcc+i))) != -1)
			{
				cmp_plus = 4;
			}
			else
			{
				for(j=1;j<=*(pcc+i);j++)
				{
					if(*(pa+(*(pcc+i)) - j) != -1)
					{
						cmp_plus = 4 + j;
						break;
					}
					
					if(j == *(pcc+i))
					{
						cmp_plus = 500000;
					}
				}
			}
		}
		
		//���⿡ 0 ~ channel_count -2 ���� �Ǻ��� �־���� 
	}

	for(i=0;i<channel_count;i++) // ���ϴ� ä�� char �迭 Ȯ�� 
	{
		printf("channel_char(%d) = %d\n",i,*(pcc+i));
	}

	printf("channel_count = %d\n",channel_count); //ä�� int�� ������ �Լ� ��� 

	for(i=0;i<10;i++) // array���� �� ������ Ȯ�ο� 
	{
		printf("array(%d) = %d\n",i,*(pa+i));
	}

	for(i=0;i<(button_count*2)-1;i++) // out Ȯ�ο� 
	{
		printf("out(%d) = %c\n",i,*(po+i));	
	}
	
	printf("cmp_plus = %d\n",cmp_plus);
	
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

int Compare_100(int x)
{
	return abs(x-100);
}






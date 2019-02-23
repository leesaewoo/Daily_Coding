#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Channel_Count(int x); // 원하는 채널 자릿수 구하는 함수
int Compare_100(); //100에서 +-로만 원하는 채널 맞추는 경우 

int main(void)
{
	int i, j, temp;
	int channel_int; //원하는 채널
	int channel_count; //원하는 채널의 자릿수
	int button_count; // 고장난 버튼의 갯수 
	int cmp_plus;
	int cmp_minus;
 	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *pa = array;

	scanf("%d", &channel_int); // 원하는 채널 입력 
	temp = channel_int;
	
	scanf("%d", &button_count); // 고장난 버튼의 갯수 입력 
	char out[(button_count*2)-1];
	char *po = out;
	scanf(" %[^\n]s",po); // 고장난 버튼의 번호 입력 
	for(i=0;i<button_count;i++) // array 배열에서 고장난 버튼의 값을 -1로 바꿈 
	{
		*(pa+(*(po+(2*i))-'0')) = -1;
	}
	
	channel_count = Channel_Count(channel_int); // 원하는 채널 자릿수 구하기 	
	char channel_char[channel_count]; // 원하는 채널 char 배열 선언 
	char *pcc = channel_char;
	for(i=0;i<channel_count;i++) // 원하는 채널을 char 배열에 입력 
	{
		*(pcc+i) = temp / pow(10,channel_count -1 -i);
		temp -= pow(10,channel_count -1 -i)*(*(pcc+i));
	}

	for(i=0;i<channel_count;i++) // cmp_plus 구하기 
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
		
		//여기에 0 ~ channel_count -2 까지 판별식 넣어야함 
	}

	for(i=0;i<channel_count;i++) // 원하는 채널 char 배열 확인 
	{
		printf("channel_char(%d) = %d\n",i,*(pcc+i));
	}

	printf("channel_count = %d\n",channel_count); //채널 int값 저장한 함수 출력 

	for(i=0;i<10;i++) // array에서 잘 빠지나 확인용 
	{
		printf("array(%d) = %d\n",i,*(pa+i));
	}

	for(i=0;i<(button_count*2)-1;i++) // out 확인용 
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






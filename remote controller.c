#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Channel_Count(int x); // 원하는 채널 자릿수 구하는 함수
int Compare_100(); //100에서 +-로만 원하는 채널 맞추는 경우에 버튼 누른 횟수 구하는 함수 
int Compare_plus_minus_100(); //가장 적게 누른 횟수 구하는 함수 

int main(void)
{
	int i, j, k, l, m, temp, check = 0;
	int channel_int; //원하는 채널
	int channel_count; //원하는 채널의 자릿수
	int button_count; // 고장난 버튼의 갯수 
	int cmp_plus = 0;
	int cmp_plus_count = 0;
	int cmp_minus = 0;
	int cmp_minus_count = 0;
 	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *pa = array;
	int array_max; // 고장난 버튼을 제외하고 가장 큰 버튼 값
	int array_min; // 고장난 버튼을 제외하고 가장 작은 버튼 값
		
	while(1)
	{
		scanf("%d", &channel_int); // 원하는 채널 입력 
		if(channel_int > 500000 || channel_int < 0)
		{
			printf("채널은 0 ~ 500000 사이의 값이어야 합니다.\n");
		}
		else
		{
			temp = channel_int;
			break;
		}
	}
	
	while(1)
	{	
		scanf("%d", &button_count); // 고장난 버튼의 갯수 입력 
		if(button_count > 10 || button_count < 0)
		{
			printf("고장난 버튼의 갯수는 0 ~ 10 사이의 값이어야 합니다.\n");
		}
		else
		{
			break;
		} 
	}
	char out[(button_count*2)-1];
	char *po = out;
	if(button_count != 0)
	{
		scanf(" %[^\n]s",po); // 고장난 버튼의 번호 입력 
	}
	for(i=0;i<button_count;i++) // array 배열에서 고장난 버튼의 값을 -1로 바꿈 
	{
		*(pa+(*(po + 2*i) - '0')) = -1;
	}
	for(i=9;i>0;i--) // array_max 구하는 함수 
	{
		if(*(pa+i) != -1)
		{
			array_max = *(pa+i);
			break;
		}
	}
	for(i=0;i<10;i++) // array_min 구하는 함수 
	{
		if(*(pa+i) != -1)
		{
			array_min = *(pa+i);
			break;
		}
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
		if(channel_count == 1)
		{
			if(*(pa + *pcc) == -1 && *pcc != 0)
			{
				for(i=1;i<*pcc;i++)
				{	
					if(*(pa + *pcc - i) != -1)
					{
						cmp_plus = *(pa + *pcc - i);
						break;
					} 
				}
			}
			else if(*(pa + *pcc) == *pcc)
			{
				cmp_plus = 0;
				break;
			}
			else
			{
				cmp_plus = 9999999;
				break;
			}
			break;
		}
		
		if(i == channel_count -1)
		{
			if(*(pa + *(pcc+i)) != -1)
			{
			cmp_plus += (*(pa + *(pcc+i)));
			}
			else
			{
				for(j=1;j<=*(pcc+i);j++)
				{
					if(*(pa + *(pcc+i) - j) >= 0 && *(pa + *(pcc+i) - j) < 10 && i-j >= 0 && check !=88)
					{
						cmp_plus += (*(pa + *(pcc+i) - j));
						break;
					}
					else if(check == 88) // 한 자릿수 낮은 가장 큰 수에서 ++ 경우 
					{
						cmp_plus = 0;
						
						for(l=1;l<channel_count;l++)
						{
							cmp_plus += pow(10,channel_count - l - 1) * array_max;
						}
						check = 77;
						break;
					}	
				}
			}
		}
		
		// 0 ~ channel_count -2 까지 판별식

		if(*(pa + *(pcc+i)) != -1 && i < channel_count -1 && channel_count != 1)
		{
			cmp_plus += pow(10,channel_count -i - 1) * (*(pa + *(pcc+i)));
		}
		else if(*(pa + *(pcc+i)) == -1 && i < channel_count -1 && channel_count != 1)
		{
			for(j=1;j<=*(pcc+i);j++)
			{
				if (*(pa + *(pcc+i) - j) == 0 && i == 0)
				{
					check = 88;
					break;
				}
				else if(*(pa + *(pcc+i) - j) != -1 && *(pcc+i) - j >= 0 && check != 88)
				{
					cmp_plus += pow(10,channel_count -i -1) * *(pa + *(pcc+i) - j);
					
					for(k=1;channel_count - i - 1 - k >= 0; k++)
					{
						cmp_plus += pow(10,channel_count -i -1 -k) * array_max;
					}
					i = channel_count;
					break;
				}
			}
		}
	}
	if(cmp_plus == channel_int) // cmp_plus_count 구하기
	{
		cmp_plus_count = channel_count;
	}
	else if(check == 77)
	{
		cmp_plus_count = abs(cmp_plus - channel_int) + channel_count - 1;
	}
	else if(check == 88 && button_count == 9)
	{
		cmp_plus_count = channel_int + 1;
	}
	else
	{
		cmp_plus_count = abs(cmp_plus - channel_int) + channel_count;
	}	
	
	
	for(i=0;i<channel_count;i++) // cmp_minus 구하기 
	{
		if(channel_count == 1)
		{
			if(*(pa + *pcc) == -1)
			{
				for(i=1;i<(10 - *pcc);i++ && *pcc != 9)
				{	
					if(*(pa + *pcc + i) != -1)
					{
						cmp_minus = *(pa + *pcc + i);
						break;
					} 
				}
			}
			else if(*(pa + *pcc) == *pcc)
			{
				cmp_minus = 0;
				break;
			}
			else
			{
				cmp_minus = 9999999;
				break;
			}
			break;
		}

		if(i == channel_count -1)
		{
			if(*(pa + *(pcc+i)) != -1)
			{
			cmp_minus += *(pa + *(pcc+i));
			}
			else
			{
				for(j=1;j<(10 - *(pcc+i));j++)
				{
					if(*(pa + *(pcc+i) + j) != -1)
					{
						cmp_minus += (*(pa + *(pcc+i) + j));
						break;
					}
					else // 한 자리 많은 최소값에서 -- 하는 경우 
					{
						cmp_minus = 0;
						
						for(l=0;l<channel_count;l++)
						{
							if(l ==0 && array_min != 0)
							{
								cmp_minus += pow(10,channel_count - l) * array_min;
								check = 7;
							}
							else if(l ==0 && array_min == 0)
							{
								for(m=1;m<10;m++)
								{
									if(*(pa + m) != -1)
									{
										cmp_minus += pow(10,channel_count - l) * *(pa + m);
										check = 7;
									}
									else if(m == 9 && *(pa + m) == -1)
									{
										cmp_minus = 9999999;
										l = channel_count;
										break;
									}
								} 
							}
						}
					}
				}
			}
		}
		
		// 0 ~ channel_count -2 까지 판별식

		if(*(pa + *(pcc+i)) != -1 && i < channel_count -1 )
		{
			cmp_minus += pow(10,channel_count -i - 1) * (*(pa + *(pcc+i)));
		}
		else if(*(pa + *(pcc+i)) == -1 && i < channel_count -1)
		{
			for(j=1;j<(10 - *(pcc + i));j++)
			{
				if(*(pa + *(pcc+i) + j) == -1 && i == 0 && *(pcc+i) + j == 9)
				{
					check = 8;
				}
				else if(*(pa + *(pcc+i) + j) != -1 && *(pcc+i) + j <= 9 )
				{
					cmp_minus += pow(10,channel_count -i -1) * *(pa + *(pcc+i) + j);
					
					for(k=1;channel_count - i - 1 - k >= 0; k++)
					{
						cmp_minus += pow(10,channel_count -i -1 -k) * array_min;
					}
					i = channel_count;
					break;
				}
			}
		}
	}
	if(cmp_minus == channel_int) // cmp_minus_count 구하기
	{
		cmp_minus_count = channel_count;
	}
	else if(check == 7)
	{
		cmp_minus_count = abs(cmp_minus - channel_int) + channel_count + 1;	
	}
	else if(check == 8)
	{
		cmp_minus_count = 999999;
	}
	else
	{
		cmp_minus_count = abs(cmp_minus - channel_int) + channel_count;
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
	
	printf("cmp_plus_count = %d\n",cmp_plus_count);	
	
	printf("cmp_minus = %d\n",cmp_minus);
	
	printf("cmp_minus_count = %d\n",cmp_minus_count);
	
	printf("Compare_100 = %d\n",Compare_100(channel_int));
	
	printf("array_max = %d\narray_min = %d\n",array_max,array_min);
	
	
	printf("채널을 맞출 때 버튼을 가장 적게 누르는 횟수 = %d\n",Compare_plus_minus_100(button_count,cmp_plus_count,cmp_minus_count,Compare_100(channel_int),channel_count));

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

int Compare_plus_minus_100(int b,int p,int m,int c,int cc)
{
	if(b == 10)
	{
		return c;
	}
	else if(b == 0 && c > cc)
	{
		return cc;
	}
	else if(b == 0 && cc > c)
	{
		return c;
	}
	else if(b !=0 && b != 10 && p > m && c > m)
	{
		return m;		
	}
	else if(b !=0 && b != 10 && m > p && c > p)
	{
		return p;		
	}
	else if(b !=0 && b != 10 && m > c && p > c)
	{
		return c;		
	}
	else if(b !=0 && b != 10 && m == p && c > p)
	{
		return p;
	}
	else if(b !=0 && b != 10 && m == p && p > c)
	{
		return c;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Channel_Count(int x); // 원하는 채널 자릿수 구하는 함수
int Compare_100(); //100에서 +-로만 원하는 채널 맞추는 경우에 버튼 누른 횟수 구하는 함수 
int Compare_plus_minus_100(); //가장 적게 누른 횟수 구하는 함수 

// TO DO LIST (20190301)
// 293 line .. 첫째자리 && channel_count = 6 일때 
 
int main(void)
{
	int i, j, k, L, m, temp, counter = 0;
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
	int array_min1, array_min2 = -1; // 고장난 버튼을 제외하고 가장 작은 버튼 값
	int button_push; // 원하는 채널을 보기 위해 가장 적게 버튼을 누른 횟수 

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
	for(i=0;i<10;i++) // array_min1, array_min2 구하는 함수 
	{
		if(*(pa+i) != -1 && array_min1 == -1)
		{
			array_min1 = *(pa+i);
		}
		else if(*(pa+i) != -1 && array_min1 != -1)
		{
			array_min2 = *(pa+i);
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



	// 공통사항 (숫자 버튼을 누르는 행동을 취할 때 counter++ (+-는 제외)) 

	if(button_count == 0) // 고장난 버튼이 없을 때
	{
		printf("%d", channel_count); // button_push = channel_count 
	}
	else if(button_count == 10) // 버튼이 모두 고장났을 때
	{
		printf("%d", Compare_100(channel_int)); // Compare_100(channel_int)
	}
	else if(button_count == 9 && *pa == 0) // 버튼이 0 빼고 모두 고장났을 때
	{
		counter = 1; //버튼은 무조건 한번만 누르는거 (0) 
		button_push = counter + channel_int;
		if(button_push >= Compare_100(channel_int))
		{
			printf("%d", Compare_100(channel_int));
		}
		else
		{
			printf("%d", button_push);
		}
		
	}
	else // 그 외의 경우
	{
		counter = 0;
		
		for(i=0 ; i<channel_count ; i++) //cmp_plus
		{
			if(i == 0)
			{
				if(*(pa + *pcc) != -1) // 첫 번째 자리는 같거나 
				{
					cmp_plus += pow(10, channel_count - 1) * *(pa + *pcc);
					counter++;
				}
				else if(*(pa + *pcc) == -1)
				{
					for(j = 1 ; j <= *pcc ; j++)
					{
						if(*(pa + *pcc - j) != -1 && j != *pcc) // 작은 수 중 가장 큰 수 
						{
							cmp_plus += pow(10, channel_count -1) * *(pa + *pcc - j);
							counter++;
							if(channel_count > i + 1)
							{
								for(k = channel_count -2 ; k >=0 ; k--)
								{
									cmp_plus += pow(10, k) * array_max;
									counter++;
								}								
							}
							cmp_plus_count = abs(cmp_plus - channel_int) + counter;
							i = channel_count;
							break;
						}
						else if(j == *pcc) // 첫 번째 자리에 가능한 수가 0보다 작거나 같을 경우 
						{
							for(k = channel_count - i - 2 ; k >= 0  ; k--)
							{
								cmp_plus += pow(10, k) * array_max;
								counter++;
							}
							cmp_plus_count = abs(cmp_plus - channel_int) + counter;
							i = channel_count;
						}
					}
				}
			}
			else // 나머지 자리는 같거나 작은 수 중 가장 큰 수 
			{
				if(*(pa + *(pcc + i)) != -1) // 같을 때 
				{
					cmp_plus += pow(10, channel_count - i - 1) * *(pa + *(pcc + i));
					counter++;
				}
				else if(*(pa + *(pcc + i)) == -1) 
				{
					for(j = 1 ; j <= *(pcc + i) ; j++)
					{
						if(*(pa + *(pcc + i) - j) != -1 && j != *(pcc + i)) // 작은 수 중 가장 큰 수 
						{
							cmp_plus += pow(10, channel_count - i -1) * *(pa + *(pcc + i) - j);
							counter++;
							if(channel_count > i + 1)
							{
								for(k = channel_count - i -2 ; k >=0 ; k--)
								{
									cmp_plus += pow(10, k) * array_max;
									counter++;
								}								
							}
							cmp_plus_count = abs(cmp_plus - channel_int) + counter;
							i = channel_count;
							break;							
						}
					}
				}
			}
		}
		cmp_plus_count = abs(cmp_plus - channel_int) + counter; //for문 끝나고 계산 
		
		counter = 0;
		
		for(i=0 ; i<channel_count ; i++) //cmp_minus
		{
			if(i == 0)
			{
				if(*(pa + *pcc) != -1) // 첫 번째 자리는 같거나 
				{
					cmp_minus += pow(10, channel_count - 1) * *(pa + *pcc);
					counter++;
				}
				else if(*(pa + *pcc) == -1 && channel_count != 6) // 채널이 6자리가 아닐 때 
				{
					for(j = 1 ; j <= 9 - *pcc ; j++)
					{
						if(*(pa + *pcc + j) != -1) // 큰 수 중 가장 작은 수 
						{
							cmp_minus += pow(10, channel_count -1) * *(pa + *pcc + j);
							counter++;
							if(channel_count > 1)
							{
								for(k = channel_count -2 ; k >=0 ; k--)
								{
									cmp_minus += pow(10, k) * array_min1;
									counter++;
								}								
							}
							cmp_minus_count = abs(cmp_minus - channel_int) + counter;
							i = channel_count;
							break;
						}
						else if(*(pa + *pcc + j) == -1 && j == 9 - *pcc) // 첫 번째 자리에 가능한 수가 9보다 크거나 같은 수가 없을 경우
						{
							if(channel_count == 5) // 채널의 자릿수가 5일 경우 채널의 최대치가 500000임을 유의 
							{
								for(k = 0 ; k < 6  ; k++)
								{
									if(*(pa +*(pcc + i) + k) != -1 && k != 5) // 맨 앞자리가 5 미만일 경우 
									{
										for(L = 0 ; L <= channel_count ; L++)
										{
											cmp_minus += pow(10, channel_count - L) * *(pa + *(pcc + i) +k);
											counter++;									
										}
										cmp_minus_count = abs(cmp_minus - channel_int) + counter;
										i = channel_count;
										break;
									}
									else if(*(pa + *(pcc + i) + k) != -1 && k == 5) // 맨 앞자리가 5일 경우 
									{
										if(array_min1 == 0)
										{
											cmp_minus = 500000;
											counter = 6;
											cmp_minus_count = abs(cmp_minus - channel_int) + counter;
											i = channel_count;
											break;
										}
									}
									else if(*(pa + *(pcc + i) + k) == -1 && k == 5) // 맨 앞자리가 5보다 클 경우
									{
										cmp_minus_count = 9999999;
										i = channel_count;
										break;										
									} 
								}
								cmp_minus_count = abs(cmp_minus - channel_int) + counter;
								i = channel_count;								
							}
							else
							{
								for(k = channel_count ; k < channel_count ; k++)
								{
									if(k == channel_count)
									{
										cmp_minus += pow(10, k) * array_min2;
										counter++;									
									}
									else
									{
										cmp_minus += pow(10, k) * array_min1;
										counter++;
									}
								}
								cmp_minus_count = abs(cmp_minus - channel_int) + counter;
								i = channel_count;
							}
							break;
						}
					}
				}
				else if(*(pa + *pcc) == -1 && channel_count == 6) // 채널이 6자리 일 때 
				{
					
				}
			}
			else // 나머지 자리는 같거나 작은 수 중 가장 큰 수 
			{
				if(*(pa + *(pcc + i)) != -1) // 같을 때 
				{
					cmp_minus += pow(10, channel_count - i - 1) * *(pa + *(pcc + i));
					counter++;
				}
				else if(*(pa + *(pcc + i)) == -1) 
				{
					for(j = 1 ; j <= *(pcc + i) ; j++)
					{
						if(*(pa + *(pcc + i) - j) != -1 && j != *(pcc + i)) // 작은 수 중 가장 큰 수 
						{
							cmp_minus += pow(10, channel_count - i -1) * *(pa + *(pcc + i) - j);
							counter++;
							if(channel_count > i + 1)
							{
								for(k = channel_count - i -2 ; k >=0 ; k--)
								{
									cmp_minus += pow(10, k) * array_max;
									counter++;
								}								
							}
							cmp_minus_count = abs(cmp_minus - channel_int) + counter;
							i = channel_count;
							break;							
						}
					}
				}
			}
		}
		cmp_minus_count = abs(cmp_minus - channel_int) + counter; //for문 끝나고 계산 
	}
 

			//첫째 자리는  같거나, 큰 수 중 가장 작은 수
			//나머지 자리는 누를수 있는 수 중 가장 작은 수로 
			//첫째 자리에 가능한 수가 9보다 큰 경우 
				//원하는 채널보다 한 자릿수 많은 채널에서 -- 
				//첫째 자리는 0이 아닌 가장 작은 수
				//나머지 자리는 누를 수 있는 수 중 가장 작은 수 (0도 가능) 
		//Compare_100(channel_int) 



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
	
	printf("array_max = %d\narray_min1 = %d\narray_min2 = %d\n",array_max,array_min1,array_min2);
	
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











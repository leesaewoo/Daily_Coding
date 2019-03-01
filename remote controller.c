#include <stdio.h>
#include <math.h>

int Channel_Count(int x); // 원하는 채널 자릿수 구하는 함수
int Compare_100(); //100에서 +-로만 원하는 채널 맞추는 경우에 버튼 누른 횟수 구하는 함수 
int Compare_plus_minus_100(); //가장 적게 누른 횟수 구하는 함수 

// https://www.acmicpc.net/problem/1107 해당 페이지 에서는 채널이 무한대이나, 
// 여기서는 0 이상 500000 이하로 제한하였다.
 
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
	int array_min1 = -1; // 고장난 버튼을 제외하고 가장 작은 버튼 값
	int array_min2 = -1; // 고장난 버튼을 제외하고 가장 작은 버튼 값
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
			if(i == 9 && array_min1 == -1)
			{
				array_min1 = *(pa+i);
				array_min2 = array_min1;
				break;
			}
			else if(button_count == 9)
			{
				array_min1 = *(pa+i);
				array_min2 = array_min1;
				break;
			}
			else
			{
				array_min1 = *(pa+i);		
			}
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
		if(channel_count > Compare_100(channel_int))
		{
			printf("%d", Compare_100(channel_int));
		}
		else
		{
			printf("%d", channel_count);
		}
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
				else if(*(pa + *pcc) == -1 && *pcc != 0) // 같지않으면 
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
							i = channel_count;
							break;
						}
						else if(*pcc - j <= 0 && channel_count > 1) // 첫 번째 자리에 가능한 수가 0보다 작거나 같을 경우 
						{
							for(k = channel_count - 2 ; k >= 0  ; k--)
							{
								cmp_plus += pow(10, k) * array_max;
								counter++;
							}
							i = channel_count;
						}
					}
				}
				else if(*pcc == 0 && *(pa + *pcc) == -1) // 원하는 채널이 0 일 경우
				{
					cmp_plus = 9999999;
					i = channel_count;
				}
			}
			else // 나머지 자리는 같거나 작은 수 중 가장 큰 수 
			{
				if(*(pa + *(pcc + i)) != -1) // 같을 때 
				{
					cmp_plus += pow(10, channel_count - i - 1) * *(pa + *(pcc + i));
					counter++;
				}
				else if(*(pa + *(pcc + i)) == -1) //다를 때 
				{
					for(j = 0 ; j <= *(pcc + i) ; j++) // 작은 수 중 검색 
					{
						if(*(pa + *(pcc + i) - j) != -1) // 작은 수 중 가장 큰 수 있음 
						{
							cmp_plus += pow(10, channel_count - i - 1) * *(pa + *(pcc + i) - j); // 그거 쓰고 
							counter++;
							if(channel_count > i + 1) // 나머지 자리는 max 로 채움 
							{
								for(k = channel_count - i -2 ; k >=0 ; k--)
								{
									cmp_plus += pow(10, k) * array_max;
									counter++;
								}								
							}
							i = channel_count;
							break;
						}
						else if(j ==  *(pcc + i)) // 작은 수 중 가장 큰 수 없음 
						{
							for(k = 1 ; k <= i ; k++)
							{
								for(L = 1 ; L <= *(pcc + i - k) ; L++) // 해당 자리에서 왼쪽으로 k 만큼 간 자리보다 작은 수 중 가장 큰 수 검색 
								{
									if(*(pa + *(pcc + i - k) - L) != -1) // 있으면
									{
										cmp_plus -= pow(10, channel_count - i - 1 + k) * *(pa + *(pcc + i - k));
										cmp_plus += pow(10, channel_count - i - 1 + k) * *(pa + *(pcc + i - k) - L);
										for(m = 1 ; m <= channel_count - i - 1 + k ; m++)
										{
											cmp_plus += pow(10, (channel_count - i - 1 + k) - m) * array_max;
											counter++;
										}
										i = channel_count;
										k = i + 1;
										break;
									}
								}
							}
							if(i != channel_count) // 없으면 전체 한자리수 낮은 max 도배
							{
								counter = 0;
								cmp_plus = 0;
								for(k = channel_count - 2 ; k >= 0  ; k--)
								{
									cmp_plus += pow(10, k) * array_max;
									counter++;
								}
								i = channel_count;
								break; 
							}
						}
					}
				}
			}
		}
		if(cmp_plus_count != 9999999)
		{
			cmp_plus_count = abs(cmp_plus - channel_int) + counter; //for문 끝나고 계산 			
		}
		
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
				else if(*(pa + *pcc) == -1 && channel_count != 6) // 채널이 같지않고 6자리가 아닐 때 
				{
					for(j = 0 ; j <= 9 - *pcc ; j++)
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
								for(k = 1 ; k < 6  ; k++)
								{
									if(*(pa + k) != -1 && k != 5) // 맨 앞자리에 가능한 버튼이 5 미만일 경우 
									{
										cmp_minus += pow(10, channel_count) * *(pa + k);
										counter++;											
										for(L = 1 ; L <= channel_count ; L++)
										{
											cmp_minus += pow(10, channel_count - L) * array_min1;
											counter++;
										}
										cmp_minus_count = abs(cmp_minus - channel_int) + counter;
										i = channel_count;
										break;
									}
									else if(*(pa + k) != -1 && k == 5) // 맨 앞자리에 가능한 버튼이 5일 경우 
									{
										if(array_min1 == 0)
										{
											cmp_minus = 500000;
											counter = 6;
											cmp_minus_count = abs(cmp_minus - channel_int) + counter;
											i = channel_count;
											break;
										}
										else
										{
											cmp_minus_count = 9999999;
											i = channel_count;
											break;											
										}
									}
									else if(*(pa + k) == -1 && k == 5) // 맨 앞자리에 가능한 버튼이 5보다 클 경우
									{
										cmp_minus_count = 9999999;
										i = channel_count;
										break;
									}
								}
								cmp_minus_count = abs(cmp_minus - channel_int) + counter;
								i = channel_count;
								break;
							}
							else
							{
								for(k = channel_count ; k >= 0 ; k--)
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
								break;
							}
							break;
						}
					}
				}
				else if(*(pa + *pcc) == -1 && channel_count == 6) // 채널이 6자리 일 때 
				{
					if(*pcc = 5)
					{
						cmp_minus_count = 9999999;
						i = channel_count;
					}
					else if(*pcc < 5)
					{
						for(j = 1; j <= 5 - *pcc ; j++)
						{
							if(*(pa + *pcc + j) != -1)
							{
								if(*(pa + *pcc + j) == 5)
								{
									if(array_min1 !=0)
									{
										cmp_minus_count = 9999999;
										i = channel_count;
									}
									else if(array_min1 == 0)
									{
										cmp_minus = 500000;
										cmp_minus_count = abs(cmp_minus - channel_int) + 6;
										i = channel_count;
									}
								}
								else if(*(pa + *pcc + j) < 5)
								{
									cmp_minus += pow(10, channel_count -1) * *(pa + *pcc + j);
									for(k = 1 ; k <= channel_count ; k++)
									{
										cmp_minus += pow(10, channel_count -k -1) * array_min1;
									}
									i = channel_count;
								}
								else
								{
									cmp_minus_count = 9999999;
									i = channel_count;
								}
							}
						}
					}
				}
			}
			else // 나머지 자리는 같거나 큰 수 중 가장 작은 수 
			{
				if(*(pa + *(pcc + i)) != -1) // 같을 때 
				{
					cmp_minus += pow(10, channel_count - i - 1) * *(pa + *(pcc + i));
					counter++;
				}
				else if(*(pa + *(pcc + i)) == -1) //다를 때 
				{
					for(j = 0 ; j <= 9 - *(pcc + i) ; j++) // 큰 수 중 검색 
					{
						if(*(pa + *(pcc + i) + j) != -1) // 큰 수 중 가장 작은 수 있음 
						{
							cmp_minus += pow(10, channel_count - i - 1) * *(pa + *(pcc + i) + j); // 그거 쓰고 
							counter++;
							if(channel_count > i + 1) // 나머지 자리는 min1 로 채움 
							{
								for(k = channel_count - i -2 ; k >=0 ; k--)
								{
									cmp_minus += pow(10, k) * array_min1;
									counter++;
								}								
							}
							cmp_minus_count = abs(cmp_minus - channel_int) + counter;
							i = channel_count;
							break;
						}
						else if(j == 9 - *(pcc + i)) // 큰 수 중 가장 작은 수 없음 
						{
							for(k = 1 ; k <= i ; k++)
							{
								for(L = 1 ; L <= 9 - *(pcc + i - k) ; L++) // 해당 자리에서 왼쪽으로 k 만큼 간 자리보다 큰 수 중 가장 작은 수 검색 
								{
									if(*(pa + *(pcc + i - k) + L) != -1) // 있으면
									{
										cmp_minus -= pow(10, channel_count - i - 1 + k) * *(pa + *(pcc + i - k));
										cmp_minus += pow(10, channel_count - i - 1 + k) * *(pa + *(pcc + i - k) + L);
										for(m = 1 ; m <= channel_count - i - 1 + k ; m++)
										{
											cmp_minus += pow(10, (channel_count - i - 1 + k) - m) * array_min1;
											counter++;
										}
										i = channel_count;
										k = i + 1;
										break;
									}
								}
							}
							if(i != channel_count) // 없으면 한자리수 많은 수에서 -
							{
								counter = 0;
								cmp_minus = 0;
								for(k = channel_count ; k >= 0 ; k--)
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
								i = channel_count;
								break;
							}
							break;
						}
					}
				}
			}
		}
		if(cmp_minus_count != 9999999)
		{
			cmp_minus_count = abs(cmp_minus - channel_int) + counter; //for문 끝나고 계산
		}
		
		printf("%d",Compare_plus_minus_100(cmp_plus_count,cmp_minus_count,Compare_100(channel_int)));
	}
 

	printf("\n");
	printf("\nCHECK LIST\n");
	
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

int Compare_plus_minus_100(int p,int m,int c)
{
	if(p >= m && c >= m)
	{
		return m;
	}
	else if(p >= c && m >= c)
	{
		return c;
	}
	else if(c >= p && m >= p)
	{
		return p;
	}
}











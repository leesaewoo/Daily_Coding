#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int Channel_Count(int x); // ���ϴ� ä�� �ڸ��� ���ϴ� �Լ�
int Compare_100(); //100���� +-�θ� ���ϴ� ä�� ���ߴ� ��쿡 ��ư ���� Ƚ�� ���ϴ� �Լ� 
int Compare_plus_minus_100(); //���� ���� ���� Ƚ�� ���ϴ� �Լ� 

int main(void)
{
	int i, j, k, l, m, temp, check = 0;
	int channel_int; //���ϴ� ä��
	int channel_count; //���ϴ� ä���� �ڸ���
	int button_count; // ���峭 ��ư�� ���� 
	int cmp_plus = 0;
	int cmp_plus_count = 0;
	int cmp_minus = 0;
	int cmp_minus_count = 0;
 	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *pa = array;
	int array_max; // ���峭 ��ư�� �����ϰ� ���� ū ��ư ��
	int array_min; // ���峭 ��ư�� �����ϰ� ���� ���� ��ư ��
		
	while(1)
	{
		scanf("%d", &channel_int); // ���ϴ� ä�� �Է� 
		if(channel_int > 500000 || channel_int < 0)
		{
			printf("ä���� 0 ~ 500000 ������ ���̾�� �մϴ�.\n");
		}
		else
		{
			temp = channel_int;
			break;
		}
	}
	
	while(1)
	{	
		scanf("%d", &button_count); // ���峭 ��ư�� ���� �Է� 
		if(button_count > 10 || button_count < 0)
		{
			printf("���峭 ��ư�� ������ 0 ~ 10 ������ ���̾�� �մϴ�.\n");
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
		scanf(" %[^\n]s",po); // ���峭 ��ư�� ��ȣ �Է� 
	}
	for(i=0;i<button_count;i++) // array �迭���� ���峭 ��ư�� ���� -1�� �ٲ� 
	{
		*(pa+(*(po + 2*i) - '0')) = -1;
	}
	for(i=9;i>0;i--) // array_max ���ϴ� �Լ� 
	{
		if(*(pa+i) != -1)
		{
			array_max = *(pa+i);
			break;
		}
	}
	for(i=0;i<10;i++) // array_min ���ϴ� �Լ� 
	{
		if(*(pa+i) != -1)
		{
			array_min = *(pa+i);
			break;
		}
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
					else if(check == 88) // �� �ڸ��� ���� ���� ū ������ ++ ��� 
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
		
		// 0 ~ channel_count -2 ���� �Ǻ���

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
	if(cmp_plus == channel_int) // cmp_plus_count ���ϱ�
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
	
	
	for(i=0;i<channel_count;i++) // cmp_minus ���ϱ� 
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
					else // �� �ڸ� ���� �ּҰ����� -- �ϴ� ��� 
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
		
		// 0 ~ channel_count -2 ���� �Ǻ���

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
	if(cmp_minus == channel_int) // cmp_minus_count ���ϱ�
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
	
	printf("cmp_plus_count = %d\n",cmp_plus_count);	
	
	printf("cmp_minus = %d\n",cmp_minus);
	
	printf("cmp_minus_count = %d\n",cmp_minus_count);
	
	printf("Compare_100 = %d\n",Compare_100(channel_int));
	
	printf("array_max = %d\narray_min = %d\n",array_max,array_min);
	
	
	printf("ä���� ���� �� ��ư�� ���� ���� ������ Ƚ�� = %d\n",Compare_plus_minus_100(button_count,cmp_plus_count,cmp_minus_count,Compare_100(channel_int),channel_count));

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

#include <stdio.h>
#include <math.h>

int Channel_Count(int x); // ���ϴ� ä�� �ڸ��� ���ϴ� �Լ�
int Compare_100(); //100���� +-�θ� ���ϴ� ä�� ���ߴ� ��쿡 ��ư ���� Ƚ�� ���ϴ� �Լ� 
int Compare_plus_minus_100(); //���� ���� ���� Ƚ�� ���ϴ� �Լ� 

// https://www.acmicpc.net/problem/1107 �ش� ������ ������ ä���� ���Ѵ��̳�, 
// ���⼭�� 0 �̻� 500000 ���Ϸ� �����Ͽ���.
 
int main(void)
{
	int i, j, k, L, m, temp, counter = 0;
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
	int array_min1 = -1; // ���峭 ��ư�� �����ϰ� ���� ���� ��ư ��
	int array_min2 = -1; // ���峭 ��ư�� �����ϰ� ���� ���� ��ư ��
	int button_push; // ���ϴ� ä���� ���� ���� ���� ���� ��ư�� ���� Ƚ�� 

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
	for(i=0;i<10;i++) // array_min1, array_min2 ���ϴ� �Լ� 
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
	
	channel_count = Channel_Count(channel_int); // ���ϴ� ä�� �ڸ��� ���ϱ� 	
	char channel_char[channel_count]; // ���ϴ� ä�� char �迭 ���� 
	char *pcc = channel_char;
	for(i=0;i<channel_count;i++) // ���ϴ� ä���� char �迭�� �Է� 
	{
		*(pcc+i) = temp / pow(10,channel_count -1 -i);
		temp -= pow(10,channel_count -1 -i)*(*(pcc+i));
	}



	// ������� (���� ��ư�� ������ �ൿ�� ���� �� counter++ (+-�� ����)) 

	if(button_count == 0) // ���峭 ��ư�� ���� ��
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
	else if(button_count == 10) // ��ư�� ��� ���峵�� ��
	{
		printf("%d", Compare_100(channel_int)); // Compare_100(channel_int)
	}
	else if(button_count == 9 && *pa == 0) // ��ư�� 0 ���� ��� ���峵�� ��
	{
		counter = 1; //��ư�� ������ �ѹ��� �����°� (0)
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
	else // �� ���� ���
	{
		counter = 0;
		
		for(i=0 ; i<channel_count ; i++) //cmp_plus
		{
			if(i == 0)
			{
				if(*(pa + *pcc) != -1) // ù ��° �ڸ��� ���ų� 
				{
					cmp_plus += pow(10, channel_count - 1) * *(pa + *pcc);
					counter++;
				}
				else if(*(pa + *pcc) == -1 && *pcc != 0) // ���������� 
				{
					for(j = 1 ; j <= *pcc ; j++)
					{
						if(*(pa + *pcc - j) != -1 && j != *pcc) // ���� �� �� ���� ū �� 
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
						else if(*pcc - j <= 0 && channel_count > 1) // ù ��° �ڸ��� ������ ���� 0���� �۰ų� ���� ��� 
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
				else if(*pcc == 0 && *(pa + *pcc) == -1) // ���ϴ� ä���� 0 �� ���
				{
					cmp_plus = 9999999;
					i = channel_count;
				}
			}
			else // ������ �ڸ��� ���ų� ���� �� �� ���� ū �� 
			{
				if(*(pa + *(pcc + i)) != -1) // ���� �� 
				{
					cmp_plus += pow(10, channel_count - i - 1) * *(pa + *(pcc + i));
					counter++;
				}
				else if(*(pa + *(pcc + i)) == -1) //�ٸ� �� 
				{
					for(j = 0 ; j <= *(pcc + i) ; j++) // ���� �� �� �˻� 
					{
						if(*(pa + *(pcc + i) - j) != -1) // ���� �� �� ���� ū �� ���� 
						{
							cmp_plus += pow(10, channel_count - i - 1) * *(pa + *(pcc + i) - j); // �װ� ���� 
							counter++;
							if(channel_count > i + 1) // ������ �ڸ��� max �� ä�� 
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
						else if(j ==  *(pcc + i)) // ���� �� �� ���� ū �� ���� 
						{
							for(k = 1 ; k <= i ; k++)
							{
								for(L = 1 ; L <= *(pcc + i - k) ; L++) // �ش� �ڸ����� �������� k ��ŭ �� �ڸ����� ���� �� �� ���� ū �� �˻� 
								{
									if(*(pa + *(pcc + i - k) - L) != -1) // ������
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
							if(i != channel_count) // ������ ��ü ���ڸ��� ���� max ����
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
			cmp_plus_count = abs(cmp_plus - channel_int) + counter; //for�� ������ ��� 			
		}
		
		counter = 0;
		
		for(i=0 ; i<channel_count ; i++) //cmp_minus
		{
			if(i == 0)
			{
				if(*(pa + *pcc) != -1) // ù ��° �ڸ��� ���ų� 
				{
					cmp_minus += pow(10, channel_count - 1) * *(pa + *pcc);
					counter++;
				}
				else if(*(pa + *pcc) == -1 && channel_count != 6) // ä���� �����ʰ� 6�ڸ��� �ƴ� �� 
				{
					for(j = 0 ; j <= 9 - *pcc ; j++)
					{
						if(*(pa + *pcc + j) != -1) // ū �� �� ���� ���� �� 
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
						else if(*(pa + *pcc + j) == -1 && j == 9 - *pcc) // ù ��° �ڸ��� ������ ���� 9���� ũ�ų� ���� ���� ���� ���
						{
							if(channel_count == 5) // ä���� �ڸ����� 5�� ��� ä���� �ִ�ġ�� 500000���� ���� 
							{
								for(k = 1 ; k < 6  ; k++)
								{
									if(*(pa + k) != -1 && k != 5) // �� ���ڸ��� ������ ��ư�� 5 �̸��� ��� 
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
									else if(*(pa + k) != -1 && k == 5) // �� ���ڸ��� ������ ��ư�� 5�� ��� 
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
									else if(*(pa + k) == -1 && k == 5) // �� ���ڸ��� ������ ��ư�� 5���� Ŭ ���
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
				else if(*(pa + *pcc) == -1 && channel_count == 6) // ä���� 6�ڸ� �� �� 
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
			else // ������ �ڸ��� ���ų� ū �� �� ���� ���� �� 
			{
				if(*(pa + *(pcc + i)) != -1) // ���� �� 
				{
					cmp_minus += pow(10, channel_count - i - 1) * *(pa + *(pcc + i));
					counter++;
				}
				else if(*(pa + *(pcc + i)) == -1) //�ٸ� �� 
				{
					for(j = 0 ; j <= 9 - *(pcc + i) ; j++) // ū �� �� �˻� 
					{
						if(*(pa + *(pcc + i) + j) != -1) // ū �� �� ���� ���� �� ���� 
						{
							cmp_minus += pow(10, channel_count - i - 1) * *(pa + *(pcc + i) + j); // �װ� ���� 
							counter++;
							if(channel_count > i + 1) // ������ �ڸ��� min1 �� ä�� 
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
						else if(j == 9 - *(pcc + i)) // ū �� �� ���� ���� �� ���� 
						{
							for(k = 1 ; k <= i ; k++)
							{
								for(L = 1 ; L <= 9 - *(pcc + i - k) ; L++) // �ش� �ڸ����� �������� k ��ŭ �� �ڸ����� ū �� �� ���� ���� �� �˻� 
								{
									if(*(pa + *(pcc + i - k) + L) != -1) // ������
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
							if(i != channel_count) // ������ ���ڸ��� ���� ������ -
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
			cmp_minus_count = abs(cmp_minus - channel_int) + counter; //for�� ������ ���
		}
		
		printf("%d",Compare_plus_minus_100(cmp_plus_count,cmp_minus_count,Compare_100(channel_int)));
	}
 

	printf("\n");
	printf("\nCHECK LIST\n");
	
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











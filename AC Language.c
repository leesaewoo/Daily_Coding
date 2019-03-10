#include <stdio.h>
#include <stdlib.h>


void R(int *length); // R(������) �Լ� ����
void D(int *length); // D(������) �Լ� ���� 

int R_check = 1;
int D_check_s; // test case�� �ٲ� �� ���� 0���� �ʱ�ȭ �ؾ��� 
int D_check_e; // �ش� test case �� *pn ������ �ʱ�ȭ �ؾ��� 

int main(void)
{
	int i, j, k;
	int error_check = 0;

	int T; // T�� Test case
	while(1)
	{
		scanf("%d",&T);
		if(T >= 0 && T <= 100)
		{
			break;
		}
	}
	
	int *pn;
	pn = (int*)malloc(sizeof(int) * T); // �� test case �� n ���� ���� ����(�迭) �Ҵ� 
	char **pp = (char**)malloc(sizeof(char) * T); // �� test case �� p ���� ���� ����(�迭) �Ҵ� 
	
	int **pT = (int**)malloc(sizeof(int) * T);
	for(i = 0 ; i < T ; i++)
	{
		*(pp + i) = (char*)malloc(sizeof(char) * 100000);
		scanf(" %[^\n]s", *(pp + i)); // 1 <= pp <= 100000
		scanf("%d", (pn + i)); // 0 <= pn <= 100000
		*(pT + i) = (int*)malloc(sizeof(int) * *(pn + i));
		char *pTemp;
		pTemp = (char*)malloc(sizeof(char) * ((*(pn + i) * 4) + 1));
		scanf(" %[^\n]s", pTemp); // 1 <= �迭�� ���� �� <=100
		int temp = 0;
		j = 1;
		for(k = 0 ; k < *(pn + i) ; k++) // �Է¹��� �迭����  **pT(2���� �迭)�� �Է� 
		{
			if(*(pTemp + j) != ',')
			{
				if(*(pTemp + j + 1) == ',' || *(pTemp + j + 1) == ']')
				{
					temp += (*(pTemp + j) - '0');
					*(*(pT + i) + k) = temp;
					temp = 0;
					j += 2;
				}
				else if(*(pTemp + j + 2) == ',' || *(pTemp + j + 2) == ']')
				{
					temp += (*(pTemp + j) - '0') * 10;
					temp += (*(pTemp + j + 1) - '0');
					*(*(pT + i) + k) = temp;
					temp = 0;
					j += 3;
				}
				else if(*(pTemp + j + 3) == ',' || *(pTemp + j + 3) == ']')
				{
					*(*(pT + i) + k) = 100;
					j += 4;
				}
			}
			else if(*(pTemp + j) == ']')
			{
				break;
			}
		}
		free(pTemp); // *pTemp �����Ҵ� ���� 
	}
	
	
	//i ��° ���̽��� ���ؼ� pp �Լ� ������ ���� �� ��� (error ���� �� ���� �Լ� ���� �ߴ�)
	for(i = 0 ; i < T ; i++)
	{
		R_check = 1;
		D_check_s = 0;
		D_check_e = *(pn + i);
		
		for(j = 0; ; j++)
		{
			if(*(*(pp + i) + j) == 'R')
			{
				R(pn + i);
			}
			else if(*(*(pp + i) + j) == 'D' && *(pn + i) != 0)
			{
				D(pn + i);
			}
			else if(*(*(pp + i) + j) == 'D' && *(pn + i) == 0)
			{
				error_check = 1; //error ����ϴ� ����ġ ON 
				break;
			}
			else if(*(*(pp + i) + j + 1) == 0)
			{
				break;
			}
		}

		if(error_check == 1)	// pp �Լ��� ��� ������ �迭 ���
		{
			printf("error\n");
			error_check = 0;
		}
		else if(error_check == 0 && *(pn + i) == 0)
		{
			printf("[]\n");
		}
		else if(error_check == 0 && R_check == 1)
		{
			printf("[");
			for(j = D_check_s ; j < D_check_e ; j++) 
			{
				if(j == D_check_e - 1)
				{
					printf("%d", *(*(pT + i) + j));
					printf("]\n");
					break;
				}
				else
				{
					printf("%d", *(*(pT + i) + j));
					printf(",");
				} 
			}
		}
		else if(error_check == 0 && R_check == -1)
		{
			printf("[");
			for(j = D_check_e - 1 ; j >= D_check_s ; j--) 
			{
				if(j == D_check_s)
				{
				printf("%d", *(*(pT + i) + j));
				printf("]\n");
				break;
				}
				else
				{
					printf("%d", *(*(pT + i) + j));
					printf(",");
				}
			}
		}
	}
	
	free(pn); // *pn �����Ҵ� ����

	for(i = 0 ; i < T ; i++) // *pT, *pp �����Ҵ� ����
	{
		free(*(pT + i));
		free(*(pp + i));
	}

	return 0;
}

void R(int *length) // timecomplexity = O(1)
{
	if(*length != 0)
	{
		R_check *= -1; // �ϳ��� test case �� ���� �� 1�� �ʱ�ȭ �ؾ���
	}
}

void D(int *length) // timecomplexity = O(1)
{
	if(R_check == -1)
	{
		D_check_e--;
		*length = *length - 1;
	}
	else if(R_check == 1)
	{
		D_check_s++;
		*length = *length - 1;
	}
}

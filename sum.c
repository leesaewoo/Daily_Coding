#include <stdio.h>

int main(void)
{
	int number;
	int i = 1;
	int j;
	int k = 0;
	
	
	while(i != 0)
	{
		printf("��ĥ ������ �ڸ���(N)�� �Է����ּ���.\nN = ");
		scanf("%d",&number);
	
		if(number>100 || number<=0)
		{
			printf("N�� 1�̻� 100���Ͽ��� �մϴ�.");
		
		}
		else
		{
			i = 0;
		}
	}
	
	char array[number];
	char *p = array;
	
	printf("��ĥ ���ڸ� �ڸ����� �°� �Է����ּ���.\n");
	
	scanf("%s",p);
	
	for(j = 0; j < number; j++)
	{
		k = k + *(p+j) - '0';
	}
	
	printf("�� �ڸ����� ���� ���� %d �Դϴ�.",k);
	
	
	return 0;
}

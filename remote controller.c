#include <stdio.h>

int main(void)
{
	int i;
	int number,count;
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p1 = array;
	scanf("%d", &number); // ���ϴ� ä�� �Է� 
	scanf("%d", &count); // ���峭 ��ư�� ���� �Է� 
	
	char out[(count*2)-1];
	char *p2 = out;
	scanf(" %[^\n]s",p2); // ���峭 ��ư�� ��ȣ �Է� 
	
	for(i=0;i<count;i++)
	{
		*(p1+(*(p2+(2*i))-'0')) = -1; // array �迭���� ���峭 ��ư�� ���� -1�� �ٲ� 
	}
	
	for(i=0;i<10;i++) // array���� �� ������ Ȯ�ο� 
	{
		printf("array(%d) = %d\n",i,*(p1+i));
	}
	
	for(i=0;i<(count*2)-1;i++) // out Ȯ�ο� 
	{
		printf("out(%d) = %c\n",i,*(p2+i));	
	} 
	
	return 0;
}

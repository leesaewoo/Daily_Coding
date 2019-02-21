#include <stdio.h>

int main(void)
{
	int i;
	int number,count;
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int *p1 = array;
	scanf("%d", &number); // 원하는 채널 입력 
	scanf("%d", &count); // 고장난 버튼의 갯수 입력 
	
	char out[(count*2)-1];
	char *p2 = out;
	scanf(" %[^\n]s",p2); // 고장난 버튼의 번호 입력 
	
	for(i=0;i<count;i++)
	{
		*(p1+(*(p2+(2*i))-'0')) = -1; // array 배열에서 고장난 버튼의 값을 -1로 바꿈 
	}
	
	for(i=0;i<10;i++) // array에서 잘 빠지나 확인용 
	{
		printf("array(%d) = %d\n",i,*(p1+i));
	}
	
	for(i=0;i<(count*2)-1;i++) // out 확인용 
	{
		printf("out(%d) = %c\n",i,*(p2+i));	
	} 
	
	return 0;
}

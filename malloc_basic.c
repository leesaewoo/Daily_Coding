#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *pi;
	pi = (int*)malloc(sizeof(int));
	if(pi == NULL)
	{
		printf("���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
	}
	
	*pi = 100;
	
	printf("%d  %d", *pi, pi);
	
	free(pi);

	return 0;
}

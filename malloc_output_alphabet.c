#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *pc = NULL;
	int i;
	pc = (char*)malloc(26*sizeof(char));
	
	if(pc == NULL)
	{
		printf("���� �޸� �Ҵ翡 �����߽��ϴ�.\n");
		exit(1);
	}
	
	for(i=0; i<26; i++)
	{
		*(pc+i)='a'+i;
	}
	
	printf("%s", pc);
	
	free(pc);
	
	return 0;
}

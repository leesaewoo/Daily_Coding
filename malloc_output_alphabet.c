#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *pc = NULL;
	int i;
	pc = (char*)malloc(26*sizeof(char));
	
	if(pc == NULL)
	{
		printf("동적 메모리 할당에 실패했습니다.\n");
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

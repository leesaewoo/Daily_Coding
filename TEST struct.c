#include <stdio.h>
#include <stdlib.h>

void BufferClear(){
	while(getchar() != '\n');
}

typedef struct Test{
	char str[51];
	int num;
}Test;


int main(void)
{
	int N;
	scanf("%d", &N); BufferClear();
	
	Test *ptr[N];
	
	
	return 0;
}

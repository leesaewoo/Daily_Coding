#include <stdio.h>

int main(void)
{
	char str[101];
	int i;
	
	for(i = 0 ; i < 100 ; i ++)
	{
		if(scanf(" %[^\n]s",str) == EOF)
		{
			break;
		}
		else
		{
			printf("%s\n",str);
		}
	}
	
	return 0;
}

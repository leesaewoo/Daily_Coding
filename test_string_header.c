#include <stdio.h>
#include <string.h>

int main(void)
{
	char str1[5];
	char str2[5];
	
	strcpy(str1, "abcdf");
	strcpy(str2, "abcde");
	
	if(strcmp(str1, str2) == 0)
	{
		printf("zero\n");
	}
	else if(strcmp(str1, str2) > 0)
	{
		printf("plus\n");
	}
	else if(strcmp(str1, str2) < 0)
	{
		printf("minus\n");
	}
	
	int result = strcmp(str1, str2);
	
	printf("%d\n", result);
	 
	return 0;
}

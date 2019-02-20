#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
	int number;
	char title[100];
};


void OutputB(struct Book *p,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
	printf("number : %d , title : %s\n",(p+i)->number, (p+i)->title);
	}

}


int main(void)
{
	struct Book *p;
	p = (struct Book *)malloc(3*sizeof(struct Book));
	
	if(p==NULL)
	{
		printf("동적 할당에 실패했습니다.\n");
		exit(1); 
	}
	
	p->number = 2010;
	strcpy(p->title, "abc");
	(p+1)->number = 2030;
	strcpy((p+1)->title, "def");
	(p+2)->number = 2050;
	strcpy((p+2)->title, "ghi");
	
	OutputB(p,3);
	free(p);
	
	return 0;
}

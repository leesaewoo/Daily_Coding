#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("��������DICE GAME ��������\n");
	printf("��1. Throwing Dice     	��\n");
	printf("��2. Exit               ��\n");
	printf("��������������������������\n");
	printf(" Input : ");
}

void start()
{
	int random = rand() % 6 + 1;
	printf(" Throwing Dice!\n");
	printf(" Dice number : %d\n", random);
}

void srand (unsigned int seed);

int rand(void);

int main(void)
{
	int select;
	srand(time(NULL));
	while(1)
	{
		menu();
		scanf("%d", &select);
		switch(select)
		{
			case 1:
				start();
				break;
			case 2:
				printf(" EXIT!\n");
				return 0;
			default:
				break;
		}
	}
	
	return 0;
}

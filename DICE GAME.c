#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("忙式式式DICE GAME 式式式忖\n");
	printf("弛1. Throwing Dice     	弛\n");
	printf("弛2. Exit               弛\n");
	printf("戌式式式式式式式式式式式戎\n");
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

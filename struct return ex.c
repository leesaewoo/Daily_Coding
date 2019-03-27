#include <stdio.h>


struct coordinates
{
	int add;
	int sub;
	float mul;
	float div;
};

struct coordinates cal (float x, float y);


int main(void)
{
	struct coordinates value;
	
	int x, y;
	
	printf("x = ");
	scanf("%d", &x);
	printf("y = ");
	scanf("%d", &y); 
	
	value = cal(x, y);
	
	printf("x + y = %d\n", value.add);
	printf("x - y = %d\n", value.sub);
	printf("x * y = %.3f\n", value.mul);
	printf("x / y = %.3f\n", value.div);
	
	return 0;
}

struct coordinates cal (float x, float y)
{
	struct coordinates temp;
	
	temp.add = x + y;
	temp.sub = x - y;
	temp.mul = x * y;
	temp.div = x / y;
	
	return temp;
}

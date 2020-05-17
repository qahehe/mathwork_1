#include<stdio.h>
/**
	simple multiplication implementation
	@author:陈海龙
*/
int multiply(int a, int b)
{
	if (b == 0)
		return 0;
	if ((~b) & 1)
		return multiply(a, b >> 1) << 1;
	else
		return (multiply(a, b >> 1) << 1) + a;
}
int main() {
	int a, b;
	scanf_s("%d %d", &a, &b);  //vs studio scanf报错，换成scanf_s 会更安全
	int c = multiply(a, b);
	printf("%d\n", c);
	return 0;
}



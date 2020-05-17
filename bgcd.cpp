#include<stdio.h> 
/**
	binary gcd algorithm implementation
	@author: 陈海龙 
*/

int bgcd(int a,int b)
{
	if(a==0 || b==0) //0 和任何数的最大公约数都是0之外的另一个数 
		return a+b; 
	if(a==b)   // a b相同时gcd为它们本身 
		return a;
	if( (a&1)  && (b&1))  //a和b都是偶数 
		return bgcd(a>>1,b>>1)<<1;
	if((a&1)  && (~b&1))  //a偶b奇
		return bgcd(a>>1,b);
	if((~a&1)  && (b&1))   //a奇b偶
		return bgcd(a,b>>1);
	if((~a&1)  && (~b&1))  //a和b都是奇数
	{
		if(a>b) 
			return bgcd((a-b)>>1,b);
		else
			return bgcd(a,(b-a)>>1);
	}
	return 0;
}
int main(){
	int a,b;
	scanf_s("%d %d",&a,&b);
	printf("%d\n",bgcd(a,b)); 
	return 0;
}

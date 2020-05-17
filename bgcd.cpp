#include<stdio.h> 
/**
	binary gcd algorithm implementation
	@author: �º��� 
*/

int bgcd(int a,int b)
{
	if(a==0 || b==0) //0 ���κ��������Լ������0֮�����һ���� 
		return a+b; 
	if(a==b)   // a b��ͬʱgcdΪ���Ǳ��� 
		return a;
	if( (a&1)  && (b&1))  //a��b����ż�� 
		return bgcd(a>>1,b>>1)<<1;
	if((a&1)  && (~b&1))  //ażb��
		return bgcd(a>>1,b);
	if((~a&1)  && (b&1))   //a��bż
		return bgcd(a,b>>1);
	if((~a&1)  && (~b&1))  //a��b��������
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

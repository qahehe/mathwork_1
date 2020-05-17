#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS   //������Խ��scanf���������
#include<stdio.h>
#include<math.h>
/**
	binarb extended gcd algorithm implementation
	@author : �º���
*/
int t, s, d;  //d= a*s + b*t =gcd(a,b)
void begcd(int a, int b)
{
	if (a == 0) { s = 0; t = 1; d = b; return; }
	if (b == 0) { s = 1; t = 0; d = a; return; }
	int c = 0;
	while ((~a & 1) && (~b & 1)) {  //ȡ������2����c
		a >>= 1;
		b >>= 1;
		c++;
	}
	//printf("%d %d %d\n", a, b, c);
	int ra = a;
	int rb = b;
	int sa = 1, sb = 0, ta = 0, tb = 1; //��ʼϵ��ѡ��
	while ((~a) & 1) { //��aΪż
		if (!(((~sa) & 1) && ((~sb) & 1))) { //a��ϵ����Ϊż
			sa -= rb;
			sb += ra;
		}
		a >>= 1;
		sa >>= 1;
		sb >>= 1;
	}
	while (b != 0) {
		while ((~b) & 1) {
			if (!(((~ta) & 1) && ((~tb) & 1))) {
				ta -= rb;
				tb += ra;
			}
			b >>= 1;
			ta >>= 1;
			tb >>= 1;
		}
		if (a > b) {
			int temp = a;
			a = b;
			b = temp;

			temp = sa;
			sa = ta;
			ta = temp;

			temp = sb;
			sb = tb;
			tb = temp;
		}
		b = b - a;
		ta = ta - sa;
		tb = tb - sb;
	}
	d = a << c;  //���Լ��Ϊa*(2^c)
	s = sa;   //a��ϵ��s
	t = sb;   //b��ϵ��t
}

int main()
{
	//main��������Ӳ���
	int a, b;
	scanf("%d %d", &a, &b);
	s = 0, t = 0, d = 0;
	begcd(a, b);
	printf("s==%d t==%d  d==%d\n", s, t, d);
	return 0;
}

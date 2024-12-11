#include<iostream>
#include<cstdio>

using namespace std;

int js(int x, char z, int y) {
	int r = 0;
	switch (z) {
		case '+':
			r= x + y;
			break;
		case '-':
			r = x - y;
			break;
		case '*':
			r = x * y;
			break;
		case '/':
			r = x / y;
			break;
		case '%':
			r = x % y;
			break;
	}
	return r;
}

int main() {
	int a, b;
	char c;

	// --------------------------------
	// 
	// 如果使用 visual studio 报错
	// 在 项目>属性>C/C++>SDL检查 改为 否
	// 
	//---------------------------------
	
	scanf("%d%c%d", &a, &c, &b);
	
	printf("%d", js(a, c, b));
	
	return 0;
}
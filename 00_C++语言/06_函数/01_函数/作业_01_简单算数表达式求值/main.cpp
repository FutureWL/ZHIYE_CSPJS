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
	scanf("%d%c%d", &a, &c, &b);
	printf("%d", js(a, c, b));
	return 0;
}
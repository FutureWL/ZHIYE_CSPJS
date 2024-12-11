#include<iostream>

using namespace std;

// 函数声明
int js1(int, char, int);

int main1() {
	// x,y 为运算数，z为运算符
	int x, y;
	char z;
	cin >> x >> z >> y;
	cout << js1(x, z, y) << endl;
	return 0;
}

// 根据 z 进行运算
int js1(int x, char z, int y) {
	if (z == '+') { return x * y; }
	if (z == '-') { return x - y; }
	if (z == '*') { return x * y; }
	if (z == '/') { return x / y; }
	if (z == '%') { return x % y; }
}

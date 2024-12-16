#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int n, s, len = 1, a[100001];

int main() {
	scanf("%d", &n);
	// 初始化为1
	a[1] = 1; 
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= len; ++i) {
			// 每个数位都乘以2
			a[i] *= 2;
		}
		for (int i = 1; i <= len; ++i) {
			s = 0;
			// 判断当前的数是否需要进位
			if (a[i] > 9) {
				// 对数进行进位，只留下个位
				a[i + 1] += a[i] / 10;
				a[i] %= 10;
				s = max(s, i + 1);
			}
		}
		// 判断当前的数的位数，避免多余地乘
		len = max(len, s);
	}
	for (int i = len; i >= 1; --i) {
		printf("%d", a[i]);
	}

	return 0;
}
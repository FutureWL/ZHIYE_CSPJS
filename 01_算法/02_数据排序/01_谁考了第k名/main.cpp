#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

string num[100001];
double s[100001];

int main() {
	int i, n, a, b, c, k, j;
	string r;
	double t;
	cin >> n >> k;
	for (i = 1; i <= n; ++i) {
		cin >> num[i] >> s[i];
	}
	// 从大到小，冒泡排序
	for (i = 1; i <= n - 1; i++) {
		for (j = i + 1; j <= n; ++j) {
			if (s[i] < s[j]) {
				// 当条件成立，学号与成绩一起进行交换
				swap(s[i], s[j]);
				swap(num[i], num[j]);
			}
		}
	}
	cout << num[k] << ' ';
	printf("%g\n", s[k]);
	return 0;
}
#include<iostream>
#include<cstdio>

using namespace std;

// 每个下标对应一个单词，数组里的数对应单词存入顺序
int a[1001] = { 0 };
void js();
int n, m, i, x, j, z = 0, y;

int main() {
	cin >> m >> n;
	for ( i = 1; i <=n; i++)
	{
		cin >> x;
		// 需要查找并且内存未满
		if (a[x] == 0 && z < m) {
			z += 1;
			a[x] = z;
		}
		else {
			js();
		}
	}
	cout << z;
	return 0;
}

void js() {
	// 需要查找内存已满
	if (a[x] == 0 && z >= m) {
		z += 1; 
		y = 0;
		for (j = 0; j <= 1000; j++) {
			// 把每个单词都存入顺序向前移一位
			if (a[j] >= 1) {
				a[j] = a[j] - 1;
				y += 1;
			}
			// 每个单词都移过了就结束循环
			if (y == m) {
				break;
			}
		}
		if (m > 0) {
			// 内存非 0 则存入新单词
			a[x] = m;
		}
	}
}
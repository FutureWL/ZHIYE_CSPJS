#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

char al[2000], bl[2000], n[2000];
int a[2000], b[2000], c[2000];

int main() {

	int lena, lenb, lenc, i;
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));

	// 分别读入字符串 al，bl
	scanf("%s %s", al, bl);
	// 字符长度
	lena = strlen(al); 
	lenb = strlen(bl);

	// 将两串字符串分别存储到整形数组
	for (i = 0; i <= lena - 1; i++) {
		a[lena - i] = int(al[i] - '0');
	}
	for (i = 0; i <= lenb - 1; i++) {
		b[lenb - i] = int(bl[i] - '0');
	}
	for (i = 1; i <= lena; i++) {
		// 如果不够减就向前借1位
		if (a[i] < b[i]) {
			a[i] += 10;
			a[i + 1]--;
		}
		c[i] = a[i] - b[i];
	}
	lenc = i;
	while (c[lenc] == 0 && lenc > 1) {
		lenc--;
	}
	for (i = lenc; i >= 1; i--) {
		cout << c[i];
	}
	cout << endl;

	return 0;
}
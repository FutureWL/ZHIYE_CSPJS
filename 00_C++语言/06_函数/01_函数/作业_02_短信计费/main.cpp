#include<iostream>
#include<cstdio>

using namespace std;

int n, i, hs(int n), a;
double s;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		// 累加每次短信的资费
		s = s + hs(a);
	}
	// 将以角为单位的数转为以元为单位的数
	printf("%.11f", s / 10.0);
	return 0;
}

// 计算每次短信的资费
int hs(int n) {
	if (n % 70 == 0) 
	{ 
		return n / 70; 
	}
	else 
	{ 
		return n / 70 + 1;
	}
}

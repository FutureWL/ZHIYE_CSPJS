#include<iostream>

using namespace std;

int i, n, k = 0, b[201];
bool hs(float n, int a);
float a[201];
string name[201];

int main() 
{ 
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> name[i] >> a[i] >> b[i];
	}
	for (i = 1; i <= n; i++)
	{
		if (hs(a[i], b[i]))
		{
			// 类加甲流病人数
			k++;
			// 如果第 i 个病人是甲流病人则输出病人名
			cout << name[i] << endl;
		}
	}
	cout << k;
	return 0;
}

bool hs(float n, int a) 
{
	// 判断是否为甲流病人，满足条件就返回 true
	if ((n >= 37.5) && (a == 1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

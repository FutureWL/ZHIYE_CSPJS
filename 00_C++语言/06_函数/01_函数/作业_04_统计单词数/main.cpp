#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int main() {
	int t = 0, t2 = 0, l, l2;
	string s, ss;
	getline(cin, ss);
	// 使用 getline(cin, s) 读入整行字符串
	getline(cin, s);
	l = s.size();
	l2 = ss.size();
	// 循环至 l-l2 足够，词首的下标不会大于 l-l2
	for (int i = 0; i <= l - l2; ++i) {
		int j;
		// 从要查找的单词词首和文章第i个字符开始逐个字符判定
		for (j = 0; j < l - 1; ++j) {
			// 若字符不匹配则退出当前循环，再从文章第i+1个字符开始判定
			if (toupper(s[i + j]) != toupper(ss[j])) {
				break;
			}
			// 若第i个字符不是文章首，且前一个字符不是空格，则其不是独立单词，同样退出循环
			if (i > 0 && s[i - 1] != ' ')
			{
				break;
			}
		}
		// 若循环判定通过，且该单词词尾为文章尾或后有空格（独立单词），则满足条件
		if (j == l2 && (s[i + j] == ' ' || j + i == l))
		{
			// 累加满足条件的单词数
			++t;
			// 若第一次出现，用t2记录位置
			if (t == 1) {
				t2 = i;
			}
		}
	}
	// 判断是否出现，出现0次，即为没有出现
	if (t == 0){ 
		printf("-1\n");
	}
	else {
		printf("%d %d\n", t, t2);
	}
	return 0;
}
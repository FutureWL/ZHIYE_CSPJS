#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 将字符串形式的大整数按位分割成向量存储
vector<int> stringToDigits(const string& num) {
    vector<int> digits;
    for (char ch : num) {
        digits.push_back(ch - '0');
    }
    return digits;
}

// 模拟简单的两个一位数相乘（实际可以直接用乘法运算，这里为体现逻辑）
int multiplySingleDigits(int a, int b) {
    return a * b;
}

// 合并两个部分乘积结果（简单相加，实际更复杂）
vector<int> addVectors(const vector<int>& a, const vector<int>& b) {
    vector<int> result;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) {
            sum += a[i];
            i--;
        }
        if (j >= 0) {
            sum += b[j];
            j--;
        }
        result.push_back(sum % 10);
        carry = sum / 10;
    }
    return vector<int>(result.rbegin(), result.rend());
}

// 分治函数实现大整数乘法
vector<int> multiply(vector<int>& num1, vector<int>& num2) {
    if (num1.size() == 1 && num2.size() == 1) {
        int product = multiplySingleDigits(num1[0], num2[0]);
        vector<int> result;
        result.push_back(product % 10);
        if (product >= 10) {
            result.push_back(product / 10);
        }
        return result;
    }

    int mid1 = num1.size() / 2;
    int mid2 = num2.size() / 2;

    vector<int> a(num1.begin(), num1.begin() + mid1);
    vector<int> b(num1.begin() + mid1, num1.end());
    vector<int> c(num2.begin(), num2.begin() + mid2);
    vector<int> d(num2.begin() + mid2, num2.end());

    vector<int> ac = multiply(a, c);
    vector<int> bd = multiply(b, d);
    vector<int> ad_plus_bc = addVectors(multiply(a, d), multiply(b, c));

    vector<int> result;
    result = addVectors(ac, bd);
    result = addVectors(result, ad_plus_bc);

    return result;
}

int main() {
    string num1_str = "1234";
    string num2_str = "5678";
    vector<int> num1 = stringToDigits(num1_str);
    vector<int> num2 = stringToDigits(num2_str);
    vector<int> product = multiply(num1, num2);
    for (int digit : product) {
        cout << digit;
    }
    cout << endl;
    return 0;
}
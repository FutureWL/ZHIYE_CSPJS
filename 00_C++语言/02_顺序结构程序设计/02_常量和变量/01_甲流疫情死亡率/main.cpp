#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a, b; // a为确诊数，b为死亡数
    cin >> a >> b;
    double c = (b * 100.0) / a;
    cout << fixed << setprecision(3) << c << "%";
    return 0;
}
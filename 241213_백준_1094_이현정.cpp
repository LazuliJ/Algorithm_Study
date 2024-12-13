#include <iostream>

using namespace std;

// 백준 1094번 막대기 [비트마스킹]
// 2의 n제곱들의 표현식으로 나타낼 수 있는가?

int X;
int cnt = 0;
void input() {
    cin >> X;
}

int main() {
    input();
    for (int i = 0; i < 7; i++) {
        if ((X & (1 << i)) != 0) cnt++;
    }
    cout << cnt;
}

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// 백준 11723번 집합 [비트마스킹]

int M;
long long S = 0b00;

void add(int num) {
    S = (S | (1 << num));
}

void remove(int num) {
    S = (S & ~(1 << num));
}

void check(int num) {
    if ((S & (1 << num)) != 0) cout << 1 << "\n";
    else cout << 0 << "\n";
}

void toggle(int num) {
    if ((S & (1 << num)) != 0) remove(num);
    else add(num);
}

void all() {
    S = pow(2, 21) -2;
}

void empty() {
    S = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> M;
    for (int i = 0; i < M; i++) {
        string str;
        int num;
        cin >> str;
        if (str == "all") all();
        else if (str == "empty") empty();
        else {
            cin >> num;
            if (str == "add") add(num);
            else if (str == "remove") remove(num);
            else if (str == "check") check(num);
            else if (str == "toggle") toggle(num);
        }
    }
}

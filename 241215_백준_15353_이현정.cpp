#include <iostream>
#include <string>

using namespace std;

// 백준 15353번 큰 수 A+B
/*
수의 범위가 매우 크므로 문자열로 계산한다.
*/

string A, B;
string ans = "";

int main() {
    cin >> A >> B;

    // 길이를 맞춰주는 작업
    int Alen = A.length();
    int Blen = B.length();
    if (Alen > Blen) {
        for (int i = 0; i < Alen-Blen; i++) {
            B = "0" + B;
        }
    }
    else if (Blen > Alen) {
        for (int i = 0; i < Blen-Alen; i++) {
            A = "0" + A;
        }
    }

    int next_num = 0; // 10이상일 때 1을 다음 계산에 사용하기 위해.
    for (int i = A.length() - 1; i >= 0; i--) {
        int this_num = (int(A[i])-int('0')) + (int(B[i])-int('0')) + next_num; // 현재 합
        next_num = this_num / 10;
        this_num %= 10;
        ans = to_string(this_num) + ans;
    }

    // 마지막 연산이 10 이상이라면 마지막으로 1을 연산
    if (next_num != 0) ans  = to_string(next_num) + ans;
    // 출력
    cout << ans;
}

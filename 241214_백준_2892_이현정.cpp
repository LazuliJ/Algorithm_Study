#include <iostream>
#include <string>

using namespace std;

// 백준 2892번 심심한 준규
/*
이 문제는 숫자와 문자의 범위가 다름을 이용한 것으로
xor 했을 때 문자는 64자리의 2진수 비트가 1 이상일 수 밖에 없으므로
이를 이용해 풀이한다.
*/

int N;
string ans = "";

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string num;
        int i_num = 0;
        cin >> num;

        // 16진수 바꾸기기
        for (int i = 0; i < num.length(); i++) {
            i_num *= 16;
            if (num[i] >= '0' and num[i] <= '9') {
                i_num += (int(num[i] - int('0')));
            }
            else {
                i_num += (int(num[i] - int('A')));
            }
        }
        
        // 64자리 비트 검사사
        if ((i_num & 0b01000000) == 0) {
            ans += ".";
        }
        else {
            ans += "-";
        }

    }

    cout << ans;
}

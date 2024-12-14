#include <iostream>
#include <string>

// 백준 14405번 피카츄

using namespace std;

/**/
string ans;
string strs[3] = {"pi", "ka", "chu"};
int end_p = 0;
/**/

int main() {
    cin >> ans;
    while (end_p != ans.length()) {
        int flag;
        // 피카츄가 낼 수 있는 소리 중 1개에 포함되는가?
        for (int i = 0; i < 3; i++) {
            flag = 1;
            for (int j = 0; j < strs[i].length(); j++) {
                if (ans[end_p+j] != strs[i][j]) {
                    flag = 0;
                    break;
                }
            }
            // 피카츄가 낼 수 있음.
            if (flag == 1) {
                end_p += strs[i].length();
                break;
            }
        }
        if (flag == 0) break; // 현재 범위의 소리는 피카츄가 낼 수 없음.
    }

    // 끝까지 피카츄가 모두 발음 가능한지?
    if (end_p != ans.length()) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
}

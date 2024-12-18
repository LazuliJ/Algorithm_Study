#include <iostream>
#include <vector>

// 백준 9935번 문자열 폭발 - 스택

using namespace std;

/**/
string str;
vector<char> ans;
string bomb_str;
/**/

// input
void input() {
    cin >> str;
    cin >> bomb_str;
}

// 스택을 응용해서 1개씩 쌓으면서 폭발 문자열 길이만큼 확인 및 제거
void sol() {
    for (int i = 0; i < str.length(); i++) {
        ans.push_back(str[i]);
        if (ans.size() >= bomb_str.length()) {
            string tmp = "";
            for (int j = ans.size()-bomb_str.length(); j < ans.size(); j++) {
                tmp+=ans[j];
            }
            if (tmp == bomb_str) {
                for (int j = 0; j < bomb_str.length(); j++) {
                    ans.pop_back();
                }
            }
        }
    }
}

// main
int main() {
    input();
    sol();
    // 출력
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    if (ans.size() == 0) {
        cout << "FRULA";
    }
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 백준 2870번 수학숙제

/**/
int N;
string str;
// 문제 조건에 숫자의 최대범위가 직접적으로 나와있지 않으므로 최대는 100자리 수라고 가정한다.
vector<string> vec;
/**/

bool cmp(string a, string b) {
    if (a.length() < b.length()) return true;
    if (a.length() > b.length()) return false;

    for (int i = 0; i < a.length(); i++) {
        if (a < b) return true;
        if (b < a) return false;
    }

    return false;
}

// input
void input() {
    cin >> str;
    str+=" "; //마지막 숫자 처리를 위해 공백 추가
}

// 찾은 숫자 바꾸기
string change_num(string s) {
    string n = "";
    int flag = 0;
    for (int i = 0; i < s.length(); i++) {
        if (flag == 0 and s[i] == '0') continue;
        else {
            flag = 1;
            n += s[i];
        }
    }
    if (n=="") n = "0"; // 0 00 000
    return n;
}

// 문자열에서 숫자 찾기
void find_num(string s) {
    string num = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' and s[i] <= '9') {
            num+=s[i];
        }
        else {
            if (num=="") continue;
            else {
                vec.push_back(change_num(num));
                num = "";
            }
        }
    }
}

// main
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        input();
        find_num(str);
    }
    // 정렬
    sort(vec.begin(), vec.end(), cmp);
    // 출력
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << "\n";
    }
}

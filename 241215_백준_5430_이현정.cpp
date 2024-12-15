#include <iostream>
#include <string>
#include <deque>

// 백준 5430번 AC
/*
덱을 이용해 쉽게 구현할 수 있다.
*/

using namespace std;

int T;
string com = "";
int n = 0;
deque<int> nums;

// init
void init() {
    while (!nums.empty()) {
        nums.pop_front();
    }
}

// input
int input() {
    cin >> com;
    int d_num = 0;
    for (int i = 0; i < com.length(); i++) {
        if (com[i] == 'D') d_num++;
    }

    cin >> n;

    string nums_str;
    cin >> nums_str;
    int num = 0;
    // 주어진 값에서 숫자만 분리 & 저장
    for (int i = 0; i < nums_str.length(); i++) {
        if (nums_str[i] >= '0' and nums_str[i] <= '9') {
            num *= 10;
            num += (int(nums_str[i]) - int('0'));
        }    
        else if (num != 0) {
            nums.push_back(num);
            num = 0;
        }

    }

    if (d_num > n) return -1; // error
    if (d_num == n) return 0; // []
    return 1; // 그 외 (sol함수를 통해 진행)
}

// sol (주어진 커멘드대로 처리)
int sol() {
    int r_dir = 1;
    for (int i = 0; i < com.length(); i++) {
        if (com[i] == 'R') r_dir *= -1;
        else {
            if (r_dir == 1) nums.pop_front();
            else nums.pop_back();
        }
    }
    return r_dir;
}

int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        init();
        int in_flag = input();
        if (in_flag == -1) cout << "error" << "\n";
        else if (in_flag == 0) cout << "[]" << "\n";
        else {
            int dir = sol();
            cout << "[";
            if (dir == 1) {
                for (int i = 0; i < nums.size(); i++) {
                    if (i != 0) cout << ",";
                    cout << nums[i];
                }
            }
            else {
                for (int i = nums.size()-1; i >= 0; i--) {
                    if (i != nums.size()-1) cout << ",";
                    cout << nums[i];
                }
            }
            cout << "]" << "\n";
        }
    }
} 

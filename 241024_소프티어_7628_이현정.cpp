#include<iostream>
#include<vector>

// 단순 완탐 구현 (숫자가 작으므로 시간 초과되지 않음)

using namespace std;

int n;
vector<int> warmer;
int max_size = 0;
int answer = 0;

int main(int argc, char** argv)
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > max_size) max_size = tmp;
        warmer.push_back(tmp);
    }

    for (int i = 2; i <=max_size; i++) {
        int tmp = 0;
        for (int j = 0; j < n; j++) {
            if (warmer[j] % i == 0) tmp++;
        }
        if (tmp > answer) answer = tmp;
    }
    cout << answer;
   return 0;
}

#include <iostream>
#include <algorithm>

using namespace std;

// 백준 30804 과일 탕후루
// DP -> 사실 브루트 포스 또는 투 포인터, 슬라이딩 윈도우로도 풀이할 수 있다고 한다.
// 나는 2차원 배열에 (현재 총 길이, 연속되는 최대 길이) 이런식으로 담아서 풀이함.

int N;
int max_num = 0;
int fruits[200001][2] = {0,};
int cur[2] = {0,};
int ans = 0;

void input() {
    cin >> N;
    int last;
    for (int n = 0; n < N; n++) {
        int fruit;
        cin >> fruit;
        //cout << n << " ";
        if(n == 0) {
            fruits[0][0] = 1;
            fruits[0][1] = 1;
            cur[0] = fruit;
        }
        else if (cur[0] == fruit or cur[1] == fruit) {
            fruits[n][0] = fruits[n-1][0]+1;
            if (last==fruit) fruits[n][1] = fruits[n-1][1]+1;
            else fruits[n][1] = 1;
        }
        else {
            cur[0] = last;
            cur[1] = fruit;
            fruits[n][0] = fruits[n-1][1] + 1;
            fruits[n][1] = 1;
        }
        ans = max(ans, fruits[n][0]);
        last = fruit;
        //cout << fruits[n][0] << " ";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    cout << ans;
} 

#include<iostream>
#include<algorithm>

using namespace std;

/********************/
int MAP[3][3] = {0,};
int ans = 9;
/********************/

// 입력
void input() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> MAP[i][j];
        }
    }
}

// 풀이 (땅 다듬기)
void sol() {
  // 가로줄
    for (int i = 0; i < 3; i++) {
      // 이미 알맞게 다듬어진 땅이 있음.
        if (MAP[i][0] == MAP[i][1] and MAP[i][1] == MAP[i][2]) {
            ans = 0;
            return;
        }
        // 두줄이 같다.
        else if (MAP[i][0] == MAP[i][1] or MAP[i][1] == MAP[i][2] or MAP[i][0] == MAP[i][2]) {
            ans = min(ans, max(abs(MAP[i][0]-MAP[i][1]), abs(MAP[i][1] - MAP[i][2])));
        }
        // 모두 다르다. (1, 2, 3)
        else {
            ans = min(ans, 2);
        }
    }
  // 세로줄
    for (int j = 0; j < 3; j++) {
      // 이미 알맞게 다듬어진 땅이 있음.
        if (MAP[0][j] == MAP[1][j] and MAP[1][j] == MAP[2][j]) {
            ans = 0;
            return;
        }
        // 두줄이 같다.
        else if (MAP[0][j] == MAP[1][j] or MAP[1][j] == MAP[2][j] or MAP[0][j] == MAP[2][j]) {
            ans = min(ans, max(abs(MAP[0][j]-MAP[1][j]), abs(MAP[1][j] - MAP[2][j])));
        }
        // 모두 다르다. (1, 2, 3)
        else {
            ans = min(ans, 2);
        }
    }
}

// main
int main(int argc, char** argv)
{
    input();
    sol();
    cout << ans;
   return 0;
}

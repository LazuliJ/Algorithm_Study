#include <iostream>

using namespace std;

// 백준 10709번 기상캐스터

/**/
int H, W;
int MAP[101][101] = {0,};
int ANS[101][101];
/**/

// init
void init() {
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++) {
            ANS[i][j] = -1;
        }
    }
}

// input
void input() {
    cin >> H >> W;
    char ch;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> ch;
            if (ch == 'c') MAP[i][j] = 1;
        }
    }
}

// sol
void sol() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (MAP[i][j] == 1) {
                for (int l = j; l < W; l++) {
                    ANS[i][l] = (l-j);
                }
            }
        }
    }
}

// main
int main() {
    init();
    input();
    sol();
    // 출력
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << ANS[i][j] << " ";
        }
        cout << "\n";
    }
}

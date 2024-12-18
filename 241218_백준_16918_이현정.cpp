#include <iostream>
#include <deque>

using namespace std;

// 백준 16918번 봄버맨

int R, C, N;
int MAP[200][200] = { 0, }; // -3~-1: 폭탄, 0: 빈 공간
deque<int> changed; // 3초가 지난 폭탄들의 좌표

// input
void input() {
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char init_MAP;
            cin >> init_MAP;
            if (init_MAP == '.') {
                MAP[i][j] = 0;
            }
            else {
                MAP[i][j] = -3;
            }
        }
    }
}

// 방향 배열
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

// 3초가 지나면 폭탄이 터짐.
void explode() {
    while (!changed.empty()) {
        int y = changed.front(); changed.pop_front();
        int x = changed.front(); changed.pop_front();
        
        MAP[y][x] = 0;
        for (int dir = 0; dir < 4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
                MAP[ny][nx] = 0;
            }
        }
    }
}

// 폭탄들의 남은 시간이 1초마다 1씩 감소.
void count_time(int y, int x) {
    if (MAP[y][x] == -1) {
        changed.push_back(y);
        changed.push_back(x);
    }
    else if (MAP[y][x] != 0) {
        MAP[y][x]++;
    }
}

// 2초마다 한번씩 봄버맨이 빈자리에 폭탄을 설치.
void bomberman(int y, int x) {
    MAP[y][x] = -3;
}

// 출력.
void print() {
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (MAP[y][x] == 0) cout << ".";
            else cout << "O";
        }
        cout << "\n";
    }
}

// main
int main() {
    input();
    for (int t = 0; t < N; t++) {
        for (int y = 0; y < R; y++) {
            for (int x = 0; x < C; x++) {
                count_time(y, x);
                if (MAP[y][x] == 0 && t % 2 == 1) {
                    bomberman(y, x);
                }
            }
        }
        explode();
    }
    print();
}

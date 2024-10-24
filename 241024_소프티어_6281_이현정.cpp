#include<iostream>
#include<deque>

using namespace std;

int N, M;
int MAP[100][100] = {0,};
deque<int> melting; // 녹을 좌표 push

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }
}

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

// 외부 공기를 표기 / airs(시작y좌표, 시작x좌표) / BFS
void airs(int yy, int xx) {
    deque<int> dq;
    dq.push_back(yy);
    dq.push_back(xx);
    MAP[yy][xx] = 2;
    while (!dq.empty()) {
        int y = dq.front(); dq.pop_front();
        int x = dq.front(); dq.pop_front();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 or ny >= N or nx < 0 or nx >= M) continue;
            if (MAP[ny][nx] == 1) continue;
            if (MAP[ny][nx] == 2) continue;
            MAP[ny][nx] = 2;
            dq.push_back(ny);
            dq.push_back(nx);
        }
    }
}

// 녹을 좌표를 melting 벡터에 push
void melts() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
        if (MAP[i][j] == 1){
            int count = 0;
            for (int dir = 0; dir < 4; dir++) {
                int y = i + dy[dir];
                int x = j + dx[dir];
                if (y < 0 or y >= N or x < 0 or x >= M) continue;
                if (MAP[y][x] == 2) count++;
            }
            if (count >= 2) {
                melting.push_back(i);
                melting.push_back(j);
            }
        }
    }
}
}

int main(int argc, char** argv)
{
    int ans = 0;
    input();
    airs(0, 0);
    for (int t = 0; t < 100; t++){
        melts();
        if (melting.size() == 0) {
            ans = t;
            break;
        }
        while (!melting.empty()){
            int y = melting.front(); melting.pop_front();
            int x = melting.front(); melting.pop_front();
            airs(y, x); // 내부에 비어있는 공간도 채우기 위해서
            MAP[y][x] = 2;
        }
    }
    cout << ans;
   return 0;
}

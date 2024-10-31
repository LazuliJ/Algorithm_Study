#include<iostream>
#include<queue>

// BFS 이용하는 문제

using namespace std;

int H, W;
int MAP[130][130] = {0,};
queue<int> coloring;

void input() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> MAP[i][j];
        }
    }
}

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int BFS(int y, int x) {
    queue<int> q;
    int color = MAP[y][x];
    q.push(y); coloring.push(y);
    q.push(x); coloring.push(x);
    MAP[y][x] = -1;

    while(!q.empty()) {
        int yy = q.front(); q.pop();
        int xx = q.front(); q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int ny = yy+dy[dir];
            int nx = xx+dx[dir];
            if (ny < 0 or nx < 0 or ny >= H or nx >= W) continue;
            if (MAP[ny][nx] == -1 or MAP[ny][nx] != color) continue;
            q.push(ny); coloring.push(ny);
            q.push(nx); coloring.push(nx);
            MAP[ny][nx] = -1;
        }
    }
    return color;
}

int main(int argc, char** argv)
{
    input();
    int Q;
    cin >> Q;
    for (int k = 0; k < Q; k++) {
        int i, j, c;
        //cout << i << j << c;
        cin >> i >> j >> c;
        int color = BFS(i-1, j-1);
        while(!coloring.empty()) {
            int y = coloring.front(); coloring.pop();
            int x = coloring.front(); coloring.pop();
            MAP[y][x] = c;
            //cout << MAP[y][x];
        }
    }
    //cout << "\n";
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
   return 0;
}

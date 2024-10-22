#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int N;
int MAP[25][25] = {0,};
int visited[25][25] = {0,};
vector<int> vec;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char a;
            cin >> a;
            MAP[i][j] = int(a)-int('0');
        }
    }
}

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

void BFS(int y, int x, int num) {
    queue<int> q;
    q.push(y);
    q.push(x);
    visited[y][x] = 1;
    MAP[y][x] = num;
    
    while (!q.empty()) {
        int yy = q.front(); q.pop();
        int xx = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = yy + dy[i];
            int nx = xx + dx[i];

            if (ny < 0 or nx < 0 or ny >= N or nx >= N) continue;
            if (visited[ny][nx] == 1) continue;
            if (MAP[ny][nx] == 0) continue;

            MAP[ny][nx] = num;
            visited[ny][nx] = 1;
            q.push(ny);
            q.push(nx);
            
        }
    }
    
}

int main(int argc, char** argv)
{
    input();
    int num = 2;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j] != 0) {
                continue;
            }
            if (MAP[i][j] == 1) {
                BFS(i, j, num);
                num++;
            }
        }
    }
    
    for (int i = 2; i < num; i++) {
        vec.push_back(0);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (MAP[i][j] != 0) {
                vec[MAP[i][j]-2]++;
            }
        }
    }

    sort(vec.begin(), vec.end());

    cout << vec.size()<<'\n';
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i]<< '\n';
    }
    
    return 0;
}

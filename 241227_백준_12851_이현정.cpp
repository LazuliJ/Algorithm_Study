#include <iostream>
#include <queue>

using namespace std;

// 백준 12851번 숨바꼭질 2
/*
1. 문제를 처음 봤을 때 DP가 떠오르기 쉬우나 단순 DP로는 시간초과가 난다.
2. BFS를 통해서 불필요한 부분은 탐색하지 않는다.
-> BFS는 시간순으로 진행되는 알고리즘이기 때문에 가능하다.
*/

int N, K;
queue<int> q;
int visited[2000001][2] = {0,};
// visited에 정보를 (최단시간, 방법의 수)로 저장장

// input
void input() {
    cin >> N >> K;
    q.push(N);
    q.push(0);
    visited[N][0] = 0;
    visited[N][1] = 1;
}

// BFS
void BFS() {
    while (!q.empty()) {
        int pos = q.front(); q.pop(); 
        int ti = q.front(); q.pop();
        if (pos == K) {
            break;
        }
        int posb[3] = {2 * pos, pos+1, pos-1};
        for (int i = 0; i < 3; i++) {
            if (visited[posb[i]][1] >= 1) {
                if (visited[posb[i]][0] == ti+1) visited[posb[i]][1] += visited[pos][1];
                continue;   
            }
            if (posb[i] >= 200001 or posb[i] < 0) continue;
            visited[posb[i]][0] = ti+1;
            visited[posb[i]][1] = visited[pos][1];
            q.push(posb[i]);
            q.push(ti+1);
        }
    }
}

// main
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    BFS();
    cout << visited[K][0] << "\n";
    cout << visited[K][1] << "\n";
}

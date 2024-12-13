#include <iostream>
#include <deque>

using namespace std;

// 백준 13244번 Tree 
/*
풀이: Tree에서는 사이클이 생기지 않으므로
각 노드를 1번씩만 방문해야 한다.
BFS로 입력된 에지를 모두 탐사하고 
visited가 1이 아니라면 (방문되지 않았거나, 사이클 발생)
graph로 처리한다.
*/

/**/
int T;
int MAP[1001][1001] = {0,};
int visited[1001] = {0,};
/**/

// 초기화
void init() {
    for (int i = 0; i < 1001; i++) {
        visited[i] = 0;
        for (int j = 0; j < 1001; j++) {
            MAP[i][j] = 0;
        }
    }
}

// BFS 노드 탐색
void BFS(int end) {
    deque<int> dq;
    dq.push_back(1);
    visited[1] = 1;
    
    while(!dq.empty()) {
        int now = dq.front(); dq.pop_front();
        for (int i = 1; i <= end; i++) {
            if (MAP[now][i] > 0) {
                visited[i]++;
                dq.push_back(i);
                MAP[now][i]--;
                MAP[i][now]--;
            }
        }
    }
}

// 모든 visited 탐사하면서 1인지 여부 판단
int is_valid(int end) {
    for (int i = 1; i <= end; i++) {
        if (visited[i]!=1) return 0;
    }
    return 1;
}

// main
int main() {
    cin >> T;
    for (int t = 0; t < T; t++) {
        int M, N;
        init();
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            MAP[u][v]++;
            MAP[v][u]++;
        }
        BFS(N);
        if (is_valid(N) == 1) cout << "tree" << "\n";
        else cout << "graph" << "\n";
    }
}

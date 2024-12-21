#include <iostream>
#include <algorithm>

using namespace std;

// 백준 14889번 스타트와 링크 - DFS

/**/
int N;
int MAP[20][20] = {0,};
int visited[20] = {0,};
int ans = 10000;
/**/

// input
void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
            if (i > j) MAP[j][i]+=MAP[i][j];
        }
    }
}

// DFS
void DFS(int depth, int now) {
    if (depth == N/2) {
        int t_start = 0;
        int t_link = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                if (visited[i] == visited[j]) {
                    if (visited[i] == 0) {
                        t_start += MAP[i][j];
                    }
                    if (visited[i] == 1) {
                        t_link += MAP[i][j];
                    }
                }    
            }
        }
        ans = min(ans, abs(t_start-t_link));
    }
    for (int i = now; i < N; i++) {
        visited[i] = 1;
        DFS(depth+1, i+1);
        visited[i] = 0;
    }
}

// main
int main() {
    input();
    DFS(0, 0);
    cout << ans;
}

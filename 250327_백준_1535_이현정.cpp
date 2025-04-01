#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 1535번 안녕
// DFS

int N;
int ans = 0;
vector<int> health;
vector<int> joy;

void input() {
    cin >> N;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        health.push_back(num);
    }
    for (int j = 0; j < N; j++) {
        cin >> num;
        joy.push_back(num);
    }
}

void DFS(int depth, int cur_health, int cur_joy) {
    if (depth == N) {
        ans = max(ans, cur_joy);
        return;
    }
    if (cur_health-health[depth] > 0 ) {
        DFS(depth+1, cur_health-health[depth], cur_joy+joy[depth]);
    }  
    DFS(depth+1, cur_health, cur_joy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    DFS(0, 100, 0);
    cout << ans;
}

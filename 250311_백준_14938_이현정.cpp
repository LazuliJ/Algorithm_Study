#include <iostream>
#include <algorithm>

using namespace std;

// 백준 14938번 서강그라운드
// - 다익스트라(주요), dfs(내 풀이)
// 일반적인 bfs는 안되는 이유가 최단거리를 탐색할 수 없다는 이유 - 갱신에 많은 시간을 쓴다.
// dfs로 모든 갈 수 있는 길 탐색 -> 표기 -> 표기된 곳 아이템 합

int n, m, r;
int ITEMS[101] = { 0, };
int real_visited[101] = { 0, };
int visited[101] = { 0, };
int MAP[101][101] = { 0, };
int item = 0;
int max_item = 0;

void input() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> ITEMS[i];
	}
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		MAP[a][b] = l;
		MAP[b][a] = l;
	}
}

void DFS(int now_n, int now_m) {
	for (int i = 1; i <= n; i++) {
		if (MAP[now_n][i] != 0 and visited[i] == 0) {
			int next_m = now_m+MAP[now_n][i];
			if (next_m > m) continue;
			visited[i] = 1;
			real_visited[i] = 1;
			DFS(i, next_m);
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();

	for (int i = 1; i <= n; i++) {
		visited[i] = 1;
		real_visited[i] = 1;
		DFS(i, 0);
		for (int j = 1; j <= n; j++) {
			if (real_visited[j] == 1) item += ITEMS[j];
			real_visited[j] = 0;
		}
		max_item = max(item, max_item);
		item = 0;
		visited[i] = 0;
	}
	cout << max_item;
}

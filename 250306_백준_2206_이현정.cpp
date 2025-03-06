#include <iostream>
#include <deque>

using namespace std;

// 백준 2206번 벽 부수고 이동하기
// BFS
/*
단순히 최악의 경우를 가정했을 때 1000*1000이 모두 0의 값일 때 DFS를 생각해보자.
4^1000이므로 절대 안된다.
그러면 BFS로 풀어야 한다. 안되는 값을 필터링 해야 하는데
필터링 할 때 어떻게 간곳을 세아리냐 -> 3차원으로 세아리면 된다.
즉 1, 1을 벽을 부수었을 때/아닐 때 이렇게 나누어서 visited처리를 해주면 된다.
*/

int N, M;
int ans = -1;

int MAP[1001][1001] = { 0, };
int visited[1001][1001][2] = { 0, };

struct state {
	int y = 0, x = 0;
	int num = 0;
	int dist = 0;
};

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char x;
			cin >> x;
			MAP[i][j] = int(x)-int('0');

		}
	}
}

int dy[4] = { 1, 0, 0, -1 };
int dx[4] = { 0, 1, -1, 0 };

void BFS() {
	deque<state> dq;
	state s;
	dq.push_back(s);

	while (!dq.empty()) {
		state cur;
		cur = dq.front(); dq.pop_front();
		if (cur.y == N - 1 and cur.x == M - 1) {
			ans = cur.dist+1;
		}
		for (int i = 0; i < 4; i++) {
			state cur_now;
			int ny = cur.y + dy[i];
			int nx = cur.x + dx[i];
			if (ny < 0 or nx < 0 or ny >= N or nx >= M) continue;
			if (MAP[ny][nx] == 1 and cur.num == 1) continue;
			if (ans != -1 and cur.dist > ans) continue;
			int now_num = cur.num + MAP[ny][nx];
			if (visited[ny][nx][now_num] == 1) continue;
			visited[ny][nx][now_num] = 1;
			cur_now.y = ny; cur_now.x = nx; cur_now.num = now_num; cur_now.dist = cur.dist + 1;
			dq.push_back(cur_now);
		}
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	visited[0][0][0] = 1;
	visited[0][0][1] = 1;
	BFS();
	cout << ans;
}

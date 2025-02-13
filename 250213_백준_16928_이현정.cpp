#include <iostream>
#include <deque>

using namespace std;

// 백준 16928번 뱀과 사다리 게임
// BFS

int visited[101] = { 0, };
int ladder[15][2] = { 0, };
int snake[15][2] = { 0, };

struct now {
	int num;
	int t = 0;
};

int N, M;
deque<now> dq;

void input() {
	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		int x, y;
		cin >> x >> y;
		ladder[n][0] = x;
		ladder[n][1] = y;
		visited[x] = 2;
	}
	for (int m = 0; m < M; m++) {
		int u, v;
		cin >> u >> v;
		snake[m][0] = u;
		snake[m][1] = v;
		visited[u] = 3;
	}
	visited[1] = 1;
	now n;
	n.num = 1;
	dq.push_back(n);
}

int main() {
	input();
	int ans = 0;
	while (true) {
		now n = dq.front(); dq.pop_front();
		if (n.num == 100) {
			ans = n.t;
			break;
		}
		else {
			for (int i = 1; i <= 6; i++) {
				now next;
				int nextnum = n.num + i;
				if (visited[nextnum] == 1) continue;
				else if (visited[nextnum] == 3) {
					for (int m = 0; m < M; m++) {
						if (snake[m][0] == nextnum) {
							visited[nextnum] = 1;
							nextnum = snake[m][1];
							visited[nextnum] = 1;
						}
					}
				}
				else if (visited[nextnum] > 100) continue;
				else if (visited[nextnum] == 2) {
					for (int n = 0; n < N; n++) {
						if (ladder[n][0] == nextnum) {
							visited[nextnum] = 1;
							nextnum = ladder[n][1];
							visited[nextnum] = 1;
						}
					}
				}
				visited[nextnum] = 1;
				next.num = nextnum;
				next.t = n.t + 1;
				dq.push_back(next);
			}
		}
	}
	cout << ans;
}

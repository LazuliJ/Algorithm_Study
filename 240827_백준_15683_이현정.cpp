#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
int MAP[8][8] = { 0, };

struct tv {
	int y, x;
	int type;

	bool operator<(tv right) const {
		return type < right.type;
	}
};

priority_queue<tv> pq;

// 입력
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> MAP[i][j];
			if (MAP[i][j] != 0 && MAP[i][j] != 6) {
				pq.push({ i, j, MAP[i][j] });
			}
		}
	}
}


// 4 방향의 zero 개수를 세는 cctv
int dy[4] = {-1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int dir_count[4] = { 0, 0, 0, 0 };  // 아래 함수를 사용하기 전 반드시 초기화

void count_zeros(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int v = 1; int cnt = 0;
		while (true) {
			int ny = y + dy[i] * v;
			int nx = x + dx[i] * v;

			if (ny < 0 or nx < 0 or ny >= N or nx >= M) break;
			if (MAP[ny][nx] == 6) break;
			if (MAP[ny][nx] == 0) cnt++;

			v++;
		}
		dir_count[i] = cnt;
	}
}

void fill_zeros(int y, int x, int dir) {
	int v = 1;
	while (true) {
		int ny = y + dy[dir] * v;
		int nx = x + dx[dir] * v;

		if (ny < 0 or nx < 0 or ny >= N or nx >= M) break;
		if (MAP[ny][nx] == 6) break;
		if (MAP[ny][nx] == 0) MAP[ny][nx] = 7;

		v++;
	}
}

void simulation_cctv() {
	while (!pq.empty()) {
		tv big_tv = pq.top(); pq.pop();
		if (big_tv.type == 5) {
			for (int i = 0; i < 4; i++) {
				fill_zeros(big_tv.y, big_tv.x, i);
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				dir_count[i] = 0;
			}
			count_zeros(big_tv.y, big_tv.x);

			if (big_tv.type == 4) {
				int tmp[4] = { dir_count[0] + dir_count[1] + dir_count[2],
					dir_count[0] + dir_count[1] + dir_count[3],
					dir_count[0] + dir_count[2] + dir_count[3],
					dir_count[1] + dir_count[2] + dir_count[3] };

				if (tmp[0] >= tmp[1] and tmp[0] >= tmp[2] and tmp[0] >= tmp[3]) {
					fill_zeros(big_tv.y, big_tv.x, 0);
					fill_zeros(big_tv.y, big_tv.x, 1);
					fill_zeros(big_tv.y, big_tv.x, 2);
				}

				else if (tmp[1] >= tmp[2] and tmp[1] >= tmp[0] and tmp[1] >= tmp[3]) {
					fill_zeros(big_tv.y, big_tv.x, 0);
					fill_zeros(big_tv.y, big_tv.x, 1);
					fill_zeros(big_tv.y, big_tv.x, 3);
				}

				else if (tmp[2] >= tmp[1] and tmp[2] >= tmp[0] and tmp[2] >= tmp[3]) {
					fill_zeros(big_tv.y, big_tv.x, 0);
					fill_zeros(big_tv.y, big_tv.x, 2);
					fill_zeros(big_tv.y, big_tv.x, 3);
				}

				else {
					fill_zeros(big_tv.y, big_tv.x, 1);
					fill_zeros(big_tv.y, big_tv.x, 2);
					fill_zeros(big_tv.y, big_tv.x, 3);
				}
			}

			if (big_tv.type == 3) {
				int tmp[4] = { dir_count[0] + dir_count[1],
					dir_count[1] + dir_count[2],
					dir_count[2] + dir_count[3],
					dir_count[3] + dir_count[0] };

				if (tmp[0] >= tmp[1] and tmp[0] >= tmp[2] and tmp[0] >= tmp[3]) {
					fill_zeros(big_tv.y, big_tv.x, 0);
					fill_zeros(big_tv.y, big_tv.x, 1);
				}

				else if (tmp[1] >= tmp[2] and tmp[1] >= tmp[0] and tmp[1] >= tmp[3]) {
					fill_zeros(big_tv.y, big_tv.x, 2);
					fill_zeros(big_tv.y, big_tv.x, 1);
				}

				else if (tmp[2] >= tmp[1] and tmp[2] >= tmp[0] and tmp[2] >= tmp[3]) {
					fill_zeros(big_tv.y, big_tv.x, 2);
					fill_zeros(big_tv.y, big_tv.x, 3);
				}

				else {
					fill_zeros(big_tv.y, big_tv.x, 3);
					fill_zeros(big_tv.y, big_tv.x, 0);
				}
			}

			if (big_tv.type == 2) {
				int tmp[4] = { dir_count[0] + dir_count[2],
					dir_count[1] + dir_count[3] };

				if (tmp[0] >= tmp[1]) {
					fill_zeros(big_tv.y, big_tv.x, 0);
					fill_zeros(big_tv.y, big_tv.x, 2);
				}

				else {
					fill_zeros(big_tv.y, big_tv.x, 1);
					fill_zeros(big_tv.y, big_tv.x, 3);
				}
			}

			if (big_tv.type == 1) {
				int tmp[4] = { dir_count[0] ,
					dir_count[1],
					dir_count[2],
					dir_count[3] };

				if (tmp[0] >= tmp[1] and tmp[0] >= tmp[2] and tmp[0] >= tmp[3]) {
					fill_zeros(big_tv.y, big_tv.x, 0);
				}

				else if (tmp[1] >= tmp[2] and tmp[1] >= tmp[0] and tmp[1] >= tmp[3]) {
					fill_zeros(big_tv.y, big_tv.x, 1);
				}

				else if (tmp[2] >= tmp[1] and tmp[2] >= tmp[0] and tmp[2] >= tmp[3]) {
					fill_zeros(big_tv.y, big_tv.x, 2);
				}

				else {
					fill_zeros(big_tv.y, big_tv.x, 3);
				}
			}
		}
	}
}

int ans = 0;

void find_ans() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (MAP[i][j] == 0) ans += 1;
		}
	}
}

int main() {
	input();
	simulation_cctv();
	find_ans();
	cout << ans;
}
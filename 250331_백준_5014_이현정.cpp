#include <iostream>
#include <algorithm>

using namespace std;

// 백준 5014번 스타트링크
// DFS

int F, S, G, U, D;
int floors[1000001];

void init() {
	for (int i = 0; i < 1000001; i++) {
		floors[i] = 1000001;
	}
}

void input() {
	cin >> F >> S >> G >> U >> D;
}

void find(int n, int times) {
	bool if_U = false;
	bool if_D = false;
	if (n+U <= F and times < floors[n + U]) {
		floors[n + U] = times;
		if_U = true;
	}
	if (n-D >= 1 and times < floors[n - D]) {
		floors[n - D] = times;
		if_D = true;
	}
	if (if_U) find(n + U, times + 1);
	if (if_D) find(n - D, times + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	input();
	floors[S] = 0;
	find(S, 1);
	if (floors[G] == 1000001) cout << "use the stairs";
	else cout << floors[G];
}

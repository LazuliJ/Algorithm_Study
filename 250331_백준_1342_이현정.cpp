#include <iostream>
#include <string>

using namespace std;

// 백준 1342번 행운의 문자열
// DFS -> BFS 사용하면 더 빠르게 풀이 가능

string S;
int ans = 0;

int ALPHA[10] = { 0, };
int DAT[30] = { 0 };

void input() {
	cin >> S;
	for (auto s : S) {
		DAT[s - int('a')]++;
	}
}

void DFS(int depth, string s ) {
	if (depth == S.length()) {
		ans++;
		return;
	}
	for (int i = 0; i < S.length(); i++) {
		if (depth != 0 and s[depth - 1] == S[i]) continue;
		if (ALPHA[i] != 0) continue;
		ALPHA[i] = 1;
		DFS(depth + 1, s+S[i]);
		ALPHA[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	DFS(0, "");
	for (int i = 0; i < 30; i++) {
		if (DAT[i] > 1) {
			for (int n = 1; n <= DAT[i]; n++) {
				ans /= n;
			}
		}
	}
	cout << ans;
}

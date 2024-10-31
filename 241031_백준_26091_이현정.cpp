#include <iostream>
#include <vector>
#include <algorithm>

// 투 포인터 + 그리디 이용
// 양방향 큐를 이용해서 풀수도 있음.

using namespace std;

int N, M;
vector<int> human;
int ans = 0;

int main() {
	cin >> N >> M;
	int p1 = 0, p2 = N - 1;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		human.push_back(tmp);
	}
	sort(human.begin(), human.end());
	while (p1 < p2) {
		if (human[p1] + human[p2] > M) {
			ans++;
			p1++;
			p2--;
		}
		else {
			p1++;
		}
	}
	cout << ans;
}

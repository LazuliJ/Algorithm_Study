#include <iostream>

// 백준 2828번 사과 담기 게임

using namespace std;

int start_p = 1, end_p;
int M, N, tc;
int ans = 0;;

void input() {
	cin >> M >> N;
	cin >> tc;
}

int main() {
	input();
	end_p = N;
	for (int t = 0; t < tc; t++) {
		int num;
		cin >> num;
		if (start_p <= num and end_p >= num) {
			continue;
		}
		else {
			if (end_p < num) {
				start_p += num - end_p;
				ans += num - end_p;
				end_p = num;
			}
			else {
				end_p -= start_p - num;
				ans += start_p - num;
				start_p = num;
			}
		}
	}
	cout << ans;
}

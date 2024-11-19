#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int r, c;
void input() {
	cin >> N;
	cin >> r >> c;
}

int main() {
	long long answer = 0;
	input();

	while (N >= 1) {
		if (r <= (pow(2, N - 1) - 1) and c <= (pow(2, N - 1) - 1)) {
			answer += 0 * pow(pow(2, N - 1), 2);
		}
		else if (r <= (pow(2, N - 1) - 1) and c > (pow(2, N - 1) - 1)) {
			answer += 1 * pow(pow(2, N - 1), 2);
			c -= pow(2, N - 1);
		}
		else if (r > (pow(2, N - 1) - 1) and c <= (pow(2, N - 1) - 1)) {
			answer += 2 * pow(pow(2, N - 1), 2);
			r -= pow(2, N - 1);
		}
		else if (r > (pow(2, N - 1) - 1) and c > (pow(2, N - 1) - 1)) {
			answer += 3 * pow(pow(2, N - 1), 2);
			c -= pow(2, N - 1);
			r -= pow(2, N - 1);
		}
		N--;
	}
	cout << answer;
}

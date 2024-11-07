#include <iostream>
#include <algorithm>

using namespace std;

long long X, Y, W, S;

int main() {
	cin >> X >> Y >> W >> S;
  // 1 * 1에서 대각선으로 가는 것이 유리할 때 
	if (2 * W > S) {
    // 1 * 2에서 대각선으로 2번 가는 것이 유리할 때
		if ( 2 * W > 2 * S) {
			cout << min(X, Y) * S + ((max(X, Y) - min(X, Y))/2) *2 * S+(max(X, Y) - min(X, Y)) % 2 * W;
		}
    // 1 * 2에서 대각선 1번, 직선 1번 가는 것이 유리할 때
		else {
			cout << min(X, Y) * S + (max(X, Y) - min(X, Y)) * W;
		}
	}
  // 1 * 1에서 직선으로 2번 이동하는 것이 유리할 때
	else {
		cout << (X + Y) * W;
	}

}

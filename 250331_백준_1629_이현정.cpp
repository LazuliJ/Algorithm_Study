#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

// 백준 1629번 곱셈
// 재귀

ll A, B, C;
ll ans;

vector<ll> numbers;

void input() {
	cin >> A >> B >> C;
}

ll act(ll num) {
	if (num == 1) return (A % C);
	if (num % 2 == 1)  return (((act((num - 1) / 2) % C) * (act((num - 1) / 2) % C)%C) * act(1)) % C;
	if (num % 2 == 0)  return (act((num) / 2) % C) * (act((num) / 2) % C)%C;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	cout << act(B);
}

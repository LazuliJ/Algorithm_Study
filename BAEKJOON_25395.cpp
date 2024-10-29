// 백준 25395번 커넥티드 카 실험
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, S; // 차 총 개수, 시작 차량
int connected_car[1000001] = { 0, };

struct car {
	int num;
	int coord;
	int oil;
	bool operator<(car c) const {
		if (coord < c.coord) return true;
		if (coord > c.coord) return false;
		return false;
	}
};

vector<car> cars;
queue<car> q;

void input() {
	cin >> N >> S;

	car c_0;
	c_0.num = 0;
	c_0.coord = -1;
	cars.push_back(c_0);

	for (int i = 1; i <= N; i++) {
		car c;
		c.num = i;
		cin >> c.coord;
		cars.push_back(c);
	}
	
	for (int i = 1; i <= N; i++) {
		cin >> cars[i].oil;
		if (i == S) {
			q.push(cars[i]);
		}
	}
	sort(cars.begin(), cars.end());
}

int main() {
	input();
	while (!q.empty()) {
		car cur = q.front(); q.pop();
		int i = cur.num;
		connected_car[i] = 1;
		while (true) {
			if (i == 0) break;
			if (cars[i - 1].coord < cur.coord - cur.oil) break;
			if (connected_car[cars[i - 1].num] == 1) {
				i--;
				continue;
			}
			connected_car[cars[i - 1].num] = 1;
			q.push(cars[i - 1]);
			i--;
		}

		i = cur.num;
		while (true) {
			if (i == N) break;
			if (cars[i + 1].coord > cur.coord + cur.oil) break;
			if (connected_car[cars[i + 1].num] == 1) {
				i++;
				continue;
			}
			connected_car[cars[i + 1].num] = 1;
			q.push(cars[i + 1]);
			i++;
		}
	}
	
	for (int i = 1; i <= N; i++) {
		if (connected_car[i] == 1) {
			cout << i << " ";
		}
	}
}

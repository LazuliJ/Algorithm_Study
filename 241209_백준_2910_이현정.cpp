#include <iostream>
#include <vector>
#include <algorithm>

// 백준 2910번 빈도 정렬

/*
stable sort (안정 정렬) = 중복된 값의 원래 순서를 보장
unstable sort(불안정 정렬) <->

기본적인 sort는 unstable sort에 속하며
보장하기 위해서는 아래처럼 부등호 재정의 때 명시적으로 지정하거나
stable_sort명령어를 이용하면 된다.
*/

using namespace std;

long long N, C;

struct cons {
	long long num;
	int cnt = 1;
	int fir_ac;
	bool operator<(cons c) const {
		if (cnt > c.cnt) return true;
		if (cnt < c.cnt) return false;

		if (fir_ac < c.fir_ac) return true;
		if (fir_ac > c.fir_ac) return false;
		return false;
	}
};

vector<cons> vec_con;

void input() {
	cin >> N >> C;
}

void sol() {
	for (int i = 0; i < N; i++) {
		long long n;
		cin >> n;
		for (int j = 0; j < vec_con.size(); j++) {
			if (vec_con[j].num == n) {
				n = -1;
				vec_con[j].cnt++;
				break;
			}
		}
		if (n == -1) {
			continue;
		}
		else {
			cons c;
			c.num = n;
			c.fir_ac = i + 1;
			vec_con.push_back(c);
		}
	}
}

int main() {
	input();
	sol();
	sort(vec_con.begin(), vec_con.end());
	for (int i = 0; i < vec_con.size(); i++) {
		for (int j = 0; j < vec_con[i].cnt; j++) {
			cout << vec_con[i].num << " ";
		}
	}
}

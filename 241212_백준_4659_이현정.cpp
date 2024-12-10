#include <iostream>
#include <string>

// 백준 4659번 비밀번호 발음하기

using namespace std;

string words;
char w1[5] = {'a', 'e', 'i', 'o', 'u'};
int flag1 = 0, flag2 = 0, flag3 = 0;
int sum_w = 0;

void init() {
	flag1 = 0; flag2 = 0; flag3 = 0;
	sum_w = 0;
}

void input() {
	cin >> words;
}

int main() {
	while (true) {
		init();
		input();
		if (words == "end") break;
		for (int i = 0; i < words.length(); i++) {
			// 조건1. 모음 1개 이상
			for (int j = 0; j < 5; j++) {
				if (words[i] == w1[j]) {
					sum_w++;
					flag1 = 1;
				}
				if (i >= 3 and words[i - 3] == w1[j]) {
					sum_w--;
				}
			}
			// 조건3. 연속인 단어 (e와 o는 제외)
			if (i != 0 and words[i] == words[i - 1]) {
				if (words[i] != 'e' and words[i] != 'o') {
					flag3 = 1;
					break;
				}
			}
			// 조건2. 연속 3개의 자음/모음
			if (i >= 2 and (sum_w == 3 or sum_w == 0)) {
				flag2 = 1;
				break;
			}

		}
		cout << "<" << words << ">" << " is";
		if (flag1 == 0 or flag2 == 1 or flag3 == 1) cout << " not";
		cout << " acceptable.\n";

	}
}

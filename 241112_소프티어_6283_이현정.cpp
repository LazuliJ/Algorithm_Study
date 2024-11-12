#include <iostream>

// 소프티어 6283번 8단 변속기

using namespace std;

int numbers[8];
int mode = 0;

int main() {
	for (int i = 0; i < 8; i++) {
		cin >> numbers[i];
	}
	if (numbers[0] < numbers[1]) {
		mode = 0;
	}
	else {
		mode = 1;
	}
	for (int i = 2; i < 8; i++) {
		if (numbers[i - 1] < numbers[i]) {
			if (mode == 1) {
				mode = 2;
				break;
			}
		}
		if (numbers[i - 1] > numbers[i]) {
			if (mode == 0) {
				mode = 2;
				break;
			}
		}
	}

	if (mode == 0) {
		cout << "ascending\n";
	}
	else if (mode == 1) {
		cout << "descending\n";
	}
	else {
		cout << "mixed\n";
	}
}

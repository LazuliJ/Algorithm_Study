#include <iostream>

using namespace std;

// 백준 1244번 스위치 켜고 끄기 - 구현
// 출력 형식 (20개씩만 출력)에 유의할 것

/**/
int N;
int swth[101] = {0,};

int T;
int gen, num;
/**/

// input
void input() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> swth[i];
    }
    cin >> T;
}

// 남학생일 때
void m_swth(int num) {
    for (int i = 1; i <= N; i++) {
        if (i % num == 0) {
            swth[i] ^= 1;
        }
    }
}

// 여학생일 때
void w_swth(int num) {
    for (int i = 0; i <= N; i++) {
        if (num-i == 0) break;
        if (num+i == N+1) break;
        if (swth[num-i] != swth[num+i]) break;

        if (i == 0) {
            swth[num] ^= 1;
            continue;
        }
        swth[num-i] ^= 1;
        swth[num+i] ^= 1;
    }
}

// main
int main() {
    input();
    for (int i = 0; i < T; i++) {
        cin >> gen >> num;
        if (gen == 1) m_swth(num);
        if (gen == 2) w_swth(num);
    }
    for (int i = 1; i <= N; i++) {
        cout << swth[i] << " ";
        if (i % 20 == 0) cout << "\n";
    }
}

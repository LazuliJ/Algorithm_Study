#include <iostream>
#include <vector>

using namespace std;

// 백준 2531번 회전 초밥 - 슬라이딩 윈도우(투포인터)

int N, d, k, c;
vector<int> belt; // 벨트 위 초밥들
int check[3001] = {0,}; // 해당 번호 먹는지 확인
int st = 0, ed; // 시작, 끝 포인터
int ans = 0, cnt = 0; // 정답 / 현재 몇개

// 현재 몇 종류 초밥을 먹을 수 있는지 판단
void check_max() {
    if (check[belt[st]] == 1) cnt--;
    check[belt[st]]--;
    st = (st+1) % N;

    ed = (ed+1) % N;
    if (check[belt[ed]] == 0) cnt++;
    check[belt[ed]]++;

    ans = max(ans, cnt);
}

// input
void input() {
    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        belt.push_back(num);
    }
    ed = k-1;
    for (int i = st; i <= ed; i++) {
        if (check[belt[i]] == 0) cnt++;
        check[belt[i]]++;
    }
    if (check[c] == 0) cnt++;
    check[c]++;
    ans = max(ans, cnt);
}

// main
int main() {
    input();
    while (true) {
        check_max();
        if (st == 0) break;
    }
    cout << ans;
}

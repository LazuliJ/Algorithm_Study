#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 20922번 겹치는 건 싫어
/*
회전 초밥과 거의 비슷하나
정해진 개수(슬라이딩 윈도우)가 아니기 때문에
다음수가 이미 K개 만큼 있다면 K개가 아닐 때까지
시작 포인터를 증가시키는 방식으로 해결
*/

int N, K;
vector<int> numbers;
int cnt_numbers[100001] = {0,};
int st = 0, ed = 0;
int ans = 1;

//input
void input() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    cnt_numbers[numbers[0]]++;
}

// 최대 길이 찾기
void find_max_length() {
    if (cnt_numbers[numbers[ed+1]] == K) {
        while (cnt_numbers[numbers[ed+1]] == K) {
            cnt_numbers[numbers[st]]--;
            st++;
        }
    }
    else {
        ed++;
        cnt_numbers[numbers[ed]]++;
        ans = max(ans, (ed-st+1));
    }
}

// main
int main() {
    input();
    while (ed != (N-1)) {
        find_max_length();
    }
    cout << ans;
}

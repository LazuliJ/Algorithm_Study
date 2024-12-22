#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// 백준 1806번 부분합

int N;
ll S;
int ans = 100001;
vector<ll> numbers;
int st = 0, ed = 0;
ll now = 0;

void input() {
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        ll num;
        cin >> num;
        numbers.push_back(num);
    }
    now = numbers[st];
}

void find_min_len() {
    // S '이상'을 만족할 때 최소 길이
    if (now >= S) {
        ans = min(ans, (ed-st+1));
        now -= numbers[st];
        st++;
    }
    else if (now < S) {
        ed++;
        if (ed >= N) return;
        now += numbers[ed];
    }
}

int main() {
    input();
    while (ed != N) {
        find_min_len();
    }

    if (ans == 100001) cout << 0;
    else cout << ans;
}

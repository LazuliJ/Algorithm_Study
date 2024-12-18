#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// 백준 1911번 흙길 보수하기

ll N, L;
vector<pair<ll, ll>> vec;

/*
판자로 연결한 끝이 다른 웅덩이의 시작지점보다 크다면
그대로 이어서 연결한다.
*/

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
    if (p1.first < p2.first) return true;
    if (p1.first > p2.first) return false;

    return false;
}

void input() {
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        ll st, ed;
        cin >> st >> ed;
        vec.push_back(make_pair(st, ed));
    }
    sort(vec.begin(), vec.end(), cmp);
}

int main() {
    input();
    ll start_p = vec[0].first;
    ll end_p = vec[0].second;
    ll cnt = 0;
    for (int i = 1; i < N; i++) {
        ll sp = vec[i].first;
        ll ep = vec[i].second;
        ll now = ((end_p-start_p) / L) + ((end_p-start_p) % L != 0);
        if (start_p + now * L > sp) end_p = ep;
        else {
            cnt += now;
            start_p = sp;
            end_p = ep;
        }
    }
    cnt += ((end_p-start_p) / L) + ((end_p-start_p) % L != 0);
    cout << cnt;
}

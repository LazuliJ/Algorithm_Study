#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

// 백준 12865번 평범한 배낭
// DP / (세분화하면 냅색문제)

int N;
ll K;
ll ans = 0;
vector<pair<ll, ll>> bag;
ll weights[100001] = {0,};

bool cmp(pair<ll, ll> p1, pair<ll, ll> p2) {
    if (p1.first < p2.first) return true;
    if (p1.first > p2.first) return false;

    if (p1.second > p2.second) return true;
    if (p1.second < p2.second) return false;

    return false;
}

void init() {
    for (int i = 0; i < 100001; i++) {
        weights[i] = -1;
    }
}

void input() {
    cin >> N >> K;
    ll W, V;
    for (int i = 0; i < N; i++) {
        cin >> W >> V;
        bag.push_back({W, V});
    }
    sort(bag.begin(), bag.end(), cmp);
}

void find() {
    weights[0] = 0;

    for (int j = 0; j < N; j++) {
        queue<ll> q;
        for (int i = 0; i <= K; i++) {
            if (weights[i]!=-1 and i+bag[j].first <=K) {
                q.push(i+bag[j].first);
                q.push(weights[i]+bag[j].second);
            }
        }
        while (!q.empty()) {
            ll w = q.front(); q.pop();
            ll v = q.front(); q.pop();
            weights[w] = max(weights[w], v);
        }
    }   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    input();
    find();
    for (int i = 0; i <= K; i++) {
        //cout << weights[i] << " ";
        ans = max(ans, weights[i]);
    }
    cout << ans;
}

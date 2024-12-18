#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// 백준 2170번 선 긋기

ll N;
vector<pair<ll, ll>> vec;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        ll s, e;
        cin >> s >> e;
        vec.push_back(make_pair(s, e));
    }
    sort(vec.begin(), vec.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll len = 0, st_p, ed_p;
    input();    
    st_p = vec[0].first;
    ed_p = vec[0].second;
    for (int i = 1; i < N; i++) {
        ll sp = vec[i].first;
        ll ep = vec[i].second;
        if (sp <= ed_p) ed_p = max(ed_p, ep);
        else {
            len += (ed_p - st_p);
            st_p = sp;
            ed_p = ep; 
        }
    }
    len += (ed_p-st_p);
    cout << len;
}

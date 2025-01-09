#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

// 20207번 단순 구현, DAT

/*
몇개가 최대로 겹치는지 = h  
겹치는 구간의 길이 = l
날짜별로 DAT를 만들어서 겹치는 날짜들이 총 몇 개인지 알아내기
*/

int N;
int date[367] = {0,};
int l = 0, h = 0;
ll ans = 0;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int S, E;
        cin >> S >> E;
        for (int j = S; j <= E; j++) {
            date[j]++;
        }

    }
}

void sol() {
    for (int i = 0; i < 367; i++) {
        if (l != 0 and date[i] == 0) {
            ans += (l * h);
            l = 0;
            h = 0;
        }
        else if (date[i] == 0) {
            continue;
        }
        else {
            l++;
            h = max(h, date[i]);
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    sol();
}

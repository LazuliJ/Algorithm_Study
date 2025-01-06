#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<double> vec;
double A, st = -1*(10e6+1), ed = 10e6+1;

void input() {
    cin >> N >> A;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
}

int cal_min(int i) {
    double st_ = ((vec[i] - A) / (i+1));
    double ed_ = ((vec[i]+1 - A) / (i+1));
    if (i!=0 and (ed <= st_ or st >= ed_)) return 0; 
    if (i!=0 and (st_ < 0 or ed_ <= 0)) return 0;
    st = max(st, st_);
    ed = min(ed, ed_);
    return 1;
}

int main() {
    cout.precision(11); // 10자리 수까지 출력
    // 소수점 아래수만 다루고 싶으면 cout << fixed;를 사용해야 함.
    input();
    if (N == 0) {
        cout << "0.0";
        return 0;
    }
    else {
        for (int i = 0; i < N; i++) {
            int res = cal_min(i);
            if (res == 0) {
                st = 10e6+1;
                break;
            }
        }
    }
    if (st == 10e6+1 or ed <= 0) cout << -1;
    else if (st <= 0) cout << "0.0";
    else {
        cout << st;
    }
}

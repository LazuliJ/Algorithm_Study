#include <iostream>

using namespace std;

// 백준 15922번 아우으 우아으이야!!

int N;
long long start_p, end_p;
long long total_len = 0;

int main() {
    cin >> N;
    cin >> start_p >> end_p;
    for (int i = 1; i < N; i++) {
        long long s_p, e_p;
        cin >> s_p >> e_p;
        if (e_p <= end_p) continue;
        else if (s_p <= end_p and e_p >= end_p) end_p = e_p;
        else {
            total_len += (end_p - start_p);
            start_p = s_p;
            end_p = e_p;
        }
    }
    total_len += (end_p - start_p);
    cout << total_len;
}

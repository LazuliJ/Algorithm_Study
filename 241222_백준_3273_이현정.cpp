#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// 백준 3273번 두 수의 합 - 투포인터

/**/
int n;
vector<ll> numbers;
ll x;
int p1 = 0, p2;
int cnt = 0;
/**/

// input
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        numbers.push_back(num);
    }
    cin >> x;
    p2 = n-1;
}

// sol
void sol() {
    sort(numbers.begin(), numbers.end());
    while (p1 < p2) {
        if (numbers[p1] + numbers[p2] == x) {
            cnt++;
            p2--;
        }
        if (numbers[p1] + numbers[p2] > x) {
            p2--;
        }
        else {
            p1++;
        }
    }
}

// main
int main() {
    input();
    sol();
    cout << cnt;
}

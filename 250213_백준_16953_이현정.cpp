#include <iostream>
#include <queue>

using namespace std;
typedef long long ll;
// int visited[1000000001] = { 0, }; 당연하지만 메모리 초과난다.

// 백준 16953번 A -> B
// BFS

ll A, B;
struct node {
    ll num;
    int cal = 0;
    bool operator< (node A) const {
        if (num < A.num) return true;
        if (num > A.num) return false;
        return false;
    }
};

int main() {
    cin >> A >> B;
    int ans = -1;
    priority_queue<node> pq;

    node n;
    n.num = A;
    pq.push(n);
    while (!pq.empty()) {
        node cur = pq.top(); pq.pop();
        if (cur.num > B) continue;
        else if (cur.num == B) {
            ans = cur.cal + 1;
            break;
        }
        else {
            node next1, next2;
            next1.num = cur.num * 2;
            next2.num = cur.num * 10 + 1;
            next1.cal = cur.cal + 1;
            next2.cal = cur.cal + 1;

            pq.push(next1);
            pq.push(next2);

        }
    }
    cout << ans;
}

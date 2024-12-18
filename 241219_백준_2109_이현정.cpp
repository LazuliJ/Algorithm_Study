#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>

// 백준 2109번 순회강연

using namespace std;

/*
1. deque에 pair로 넣고 cmp로 기간이 적은 순부터 정렬한다.
2. heap에 기간만큼 최대한의 이득을 볼 수 있게 최대한 채운다.
3. heap의 숫자들을 모두 더한다. = 정답
*/

/**/
int n, p, d;
long long ans = 0;

typedef pair<int, int> pa;
deque<pa> vec;
/**/

bool cmp(pa p1, pa p2) {
    // 기간이 짧고
    if (p1.second < p2.second) return true;
    if (p1.second > p2.second) return false;

    // 이득이 큰 순서대로
    if (p1.first > p2.first) return true;
    if (p1.first < p2.first) return false;

    return false;
}

// min heap
priority_queue<int, vector<int>, greater<int>> pq;

// 입력 및 정렬
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        vec.push_back(make_pair(p, d));
    }
    sort(vec.begin(), vec.end(), cmp);
}

// 기간안에 얻을 수 있는 최대한의 이득 찾기
void sort_max() {
    while(!vec.empty()){
        // 기간보다 가기로 결정한 강의 수가 적으면 무조건 추가
        if (pq.size() < vec.front().second) {
            pq.push(vec.front().first);
            vec.pop_front();
        }
        // 아닐 경우 이전 선택한 강의의 최소 이득과 비교해서 크면 추가
        else if (pq.top() < vec.front().first) {
            pq.pop();
            pq.push(vec.front().first);
            vec.pop_front();
        }
        // 조건에 부합하지 않는 강의는 하지 않는다.
        else {
            vec.pop_front();
        }
    }
}

// heap의 값들의 합을 구하기
void cal_max() {
    while(!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans;
}

// main
int main() {
    input();
    sort_max();
    cal_max();
}

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

// 프로그래머스(142085) 디펜스 게임 - 우선순위 큐(Priority Queue)

priority_queue<int, vector<int>, greater<>> pq;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    for (auto e: enemy) {
        if (!pq.empty() and pq.size() == k and n < min(e, pq.top())) break;
        answer++;
        if (pq.size() < k) {
            pq.push(e);
        }
        else {
            if (pq.top() > e) {
                n -= e;
            }
            else {
                n -= pq.top();
                pq.pop();
                pq.push(e);
            }
        }
    }
    cout << pq.top();
    return answer;
}

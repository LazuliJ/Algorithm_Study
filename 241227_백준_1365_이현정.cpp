#include <iostream>
#include <vector>

using namespace std;

// 백준 1365번: 꼬인 전깃줄
/*
처음 문제를 풀 때 LIS를 통해 접근하려고 하였으나,
DP방식으로 구현하면 시간초과가 난다.
따라서 이분탐색방식으로 구현해야 한다.
*/

int N; // 전봇대의 개수
int conn[100001] = {0,}; // 전선들의 정보
vector<int> lis;

void input() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> conn[i];
    }
}

int bin_search(int start, int end, int target) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (lis[mid-1] <= target and lis[mid] > target) {
            return mid;
        }
        else if (lis[mid] < target) {
            start = mid+1;
        }
        else {
            end = mid-1;
        }
    }
    return 0;
}

int main() {
    input();
    lis.push_back(conn[0]);
    for (int i = 1; i < N; i++) {
        if (conn[i] > lis.back()) {
            lis.push_back(conn[i]);
        }
        else {
            int idx = bin_search(0, lis.size()-1, conn[i]);
            lis[idx] = conn[i];
        }
    }
    cout << N - lis.size();
}

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 프로그래머스 81302번 거리두기 확인하기

// 방향배열 (12방향)
int dy[12] = {1, 0, -1, 0, 1, 1, -1, -1, 2, 0, 0, -2};
int dx[12] = {0, 1, 0, -1, 1, -1, 1, -1, 0, 2, -2, 0};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int t = 0; t < 5; t++) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (places[t][i][j]!='P') continue;
                for (int dir = 0; dir < 12; dir++) {
                    int di = i + dy[dir];
                    int dj = j + dx[dir];
                    
                    if (di < 0 or dj < 0 or di >= 5 or dj >= 5) continue;
                    if (places[t][di][dj] != 'P') continue;
                    // 대각선에 있을 때 (dx또는 dy 방향으로 1칸씩 옆이 모두 파티션이라면)
                    if (dir >= 4 and dir <8) {
                        if (places[t][di + (-1 * dy[dir])][dj] == 'X' and places[t][di][dj + (-1 * dx[dir])] == 'X') {
                            continue;
                        }
                        else {
                            cout << i << j << dir;
                            answer.push_back(0);
                            break;
                        }
                    }
                    // 2칸 떨어진 곳에 있을 때 (1칸 덜 갔을 때 그곳에 파티션이라면)
                    else if (dir >=8 ) {
                        if (abs(dy[dir]) == 2 and places[t][di + (-1 * (dy[dir]/2))][dj] == 'X') {
                            continue;
                        }
                        else if (abs(dx[dir]) == 2 and places[t][di][dj + (-1 * (dx[dir])/2)] == 'X') {
                            continue;
                        }
                        else {
                            cout << i << j << dir;
                            answer.push_back(0);
                            break;
                        }
                    }
                    else {
                        cout << i << j << dir;
                        answer.push_back(0);
                        break;
                    }
                }
                if (answer.size() != t) break;
            }
            if (answer.size() != t) break;
        }
        if (answer.size() == t) answer.push_back(1);
    }
    return answer;
}

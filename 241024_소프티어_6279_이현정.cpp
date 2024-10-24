#include<iostream>
#include<vector>
#include<string>
using namespace std;

// 그리디 (가장 왼쪽 멀리 집을 수 있는 부품부터 무조건 집기)

int N, K;
string ori_line; // string 형태 입력
vector<int> line; // 입력을 벡터에 push (1 = 로봇, 0 = 부품, 2 = 이미 집힌 부품)

void input() {
    cin >> N >> K;
    cin >> ori_line;
    for (int i = 0; i < ori_line.length(); i++) {
        if (ori_line[i] == 'P') line.push_back(1);
        else if (ori_line[i] == 'H') line.push_back(0);
    }
}

int main(int argc, char** argv)
{
    input();
    int answer = 0;
    for (int i = 0; i < line.size(); i++) {
    if (line[i] == 1) {
        for (int j = -1 * K; j <= K; j++) {
            int nj = i + j;
            if (nj < 0 or nj >= line.size()) continue;
            if (line[nj] == 0) {
                line[nj] = 2;
                answer++;
                break;
                }
            }        
        }
    }
    cout << answer;
   return 0;
}

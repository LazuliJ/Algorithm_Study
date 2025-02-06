#include<iostream>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

// 소프티어 7721번 루돌프 월드컵
// round = 반올림 (곱하기 나누기 적절히 섞으면 n째자리 수까지 가능)
// 되도록이면 소수점 연산을 할 때는 double로 쓰자 (정확도 이슈)

int F[4] = {0,};
int depth_team[6][2] = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3}};
int visited[6] = {0,};
double ans = 0;

void input() {
    for (int i = 0; i < 4; i++) {
        cin >> F[i];
    }
}

double to_3(double num) {
    num *= 1000;
    num = round(num);
    num *= 0.001;
    return num;
}

void DFS(int depth) {
    if (depth == 6) {
        double tmp_ans = 1.0; 
        int one, two;
        int scores[4] = {0,};
        for (int i = 0; i < 6; i++) {
            one = depth_team[i][0];
            two = depth_team[i][1];
            if (visited[i] == 1) {
                double pos = double(F[one] * 4) / double(5 * F[two] + 5 * F[one]);
                tmp_ans*=pos;
                scores[one] += 3;
            } else if (visited[i] == -1) {
                double pos = double(F[two] * 4) / double(5 * F[two] + 5 * F[one]);
                tmp_ans*=pos;
                scores[two] += 3;
            } else {
                double pos = double(F[one] + F[two]) / double(5 * F[two] + 5 * F[one]);
                tmp_ans*=pos;
                scores[one] += 1;
                scores[two] += 1;
            }
        }
        if ((int(scores[0] >= scores[1]) + int(scores[0] >= scores[2]) + int(scores[0] >= scores[3])) >= 2) {
            tmp_ans *= 100;
            ans += tmp_ans;
        }
        return;
    }
    else {
        for (int i = 1; i >= -1; i--) {
            visited[depth] = i;
            DFS(depth+1);
            visited[depth] = 0;
        }
    }
}

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    input();
    DFS(0);
    cout << to_3(ans);

    //cout << ans;
    if (int(to_3(ans) * 1000) % 100 == 0) cout << "00";
    else if (int(to_3(ans) * 1000) % 10 == 0) cout << "0";
    return 0;
}

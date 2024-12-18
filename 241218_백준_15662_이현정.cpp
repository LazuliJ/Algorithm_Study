#include <iostream>

using namespace std;

// 백준 15662번 톱니바퀴(2)

/**/
int T, K;
string gears[1001]; // 기어들의 정보
int gear_p[1001] = {0,}; // 9시 방향 기어(왼쪽)
int change_p[1001] = {0,}; // 한번 회전할 때 어떻게 회전해야 하는지
/**/

// input
void input() {
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cin >> gears[i];
        gear_p[i] = 6;
    }
    cin >> K;
}

// num번 기어 회전
void rotate(int num) {
    gear_p[num] = (8+(change_p[num]*-1)+gear_p[num]) % 8;
    change_p[num] = 0;
}

// 1번 회전당 돌아가는 기어들의 정보를 저장 
void sol() {
    int num, dir;
    cin >> num >> dir;
    change_p[num] = dir;

    // 왼쪽 확인
    int num_l = num - 1;
    int dir_l = dir * -1;
    while (num_l > 0) {
        if (gears[num_l][(gear_p[num_l]+4)%8] == gears[num_l+1][gear_p[num_l+1]]) break;
        change_p[num_l] = dir_l;
        num_l--;
        dir_l *= -1;
    }

    // 오른쪽 확인
    int num_r = num+1;
    int dir_r = dir * -1;
    while (num_r <= T) {
        if (gears[num_r-1][(gear_p[num_r-1]+4)%8] == gears[num_r][gear_p[num_r]]) break;
        change_p[num_r] = dir_r;
        num_r++;
        dir_r *= -1;
    }

    // 주의점: 문제에서 회전할 때 "동시에" 돌아간다에 주목한다. 연쇄적으로 돌아가는 것이 아니다.
    for (int i = 1; i <= T; i++) {
        rotate(i);
        
    }
}

// main
int main() {
    int cnt = 0;
    input();
    for (int t = 0; t < K; t++) {
        sol();
    }
    for (int i = 1; i <= T; i++) {
        if (gears[i][(gear_p[i]+2)%8] == '1') cnt++;
    }
    cout << cnt;
}

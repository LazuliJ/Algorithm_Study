#include<iostream>
#include<string>

using namespace std;

/**********************/
char MAP[5][5]; // key 5*5 배열
int map_p = 0; // map만들기 위해 사용하는 포인터
int visited[26] = {0,}; // map만들기 위해 사용하는 visited 배열

string mesg, key;
string new_mesg = ""; // 두글자씩 가공한 mesg
int mesg_p = 0; // new_mesg 만들기 위해 사용기
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (MAP[i][j] == new_mesg[2 * t]) {
                    i1 = i; j1 = j;
                    break;
                }
            }
            if (i1 != -1 and j1 != -1) {
                break;
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (MAP[i][j] == new_mesg[2 * t+1]) {
                    i2 = i; j2 = j;
                    break;
                }
            }
            if (i2 != -1 and j2 != -1) {
                break;
            }
        }
        // 줄 / 열 / 모두 다를 떄
        if (i1 == i2) {
            ans = ans + MAP[i1][(j1+1)%5] + MAP[i1][(j2+1)%5];
        }
        else if (j1 == j2) {
            ans = ans + MAP[(i1+1)%5][j1] + MAP[(i2+1)%5][j1];
        }
        else {
            ans = ans + MAP[i1][j2] + MAP[i2][j1];
        }
    }
}

// main
int main(int argc, char** argv)
{
    input();
    make_MAP();
    make_mesg();
    make_ans();
    cout << ans;
   return 0;
}

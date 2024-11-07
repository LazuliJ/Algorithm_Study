#include<iostream>
#include<string>

using namespace std;

/**********************/
char MAP[5][5]; // key 5*5 배열
int map_p = 0; // map만들기 위해 사용하는 포인터
int visited[26] = {0,}; // map만들기 위해 사용하는 visited 배열

string mesg, key;
string new_mesg = ""; // 두글자씩 가공한 mesg
int mesg_p = 0; // new_mesg 만들기 위해 사용하는 포인터

string ans = "";
/**********************/

void input() {
    cin >> mesg;
    cin >> key;
}

void make_MAP() {
    visited[int('J')-int('A')] = 1;
    for (int i = 0; i < key.length(); i++) {
        if (visited[int(key[i])-int('A')]!=1) {
            visited[int(key[i])-int('A')] = 1;
            MAP[map_p/5][map_p%5] = key[i];
            map_p++;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (visited[i] == 0) {
            MAP[map_p/5][map_p%5] = char(i+int('A'));
            map_p++;
        }
    }
}

void test_make_MAP() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << MAP[i][j] << " ";
        }
        cout << "\n";
    }
}

void make_mesg() {
    while (mesg_p != mesg.length()) {
        if (mesg_p == mesg.length()-1) {
            new_mesg += mesg[mesg_p];
            break;
        }
        if (mesg[mesg_p] != mesg[mesg_p+1]) {
            new_mesg = new_mesg + mesg[mesg_p] + mesg[mesg_p+1];
            mesg_p+=2;
        }
        else {
            if (mesg[mesg_p] != 'X') {
                new_mesg = new_mesg + mesg[mesg_p] + 'X';
                mesg_p++;
            }
            else {
                new_mesg = new_mesg + mesg[mesg_p] + 'Q';
                mesg_p++;
            }
        }
    }
    if (new_mesg.length() %2 == 1) new_mesg += 'X';
}

void test_make_mesg() {
    cout << new_mesg;
}

void make_ans() {
    for (int t = 0; t < new_mesg.length()/2; t++) {
        int i1 = -1, j1 = -1, i2 = -1, j2 = -1;
        
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

int main(int argc, char** argv)
{
    input();
    make_MAP();
    make_mesg();
    make_ans();
    cout << ans;
   return 0;
}

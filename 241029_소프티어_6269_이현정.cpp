#include<iostream>
#include<vector>
#include<string>

using namespace std;

int M, N, K;
int m = 0;
vector<int> secret;
vector<int> nums;
string ans = "normal";

void input() {
    cin >> M >> N >> K;
    for (int i = 0; i < M; i++) {
        int tmp;
        cin >> tmp;
        secret.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }
}


int main(int argc, char** argv)
{
    input();
    for (int i = M-1; i < N; i++) {
        if (ans == "secret") break;
        int tmp = M-1;
        for (int j = i; j >=i+1-M; j--) {
            if (nums[j] == secret[tmp]) {
                tmp--;
            }
            else {
                break;
            }
            if (j == i+1-M) {
                ans = "secret";
            }
        }
    }

    cout << ans;
   return 0;
}

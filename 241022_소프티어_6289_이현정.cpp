#include<iostream>

using namespace std;

int N, M;
int MAP[100001] = {0,};
int weights[100001] = {0,};

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> weights[i];
    }
}

int main(int argc, char** argv)
{
    int answer = 0;
    input();
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (weights[a] <= weights[b]) MAP[a] = 1;
        if (weights[b] <= weights[a]) MAP[b] = 1;
    }

    for (int i = 1; i <= N; i++) {
        if (MAP[i] == 0) answer++;
    }
    cout << answer;
    return 0;
}

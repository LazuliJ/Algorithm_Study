#include <iostream>
#include <string>
#include <vector>

// 백준 1062번 가르침
/*
모든 string에 대해 있는 알파벳을 2진수 방식으로 표기한다. 
(1: 있음, 0: 없음)

ans를 통해 현재 배운 알파벳을 2진수로 표기한다.
이때 a, n, t, i, c의 5개 알파벳은 필수로 배워야 하므로 K가 5보다 작다면 답은 0이다.

DFS를 통해 모든 알파벳을 배우는 경우의 수를 고려해 각각의 경우 몇 개의 단어를 쓸 수 있는지 계산한다.
이때, 최대 수가 정답이다.
*/

using namespace std;

/**/
int N, K;
vector<long long> vec; // 남극 단어들
long long ans = 0; // 현재 배우고 있는 알파벳
int vocab = 0; // 최대 단어 개수(정답)
/**/

void input() {
    cin >> N >> K;
    // 남극 단어들의 알파벳 유무를 2진수로 표기
    for (int i = 0; i < N; i++) {
        string str;
        long long vec_str = 0;
        
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            vec_str = (vec_str | (1 << int(str[j]) - int('a')));
        }
        vec.push_back(vec_str);
    }

    // 필수 알파벳인 a, n, t, i, c을 배움
    string str = "antic";
    for (int i = 0; i < 5; i++) {
        ans = ( ans | (1 << int(str[i]) - int('a')));
    }
}

// DFS
void DFS(int depth, int end) {
    if (depth == K-5) {
        int tmp_vocab = 0;
        for (int i = 0; i < N; i++) {
            if ((vec[i] & ~(ans)) == 0) tmp_vocab++; 
        }
        if (vocab < tmp_vocab) vocab = tmp_vocab;
        return;
    }
    for (int i = end; i < 26; i++) {
        if ((ans & (1 << i)) != 0) {
            continue;
        }
        ans = (ans | (1 << i));
        DFS(depth+1, i+1);
        ans = (ans & ~(1 << i));
    }
}

// main
int main() {
    input();
    if (K >= 5) DFS(0, 1); // 5개 미만은 단어 학습이 불가능
    cout << vocab;
}

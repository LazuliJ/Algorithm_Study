#include<iostream>

// Softeer 바이러스 (Level 2)

using namespace std;
typedef long long ll;

ll K, P, N;

int main(int argc, char** argv)
{
    cin >> K >> P >> N;
    for (int i = 0; i < N; i++) {
        K = (K*P) % 1000000007;
    }
    cout << K;
    return 0;
}

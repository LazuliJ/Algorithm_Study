#include<iostream>

int N;
int n = 2; // 현재 한 변의 점의 갯수

using namespace std;

int main(int argc, char** argv)
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        n += (n-1);
    }
    cout << n * n;
    return 0;
}

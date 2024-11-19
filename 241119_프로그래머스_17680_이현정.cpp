#include <string>
#include <vector>

using namespace std;

string cache[31];
void init() {
    for (int i = 0; i < 31; i++) {
        cache[i] = "";
    }
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    for (int i = 0; i < cities.size(); i++) {
        int flag = 0;
        for (int l = 0; l < cities[i].length(); l++) {
            if (cities[i][l] > 'Z') cities[i][l] = char(int(cities[i][l]) - int('a') + int('A'));
        }
        for (int j = 0; j < cacheSize; j++) {
            if (cache[j] == cities[i]) {
                flag = j;
                answer+=1;
                break;
            }
            if (j == cacheSize-1) {
                flag = cacheSize-1;
                answer+=5;
            }
        }
        while (flag != 0) {
            cache[flag] = cache[flag-1];
            flag--;
        }
        cache[0] = cities[i];
    }
    if (cacheSize == 0) answer += cities.size() * 5;
    return answer;
}

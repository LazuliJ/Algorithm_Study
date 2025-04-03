#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 프로그래머스(43164) 여행경로 - DFS

int visited[10001] = {0,};
bool if_found_ans = false;
vector<string> answer_o;
vector<vector<string>> tickets_o;
bool cmp (vector<string> t1, vector<string> t2) {
    if (t1[0] < t2[0]) return true;
    if (t1[0] > t2[0]) return false;
    
    if (t1[1] < t2[1]) return true;
    if (t1[1] > t2[1]) return false;
    
    return false;
}

void DFS(string cur) {
    if (answer_o.size() == tickets_o.size()) {
        if_found_ans = true;
        return;
    }
    for (int i = 0; i < tickets_o.size(); i++) {
        if (visited[i] == 1) continue;
        if (tickets_o[i][0] == cur) {
            visited[i] = 1;
            answer_o.push_back(tickets_o[i][1]);
            DFS(tickets_o[i][1]);
            if (if_found_ans == true) break;
            answer_o.pop_back();
            visited[i] = 0;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end(), cmp);
    for (auto t: tickets) tickets_o.push_back(t);
    answer.push_back("ICN");
    DFS("ICN");
    for (auto a: answer_o) {
        answer.push_back(a);
    } 
    
    return answer;
}

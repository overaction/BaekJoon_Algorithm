#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int, vector<int>, greater<int>> pq_des;
    priority_queue<int, vector<int>> pq_asc;
    int cnt = 0;

    for(int i=0; i<operations.size(); i++) {
        string now = operations[i];
        // 숫자 삽입
        if(now[0] == 'I') {
            cnt++;
            pq_asc.push(stoi(now.substr(2)));
            pq_des.push(stoi(now.substr(2)));
        }
        // 최댓값 또는 최솟값 삭제
        else if(now[0] == 'D' && cnt != 0) {
            if(now[2] == '-') pq_des.pop();
            else pq_asc.pop();
            cnt--;

            if(cnt == 0) {
                while(!pq_des.empty()) pq_des.pop();
                while(!pq_asc.empty()) pq_asc.pop();
            }
        }
    }

    // 정답
    if(cnt == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(pq_asc.top());
        answer.push_back(pq_des.top());
    }
    return answer;
}

int main() {
    priority_queue <int> q;
    q.push(1);
    q.push(5);
    q.push(2);
    for(int i=0; i<q.size(); i++) {
        printf("%d\n",q.top());
        q.pop();
    }

    string t = "-23";
    printf("%d\n",stoi(t));
}
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <regex>
using namespace std;
bool selected[8];
char character[8] = {'A','C','F','J','M','N','R','T'};
vector < char > v(8,'x');
int answer;
// 순열
void dfs(int cnt, vector<string> data) {
    if(cnt == 8) {
        for(int i=0; i<data.size(); i++) {
            char first = data[i][0];
            char second = data[i][2];
            char op = data[i][3];
            int dist = data[i][4] - '0';
            dist+=1;
            // first,second의 인덱스 찾기
            int idx1 = -1,idx2 = -1;
            for(int j=0; j<8; j++) {
                if(first == v[j]) idx1 = j;
                if(second == v[j]) idx2 = j;
                if(idx1 != -1 && idx2 != -1) break;
            }
            // 비교
            if(op == '<' && abs(idx1-idx2) >= dist) return;
            if(op == '=' && abs(idx1-idx2) != dist) return;
            if(op == '>' && abs(idx1-idx2) <= dist) return;
        }
        answer++;
        return;
    }
    for(int i=0; i<8; i++) {
        if(selected[i]) continue;
        selected[i] = true;
        v[cnt] = character[i];
        dfs(cnt+1,data);
        selected[i] = false;
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    char arr[8] = {NULL,};
    answer = 0;
    dfs(0,data);
    return answer;
}

int main() {
    
}
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
int S;
typedef struct option {
    // 화면 클립보드 시간
    int screen,clip,time;
}option;
// 화면,클립보드
int visited[1001][1001];
int answer = 0;

void solution() {
    deque < option > dq;
    dq.push_back({1,0,0});
    visited[1][0] = 1;
    while(!dq.empty()) {
        int s = dq.front().screen;
        int c = dq.front().clip;
        int t = dq.front().time;
        dq.pop_front();
        // 답을 찾음
        if(S == s) {
            answer = t;
            break;
        }
        // 화면에 있는 이모티콘을 클립보드에 복사
        if(visited[s][s] == 0) {
            dq.push_back({s,s,t+1});
            visited[s][s] = 1;
        }
        // 클립보드에 있는 이모티콘을 화면에 복사
        if(c != 0 && s+c <= 1000 && visited[s+c][c] == 0) {
            dq.push_back({s+c,c,t+1});
            visited[s+c][c] = 1;
        }
        if(s != 0 && visited[s-1][c] == 0) {
            dq.push_back({s-1,c,t+1});
            visited[s-1][c] = 1;
        }
    }
    return;
}

int main()
{
    scanf("%d",&S);
    solution();
    printf("%d\n",answer);
}


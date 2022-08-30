#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int S;
int visited[1001][1001]; // [d][c]
typedef struct options {
    int display_q, clipboard_q, time_q;
}op;

void solution() {
    queue < op > q;
    q.push({1,0,0});
    visited[1][0] = 1;
    while(!q.empty()) {
        int d = q.front().display_q;
        int c = q.front().clipboard_q;
        int t = q.front().time_q;
        q.pop();
        if(d == S) {
            printf("%d\n",t);
            break;
        }
        // 클립보드에 복사
        if(visited[d][d] == 0) {
            q.push({d,d,t+1});
            visited[d][d] = 1;
        }
        // 화면에 복사
        if(c != 0 && d+c <= 1000 && visited[d+c][c] == 0) {
            q.push({d+c,c,t+1});
            visited[d+c][c] = 1;
        }
        // 이모티콘 삭제
        if(d != 0 && visited[d-1][c] == 0) {
            q.push({d-1,c,t+1});
            visited[d-1][c] = 1;
        } 
    }    
}

int main() {
    scanf("%d",&S); 
    solution();
}
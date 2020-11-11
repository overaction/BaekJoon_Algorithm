#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int N,M,cnt=0;
int visited[101];
int computer[101][101];
deque < int > dq;

void bfs(int v) {
    dq.push_back(v);
    visited[v] = 1;
    while(!dq.empty()) {
        int next = dq.front();
        dq.pop_front();
        for(int i=1; i<=N; i++) {
            if(!computer[next][i]) continue;
            if(visited[i]) continue;
            dq.push_back(i);
            visited[i] = 1;
            cnt++;
        }
    }
}

int main() {
    int x,y;
    scanf("%d %d",&N,&M);
    for(int i=0; i<M; i++) {
        scanf("%d %d",&x,&y);
        computer[x][y] = 1;
        computer[y][x] = 1;
    }
    bfs(1);
    printf("%d",cnt);
}

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;
int N,M;
int maze[101][101];
int visited[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void solution() {
    deque < pair < int,int > > dq;
    visited[0][0] = 1;
    dq.push_back({0,0});
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(visited[ny][nx]) continue;
            if(maze[ny][nx] == 0) continue;
            if(ny >= N || ny < 0 || nx >= M || nx < 0) continue;
            
            visited[ny][nx] = 1;
            maze[ny][nx] = maze[y][x] + 1;
            dq.push_back({ny,nx});
        }
    }
    printf("%d\n",maze[N-1][M-1]);
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%1d",&maze[i][j]);
        }
    }
    solution();
}
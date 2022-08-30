#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <list>
using namespace std;
int maze[101][101];
int N,M;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
deque < pair <int,int> > dq;
int visited[101][101];

void bfs() {
    visited[1][1] = 1;
    dq.push_back(make_pair(1,1));
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int newy = dy[i] + y;
            int newx = dx[i] + x;
            if(newy > N || newy <= 0 || newx > M || newx <= 0)
                continue;
            if(maze[newy][newx] == 0) continue;
            if(visited[newy][newx] == 1) continue;
            visited[newy][newx] = 1;
            maze[newy][newx] += maze[y][x];
            dq.push_back(make_pair(newy,newx));
        }
    }
};

int main()
{
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%1d",&maze[i][j]);
        }
    }
    bfs();
    printf("%d",maze[N][M]);
}

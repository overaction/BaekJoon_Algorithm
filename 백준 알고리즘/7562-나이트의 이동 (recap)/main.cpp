#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;
int T,N;
int maze[301][301];
int visited[301][301];
int ddy[8] = {-2,-1,1,2,-2,-1,1,2};
int ddx[8] = {1,2,2,1,-1,-2,-2,-1};
int sy,sx,dy,dx;

void solution() {
    deque < pair < int,int > > dq;
    dq.push_back({sy,sx});
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        if(y == dy && x == dx) break;
        dq.pop_front();

        for(int i=0; i<8; i++) {
            int ny = y + ddy[i];
            int nx = x + ddx[i];
            if(ny >= N || ny < 0 || nx >= N || nx < 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            dq.push_back({ny,nx});
        }
    }
    printf("%d\n",visited[dy][dx]);
}

int main() {
    scanf("%d",&T);
    for(int i=0; i<T; i++) {
        scanf("%d",&N);
        scanf("%d %d %d %d",&sy,&sx,&dy,&dx);
        solution();
        memset(visited,0,sizeof(visited));
    }
}
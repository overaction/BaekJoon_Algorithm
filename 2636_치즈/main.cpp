#include <iostream>
#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;
int N,M,time=0;
int cheese[101][101];
int visited[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int result = 0;
deque < pair < int,int > > cq;
deque < pair < int,int > > melt;
void bfs(int sy, int sx) {
    visited[sy][sx] = 1;
    deque < pair < int,int > > dq;
    dq.push_back(make_pair(sy,sx));
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        int ismelt = 0;
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(cheese[ny][nx]==1 && visited[ny][nx]==0) {
                dq.push_back(make_pair(ny,nx));
                visited[ny][nx] = 1;
            }

            while(ny <= N && ny >= 1 && nx <= M && nx >= 1) {
                if(ny == N || nx == M || ny == 1 || nx == 1) {
                    ismelt = 1;
                    break;
                }
                if(cheese[ny][nx]) break;
                ny += dy[i];
                nx += dx[i];
            }
            }

        if(ismelt) {
            melt.push_back(make_pair(y,x));
        }
    }
}
int main()
{
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d",&cheese[i][j]);
            if(cheese[i][j]) cq.push_back(make_pair(i,j));
        }
    }
    int cqsize = cq.size();
    while(1) {
        printf("\n");
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
                printf("%d ",cheese[i][j]);
        }
        printf("\n");
    }
        for(int i=0; i<cqsize; i++) {
            int y = cq[i].first;
            int x = cq[i].second;
            if(visited[y][x] == 0) {
                bfs(y,x);
            }
        }
        result = cqsize;
        memset(visited,0,sizeof(visited));
        cq.clear();
        time++;
        // 치즈 녹이기
        int meltSize = melt.size();
        printf("melt %d\n",meltSize);
        for(int i=0; i<meltSize; i++) {
            int y = melt[i].first;
            int x = melt[i].second;
            cheese[y][x] = 0;
        }
        melt.clear();
        // 남은 치즈 다시 넣기
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(cheese[i][j]) cq.push_back(make_pair(i,j));
            }
        }
        cqsize = cq.size();
        if(cqsize == 0) {
            break;
        }
    }
    printf("%d\n",time);
    printf("%d",result);
}

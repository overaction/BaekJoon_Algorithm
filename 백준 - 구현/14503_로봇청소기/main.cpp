#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;
int N,M,cleanCnt = 0;
bool possible = false;
int dy[4] = {-1,0,1,0}; // 북 서 남 동
int dx[4] = {0,-1,0,1};
int sy,sx,d;
int house[51][51];
deque < pair < int,int > > dq;

void bfs() {
    dq.push_back(make_pair(sy+1,sx+1));
    house[sy+1][sx+1] = 2;
    cleanCnt++;
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        possible = false;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            d = d+1;
            if(d >= 4) d = 0;
            printf("d %d\n",d);
            int ny = y + dy[d];
            int nx = x + dx[d];

            if(ny >= N || ny <= 1 || nx >= M || nx <= 1) continue;
            if(house[ny][nx] != 0) continue;

            // 청소할 공간이 있는경우
            house[ny][nx] = 2;
            cleanCnt++;
            possible = true;
            dq.push_back(make_pair(ny,nx));
            break;
        }
        if(!possible) {
            // 네 방향 모두 청소할 곳이 없으면
            int next = (d+2)%4;
            y = y + dy[next];
            x = x + dx[next];
            dq.push_back(make_pair(y,x));
            if(house[y][x] == 1) {
                return;
            }
        }
    }
}

int main()
{
    scanf("%d %d",&N,&M);
    scanf("%d %d %d",&sy,&sx,&d);
    switch(d) {
    case 1:
        d = 3;
        break;
    case 3:
        d = 1;
        break;
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d",&house[i][j]);
        }
    }
    bfs();
    printf("%d",cleanCnt);
}

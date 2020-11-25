#include <iostream>
#include <stdio.h>
#include <deque>
#include <vector>
#include <string.h>
using namespace std;
typedef struct options {
    int y,x,cnts;
}options;
int N,M,cnt=0,iceCount=0,time=0;
int ice[301][301];
int visited[301][301];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
vector < pair < int,int > > dq;
deque < options > temp;

void checkIceCount(int y, int x) {
    visited[y][x] = 1;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny > N || ny <= 0 || nx > M || nx <= 0) continue;
        if(visited[ny][nx]) continue;
        if(ice[ny][nx] == 0) continue;
        checkIceCount(ny,nx);
    }
}

void hit() {
    // ºùÇÏ ³ìÀÌ±â
    int dqSize = dq.size();
    for(int i=0; i<dq.size(); i++) {
        int y = dq[i].first;
        int x = dq[i].second;
        if(ice[y][x] == 0) continue;
        cnt = 0;
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny > N || ny <= 0 || nx > M || nx <= 0) continue;
            if(ice[ny][nx] == 0) cnt++;
        }
        options op = {y,x,cnt};
        temp.push_back(op);
    }
    int tempSize = temp.size();
    for(int i=0; i<tempSize; i++) {
        options next = temp.front();
        temp.pop_front();
        int y = next.y, x = next.x, cnts = next.cnts;
        ice[y][x] = ice[y][x] - cnts;
        if(ice[y][x] <= 0) ice[y][x] = 0;
    }
    // ºùÇÏ °³¼ö Ã¼Å©
    for(int i=0; i<dqSize; i++) {
        int y = dq[i].first;
        int x = dq[i].second;
        if(visited[y][x] || ice[y][x] == 0) continue;
        checkIceCount(y,x);
        iceCount++;
    }
}

int main()
{
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d",&ice[i][j]);
            if(ice[i][j] != 0) dq.push_back(make_pair(i,j));
        }
    }
    while(1) {
        iceCount = 0;
        hit();
        time++;
        if(iceCount >= 2) break;
        if(iceCount == 0) {
            time = 0;
            break;
        }
        memset(visited,0,sizeof(visited));
    }
    printf("%d",time);
}

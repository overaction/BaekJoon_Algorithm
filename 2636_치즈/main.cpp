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
int answer = 0;
deque < pair < int,int > > cheeseq;
deque < pair < int,int > > meltq;
void calculate() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(cheese[i][j] == 1)
                result++;
        }
    }
}

void setAir() {
    memset(visited,0,sizeof(visited));
    deque < pair < int,int > > dq;
    dq.push_back(make_pair(1,1));
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(visited[ny][nx]) continue;
            if(ny > N || ny <= 0 || nx > M || nx <= 0) continue;
            if(cheese[ny][nx] == 1) continue;
            cheese[ny][nx] = 3; // 공기
            dq.push_back(make_pair(ny,nx));
            visited[ny][nx] = 1;
        }
    }
}

void melting(int sy, int sx) {
    deque < pair <int,int> > dq;
    dq.push_back(make_pair(sy,sx));
    visited[sy][sx] = 1;
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny > N || ny <= 0 || nx > M || nx <= 0) continue;
            if(cheese[ny][nx] == 3) {
                cheese[y][x] = 2; // 다음에 녹을 치즈
            }
            if(visited[ny][nx] == 0 && cheese[ny][nx] == 1){
                visited[ny][nx] = 1;
                dq.push_back(make_pair(ny,nx));
            }
        }
    }
}

void meltandfind() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(cheese[i][j] == 2) {
                cheese[i][j] = 3;
            }
            else if(cheese[i][j] == 1)
                cheeseq.push_back(make_pair(i,j));
        }
    }
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d",&cheese[i][j]);
            if(cheese[i][j] == 1) cheeseq.push_back(make_pair(i,j));
        }
    }
    while(1) {
        int qsize = cheeseq.size();
        if(qsize == 0) break;
        time++;
        // 바깥공기 검색
        setAir();
        result = 0;
        calculate();
        // 바깥공기에 의해 녹을 치즈들 검색
        for(int i=0; i<qsize; i++) {
            int y = cheeseq[i].first;
            int x = cheeseq[i].second;
            if(visited[y][x] == 0) melting(y,x);
        }
        cheeseq.clear();
        // 녹임
        meltandfind();
    }
    printf("%d\n%d",time,result);
}

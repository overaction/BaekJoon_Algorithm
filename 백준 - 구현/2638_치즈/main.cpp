#include <iostream>
#include <stdio.h>
#include <deque>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
struct option {
    int y,x;
    bool melted;
};
int N,M,time=0;
int paper[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
vector < option > cheese;
deque < pair < int,int > > dq;

// 외부공기를 표시
void meltingAir() {
    dq.push_back({1,1});
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y +dy[i];
            int nx = x +dx[i];
            if(ny > N || ny<=0 || nx>M || nx<=0) continue;
            if(paper[ny][nx] == 0) {
                paper[ny][nx] = 3;
                dq.push_back({ny,nx});
            }
        }
    }
}

void meltingAir_second() {
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y +dy[i];
            int nx = x +dx[i];
            if(ny > N || ny<=0 || nx>M || nx<=0) continue;
            if(paper[ny][nx] == 0) {
                paper[ny][nx] = 3;
                dq.push_back({ny,nx});
            }
        }
    }
}

void melting() {
    while(1) {
        if(cheese.size() == 0) break;
        // 1. 외부공기 표시
        time++;
        // 2. 녹는치즈 표시
        for(int i=0; i<cheese.size(); i++) {
            int y = cheese[i].y;
            int x = cheese[i].x;
            int cnt = 0;
            for(int j=0; j<4; j++) {
                if(paper[y+dy[j]][x+dx[j]] == 3) cnt++;
                if(cnt >= 2) {
                    cheese[i].melted = true;
                    break;
                }
            }
        }
        // 3. 녹지않은 치즈만 다시 저장
        vector < option > temp;
        for(int i=0; i<cheese.size(); i++) {
            int y = cheese[i].y;
            int x = cheese[i].x;
            if(cheese[i].melted == false) temp.push_back({y,x,false});
            else {
                paper[y][x] = 3;
                dq.push_back({y,x});
            }
        }
        if(temp.size() == 0) break;
        cheese = temp;
        meltingAir_second();
    }
}

int main()
{
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d",&paper[i][j]);
            if(paper[i][j]) cheese.push_back({i,j,false});
        }
    }
    meltingAir();
    melting();
    printf("%d",time);
}

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;
int N,M,result=987654321;
int safe = 0;
int lab[101][101];
int original_lab[101][101];
int visited[101][101];
int check[10];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
deque < pair <int,int > > vq;
deque < pair < int,int > > activq;

void bfs() {
    // 초기화
    deque < pair < int,int > > dq;
    int viruspoint = 0;
    int time = 0;
    memset(visited,-1,sizeof(visited));
    // 활성바이러스들을 deque에 넣어줌
    for(int i=0; i<activq.size(); i++) {
        int y = activq[i].first;
        int x = activq[i].second;
        dq.push_back(make_pair(y,x));
        visited[y][x] = 0;
    }
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny > N || ny <= 0 || nx > N || nx <= 0) continue;
            if(visited[ny][nx] != -1 || lab[ny][nx] == 1) continue;
            if(lab[ny][nx] == 0) {
                viruspoint++;
                visited[ny][nx] = visited[y][x] + 1;
                time = visited[ny][nx];
                dq.push_back(make_pair(ny,nx));
            }
            else if(lab[ny][nx] == 2) {
                visited[ny][nx] = visited[y][x] + 1;
                dq.push_back(make_pair(ny,nx));
            }
        }
    }
    if(viruspoint == safe) {
        result = min(result,time);
    }
}

void solve(int idx, int cnt) {
    if(cnt == M) {
        bfs();
    }
    for(int i=idx; i<vq.size(); i++) {
        if(check[i]) continue;
        check[i] = 1;
        activq.push_back(make_pair(vq[i].first,vq[i].second));
        solve(i+1,cnt+1);
        check[i] = 0;
        activq.pop_back();
    }
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&lab[i][j]);
            if(lab[i][j] == 2) vq.push_back(make_pair(i,j));
            if(lab[i][j] == 0) safe++;
        }
    }
    solve(0,0);
    printf("%d",result==987654321 ? -1 : result);
}

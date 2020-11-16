#include <iostream>
#include <deque>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int M,N,maxSafe = 0;
int virus[9][9];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
deque < pair < int,int > > virusq;
deque < pair < int,int > > shieldq;

int calculate() {
    int cnt = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(virus[i][j] == 0) cnt++;
        }
    }
    return cnt;
}

void tempArr(int arr[][9]) {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            arr[i][j] = virus[i][j];
        }
    }
}

void returnArr(int arr[][9]) {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            virus[i][j] = arr[i][j];
        }
    }
}

void bfs() {
    deque < pair < int,int > > dq;
    for(int i=0; i<virusq.size(); i++) {
        int y = virusq[i].first;
        int x = virusq[i].second;
        dq.push_back(make_pair(y,x));
    }
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny > N || ny <= 0 || nx > M || nx <= 0) continue;
            if(virus[ny][nx] == 0) {
                dq.push_back(make_pair(ny,nx));
                virus[ny][nx] = 2;
            }
        }
    }
}

void dfs(int cnt) {
    int temp[9][9];
    tempArr(temp);
    if(cnt == 3) {
        bfs();
        int num = calculate();
        maxSafe = (maxSafe <= num) ? num : maxSafe;
        return;
    }
    for(int i=0; i<shieldq.size(); i++) {
        int y = shieldq[i].first;
        int x = shieldq[i].second;
        if(virus[y][x] == 0) {
            virus[y][x] = 1;
            dfs(cnt+1);
            returnArr(temp);
        }
    }
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%1d",&virus[i][j]);
            if(virus[i][j] == 2) {
                virusq.push_back(make_pair(i,j));
            }
            else if(virus[i][j] == 0) {
                shieldq.push_back(make_pair(i,j));
            }
        }
    }
    dfs(0);
    printf("%d",maxSafe);
}

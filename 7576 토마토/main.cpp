#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int M,N, result = -1, allClear = 0, cnt = 0;
int tomato[1001][1001];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
deque < pair <int,int > > dq;

void bfs() {
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int newy = y+dy[i];
            int newx = x+dx[i];
            if(newy > N || newy <= 0 || newx > M || newx <= 0) continue;
            if(tomato[newy][newx] != 0) continue;
            tomato[newy][newx] = tomato[y][x] + 1;
            cnt = tomato[newy][newx] >= cnt ? tomato[newy][newx] : cnt;
            dq.push_back(make_pair(newy,newx));
        }
    }
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++) {
            if(tomato[i][j] == 0)
                allClear = -1;
        }
    }

}

int main() {
    scanf("%d %d",&M, &N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d",&tomato[i][j]);
            if(tomato[i][j] == 1) dq.push_back(make_pair(i,j));
            if(tomato[i][j] == 0) allClear += 1;
        }
    }
    if(allClear == 0) printf("0");
    else {
        bfs();
        (allClear == -1) ? printf("-1") : printf("%d",cnt-1);
    }
}

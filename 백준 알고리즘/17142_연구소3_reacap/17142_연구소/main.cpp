#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <deque>
using namespace std;
int N,M;
int lab[51][51];
int choice[11];
int visited[51][51];
int a = 0;
vector < pair < int,int > > virus;
deque < pair < int,int > > dq;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int result = 987654321;

void solution() {
    memset(visited,-1,sizeof(visited));
    for(int i=0; i<10; i++)
        if(choice[i]) {
            dq.push_back({virus[i].first, virus[i].second});
            visited[virus[i].first][virus[i].second] = 0;
        }
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= N || ny < 0 || nx >= N || nx < 0) continue;
            if(visited[ny][nx] != -1 || lab[ny][nx] == 1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            dq.push_back({ny,nx});
        }
    }

    bool isClear = true;
    int maxTime = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(lab[i][j] == 0) {
                if(visited[i][j] == -1) {
                    isClear = false;
                    break;
                }
                else maxTime = max(maxTime, visited[i][j]);
            }
        }
        if(isClear == false) break;
    }
    if(isClear) result = min(result,maxTime);
}

void selecting(int idx, int cnt) {
    if(cnt == M) solution();
    for(int i=idx; i<virus.size(); i++) {
        if(choice[i] == 0) {
            choice[i] = 1;
            selecting(i+1,cnt+1);
            choice[i] = 0;
        }
    }
}

int main()
{
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d",&lab[i][j]);
            if(lab[i][j] == 2) virus.push_back({i,j});
        }
    }
    selecting(0,0);
    (result == 987654321) ? printf("-1") : printf("%d\n",result);
}

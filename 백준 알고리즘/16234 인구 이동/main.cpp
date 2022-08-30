#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <string.h>
#include <math.h>
using namespace std;
int N,L,R,cnt=0,result=0;
int answer = 0;
int A[51][51];
int visited[51][51];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
deque < pair < int,int > > dq;

void dfs(int y, int x) {
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny > N || ny <= 0 || nx > N || nx <= 0) continue;
        if(visited[ny][nx]) continue;
        int value=(int)abs(A[y][x]-A[ny][nx]);
        if(value >= L && value <= R) {
            visited[ny][nx] = 1;
            dq.push_back(make_pair(ny,nx));
            result += A[ny][nx];
            dfs(ny,nx);
        }
    }
}

int main()
{
    scanf("%d %d %d", &N,&L,&R);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&A[i][j]);
        }
    }
    while(1) {
        memset(visited,0,sizeof(visited));
        cnt = 0;
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N; j++) {
                if(visited[i][j] == 0) {
                    visited[i][j] = 1;
                    dq.clear();
                    dq.push_back(make_pair(i,j));
                    result = A[i][j];
                    dfs(i,j);
                    int dqSize = dq.size();
                    if(dqSize == 1) continue;
                    cnt++;
                    result = result / dqSize;
                    for(int q=0; q<dq.size(); q++) {
                        A[dq[q].first][dq[q].second] = result;
                    }
                }
            }
        }
        if(cnt == 0)
            break;
        answer++;
    }
    printf("%d",answer);
}

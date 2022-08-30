#include <iostream>
#include <stdio.h>
#include <deque>
#include <vector>
#include <string.h>
using namespace std;
int N, maxLife = 1;
int forest[501][501];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int dp[501][501];


int fandaMove(int y, int x) {
    if(dp[y][x])
        return dp[y][x];
    dp[y][x] = 1;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny > N || ny <= 0 || nx > N || nx <= 0) continue;
        if(forest[ny][nx] > forest[y][x]) {
            dp[y][x] = fandaMove(ny,nx) + 1;
        }
    }
    return dp[y][x];
}

int main()
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&forest[i][j]);
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
                maxLife = max(maxLife,fandaMove(i,j));
        }
    }
    printf("%d",maxLife);
}

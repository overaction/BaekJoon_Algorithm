#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int N,M;
int A[501][501];
int visited[501][501];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int result = 0;

void solution(int y, int x, int hap, int cnt) {
    if(cnt == 3) {
        result = (hap >= result) ? hap : result;
        return;
    }
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= N || ny < 0 || nx >= M || nx < 0) continue;
        if(visited[ny][nx]) continue;
        visited[ny][nx] = 1;
        solution(ny,nx,hap+A[ny][nx],cnt+1);
        visited[ny][nx] = 0;
    }
}

// 가운데 블록을 중심으로 ㅗ 모양을 판단
void except(int y, int x) {
    // ㅏ
    if(y-1 >= 0 && y+1 < N && x+1 < M)
        result = max(result,A[y][x]+A[y-1][x]+A[y+1][x]+A[y][x+1]);
    // ㅓ
    if(y-1 >= 0 && y+1 < N && x-1 >= 0)
        result = max(result,A[y][x]+A[y-1][x]+A[y+1][x]+A[y][x-1]);
    // ㅗ
    if(y-1 >= 0 && x-1 >= 0 && x+1 < M)
        result = max(result,A[y][x]+A[y-1][x]+A[y][x-1]+A[y][x+1]);
    // ㅜ
    if(y+1 >= 0 && x-1 >= 0 && x+1 < M)
        result = max(result,A[y][x]+A[y+1][x]+A[y][x-1]+A[y][x+1]);
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            except(i,j);
            visited[i][j] = 1;
            solution(i,j,A[i][j],0);
            visited[i][j] = 0;
        }
    }
    printf("%d\n",result);
}
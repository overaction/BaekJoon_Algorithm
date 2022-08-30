#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define MOD 1000000
using namespace std;

// 방법의 수가 항상 1000000보다 작거나 같으므로 0.1초안에 해결 가능

int N;
int flag = false;
int pipe[16][16];
int cache[16][16];

// 우 대각 아래
int dy[3] = {0,1,1};
int dx[3] = {1,1,0};

int result = 0;

// dir : 0 1 2(가로 대각 세로)
// y,x 위치에 있을 때 끝에 도달 하는 경우의 수 반환
// 0 1 2 빈칸 벽 도착지점
void solution(int y, int x, int dir) {
    if(y == N-1 && x == N-1) {
        result++;
        return;
    }

    // 파이프가 가로일 경우
    if(dir == 0) {
        for(int i=0; i<2; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= N || nx >= N) continue;
            if(pipe[ny][nx] == 1) continue;
            // 대각선으로 갈때 추가적인 체크
            if(i == 1 && (pipe[y+1][x] == 1 || pipe[y][x+1] == 1)) continue;
            solution(ny,nx,i);
        }
    }
    // 파이프가 대각선일 경우
    else if(dir == 1) {
        for(int i=0; i<3; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= N || nx >= N) continue;
            if(pipe[ny][nx] == 1) continue;
            if(i == 1 && (pipe[y+1][x] == 1 || pipe[y][x+1] == 1)) continue;
            solution(ny,nx,i);
        }
    }
    // 파이프가 세로인 경우
    else if(dir == 2) {
        for(int i=1; i<3; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= N || nx >= N) continue;
            if(pipe[ny][nx] == 1) continue;
            if(i == 1 && (pipe[y+1][x] == 1 || pipe[y][x+1] == 1)) continue;
            solution(ny,nx,i);
        }
    }
}

int main()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d",&pipe[i][j]);
        }
    }
    solution(0,1,0);
    printf("%d\n",result);
}

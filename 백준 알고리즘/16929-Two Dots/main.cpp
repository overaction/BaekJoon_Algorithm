#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <deque>
#include <stack>
using namespace std;
int N,M;
int sy,sx;
int game[51][51];
int visited[51][51];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void solution(int y, int x, int cnt) {
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny >= N || ny < 0 || nx >= M || nx < 0) continue;
        if(game[y][x] == game[ny][nx] && !visited[ny][nx]) {
            visited[ny][nx] = 1;
            solution(ny,nx,cnt+1);
            visited[ny][nx] = 0;
        }
        else if(cnt >= 4 && sy == ny && sx == nx) {
            printf("Yes\n");
            exit(0);
        }
    }
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            game[i][j] = s[j]-64;
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            sy = i, sx = j;
            visited[i][j] = 1;
            solution(i,j,1);
        }
    }
    printf("No\n");
}
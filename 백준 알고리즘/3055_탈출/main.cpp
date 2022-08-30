#include <iostream>
#include <stdio.h>
#include <deque>
#include <string.h>
using namespace std;
int R,C;
int sy,sx,ey,ex;
int forest[51][51];
int visited[51][51];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
deque < pair < int,int > > water;
void test() {
    printf("\n");
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            printf("%d ",forest[i][j]);
        }
        printf("\n");
    }
}

int bfs() {
    // initial setting
    deque < pair < int,int > > dq;
    dq.push_back(make_pair(sy,sx));
    visited[sy][sx] = 1;
    while(!dq.empty()) {
        // 먼저 물을 퍼뜨림
        int wSize = water.size();
        for(int w=0; w<wSize; w++) {
            int y = water.front().first;
            int x = water.front().second;
            water.pop_front();
            for(int i=0; i<4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if(ny > R || ny <= 0 || nx > C || nx <= 0) continue;
                if(forest[ny][nx] == 0) {
                    forest[ny][nx] = 1;
                    water.push_back(make_pair(ny,nx));
                }
            }
        }
        int dqSize = dq.size();
        for(int d=0; d<dqSize; d++) {
            int y = dq.front().first;
            int x = dq.front().second;
            dq.pop_front();
            for(int i=0; i<4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                // 범위를 벗어남
                if(ny == ey && nx == ex) {
                    visited[ny][nx] = visited[y][x] + 1;
                    return visited[ny][nx];
                }
                if(ny > R || ny <= 0 || nx > C || nx <= 0) continue;
                // 방문한곳이거나 물 or 돌이 있는곳
                if(visited[ny][nx] || forest[ny][nx] == 1 || forest[ny][nx] == 2) continue;
                visited[ny][nx] = visited[y][x] + 1;
                dq.push_back(make_pair(ny,nx));
            }
        }
    }
    // 고슴도치가 없으면 끝
    return -1;
}

int main()
{
    char str[51];
    scanf("%d %d",&R,&C);
    for(int i=1; i<=R; i++) {
        scanf("%s",str);
        int len = strlen(str);
        for(int j=0; j<len; j++) {
            switch(str[j]) {
                case 'D': // 비버 굴
                    forest[i][j+1] = 3;
                    ey = i, ex = j+1;
                    break;
                case 'S': // 고슴도치 위치
                    forest[i][j+1] = 0;
                    sy = i, sx = j+1;
                    break;
                case '*': // 물
                    forest[i][j+1] = 1;
                    water.push_back(make_pair(i,j+1));
                    break;
                case 'X': // 돌
                    forest[i][j+1] = 2;
                    break;
                case '.':
                    forest[i][j+1] = 0;
                    break;
            }
        }
    }
    int result = bfs();
    if(result == -1)
        printf("KAKTUS");
    else
        printf("%d",result-1);
}

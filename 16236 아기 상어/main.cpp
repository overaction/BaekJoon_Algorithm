#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;

/* 현재 상어 위치를 기준점으로 해서 먹이까지의 최소거리를 탐색한다.
    그 거리는 visited에 담기며 bfs 한번 돌릴 때마다 가장 가까운 먹이 하나씩을 먹는다.
    visited는 bfs를 돌릴때마다 초기화해준다.
    만약 먹이가 없다면 종료한다
*/
int N,sy,sx,big=2,eats=0,flag=false; // flag는 먹이가 있나 없나를 판단한다
int minDist = 999999999, minY = 999999999, minX = 999999999;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int sea[21][21];
int visited[21][21];
int result = 0;
typedef struct options {
    int y,x;
    int dist;
}options;

void initial() {
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            visited[i][j] = 0;
        }
    }
    minDist = 999999999, minY = 999999999, minX = 999999999;
}

void bfs(int nowy, int nowx) {
    deque < pair < int,int > > dq;
    deque < options > fish;
    dq.push_back(make_pair(nowy,nowx));
    visited[nowy][nowx] = 1;
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny > N || ny <=0 || nx > N || nx <= 0) continue;
            if(visited[ny][nx] || sea[ny][nx] > big) continue;
            // 먹이발견
            if(sea[ny][nx] != 0 && sea[ny][nx] < big) {
                visited[ny][nx] = visited[y][x] + 1;
                options now = {ny,nx,visited[ny][nx]};
                fish.push_back(now);
            }
            // 지나갈수있음
            if(sea[ny][nx] == 0 || sea[ny][nx] == big) {
                visited[ny][nx] = visited[y][x] + 1;
                dq.push_back(make_pair(ny,nx));
            }
        }
    }
    if(fish.size() > 0) {
        flag = true;
        int fsize = fish.size();
        for(int i=0; i<fsize; i++) {
            int dist = fish[i].dist;
            int y = fish[i].y;
            int x = fish[i].x;
            if(dist < minDist) {
                minDist = dist;
                minY = y;
                minX = x;
            }
            else if(dist == minDist) {
                if(y < minY) {
                    minY = y;
                    minX = x;
                }
                else if(y == minY) {
                    if(x < minX) {
                        minX = x;
                        minY = y;
                    }
                }
            }
        }
    }
    else {
        flag = false;
    }
}

int main() {
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%1d",&sea[i][j]);
            if(sea[i][j] == 9) {
                sy = i;
                sx = j;
                sea[i][j] = 0;
            }
        }
    }
    while(1) {
        bfs(sy,sx);
        // 먹이가 있음
        if(flag) {
            sy = minY;
            sx = minX;
            eats++;
            if(eats == big) {
                eats = 0;
                big++;
            }
            sea[sy][sx] = 0;
            result += visited[sy][sx] - 1;
        }
        else if(!flag)
            break;
        initial();
    }
    printf("%d",result);
}

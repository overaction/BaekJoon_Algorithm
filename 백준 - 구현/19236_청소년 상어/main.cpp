#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int answer = 0;

typedef struct FISH {
    int y,x,dir,live;
}FISH;

FISH Fish[16];
int Map[5][5];

int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };

void copy_state(int A[][5], int B[][5], FISH C[], FISH D[]) {
    for(int i=1; i<=4; i++) {
        for(int j=1; j<=4; j++) {
            A[i][j] = B[i][j];
        }
    }
    for(int i=1; i<=16; i++) C[i] = D[i];
}

void move_Fish() {
    for(int i=1; i<=16; i++) {
        // 죽은 물고기면 패스
        if(Fish[i].live == false) continue;

        int dir = Fish[i].dir;
        int y = Fish[i].y;
        int x = Fish[i].x;

        int ny = y + dy[dir];
        int nx = x + dx[dir];

        bool flag = false;
        // 범위를 벗어남
        if(ny > 4 || ny <= 0 || nx > 4 || nx <= 0) continue;
        // 만약 빈자리라면
        if(Map[ny][nx] == 0) {
            flag = true;
            Map[ny][nx] = i;
            Map[y][x] = 0;
            Fish[i].y = ny;
            Fish[i].x = nx;
        }
        // 만약 다른물고기가 있다면 자리 바꾸기
        else if(Map[ny][nx] != -1) {
            flag = true;

            swap(Map[y][x], Map[ny][nx]);

            FISH temp = Fish[i];
            int otherDir = Map[ny][nx];
            Fish[i].y = Fish[otherDir].y;
            Fish[i].x = Fish[otherDir].x;
            Fish[otherDir].y = temp.y;
            Fish[otherDir].x = temp.x;
        }

        // 나머지 7방향 탐색
        if(flag == false) {
            int nDir = dir -= 1;
            if(nDir == 0) nDir = 8;
            while(nDir != dir) {
                int ny = y + dy[nDir];
                int nx = x + dx[nDir];
                if(ny <= 4 || ny > 0 || nx <= 4 || nx > 0) {
                    if(Map[ny][nx] == 0) {
                        Fish[i].y = ny;
                        Fish[i].x = nx;
                        Map[ny][nx] = i;
                        Map[y][x] = 0;
                        Fish[i].dir = nDir;
                        break;
                    }
                    else if(Map[ny][nx] != -1) {
                        swap(Map[ny][nx],Map[y][x]);
                        FISH temp = Fish[i];
                        int otherDir = Map[ny][nx];
                        Fish[i].y = Fish[otherDir].y;
                        Fish[i].x = Fish[otherDir].x;
                        Fish[otherDir].y = temp.y;
                        Fish[otherDir].x = temp.x;
                        Fish[i].dir = nDir;
                        break;
                    }
                }
                nDir -= 1;
                if(nDir == 0) nDir = 8;
            }
        }
    }
}

void DFS(int y, int x, int dir, int sum) {
    // 최댓값 저장
    answer = max(answer,sum);
    // 현재 상태 임시 저장
    int copy_Map[5][5];
    FISH copy_Fish[16];
    copy_state(copy_Map,Map,copy_Fish,Fish);
    // 물고기 움직이기
    move_Fish();
    // 상어 움직이기, *최대 3칸밖에 움직일 수 없다
    for(int i=1; i<=3; i++) {
        int ny = y + dy[dir] * i;
        int nx = x + dx[dir] * i;
        // 범위를 벗어나면 break
        if(ny > 4 || ny <= 0 || nx > 4 || nx <= 0) break;
        if(Map[ny][nx] == 0) continue;
        int Fish_num = Map[ny][nx];
        int nDir = Fish[Fish_num].dir;
        // 상어에게 먹힘
        Map[y][x] = 0;
        Map[ny][nx] = -1;
        Fish[Fish_num].live = false;
        // 재귀
        DFS(ny,nx,nDir,sum+Fish_num);
        // 원상복구
        Map[y][x] = -1;
        Map[ny][nx] = 0;
        Fish[Fish_num].live = true;
    }

    copy_state(Map,copy_Map,Fish,copy_Fish);
}

int main() {
    int a,b;
    for(int i=1; i<=4; i++) {
        for(int j=1; j<=4; j++) {
            scanf("%d %d",&a,&b);
            Map[i][j] = a;
            Fish[a] = {i,j,b,true};
        }
    }
    // 상어 초기값
    int firstFish = Map[1][1];
    int firstDir = Fish[firstFish].dir;
    // 첫 물고기 죽음
    Fish[firstFish].live = false;
    // 상어 위치는 -1
    Map[1][1] = -1;
    // 시작
    DFS(1,1,firstDir,firstFish);
    printf("%d\n",answer);
}

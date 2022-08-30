#include <iostream>
#include <iostream>
#include <stdio.h>
#include <deque>
#include <string.h>
#include <algorithm>
using namespace std;
int tomato[101][101][101],cnt=0,init=0;
int N,M,H;
deque < pair < int, pair < int , int > > >dq;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int dh[2] = {-1,1};

void validity() {
    for(int i=1; i<=H; i++)
        for(int j=1; j<=N; j++)
            for(int k=1; k<=M; k++) {
                    if(tomato[i][j][k] == 0) {
                        cnt = -1;
                        return;
                    }
                    cnt = (cnt <= tomato[i][j][k]-1) ? tomato[i][j][k]-1 : cnt;
            }
}

void spreadTomato() {
    while(!dq.empty()) {
        int h = dq.front().first;
        int y = dq.front().second.first;
        int x = dq.front().second.second;
        dq.pop_front();
        for(int j=0; j<4; j++) {
            int ny = y + dy[j];
            int nx = x + dx[j];
            if(ny > N || ny <= 0 || nx > M || nx <= 0) continue;
            if(tomato[h][ny][nx] != 0) continue;
            tomato[h][ny][nx] = tomato[h][y][x] + 1;
            dq.push_back(make_pair(h,make_pair(ny,nx)));
        }
        for(int i=0; i<2; i++) {
            int nh = h + dh[i];
            if(nh > H || nh <= 0) continue;
            if(tomato[nh][y][x] != 0) continue;
            tomato[nh][y][x] = tomato[h][y][x] + 1;
            dq.push_back(make_pair(nh,make_pair(y,x)));
        }
    }
    validity();
}

int main() {
    scanf("%d %d %d",&M,&N,&H);
    for(int i=1; i<=H; i++) {
        for(int j=1; j<=N; j++) {
            for(int k=1; k<=M; k++) {
                scanf("%d",&tomato[i][j][k]);
                if(tomato[i][j][k] == 1)
                    dq.push_back(make_pair(i,make_pair(j,k)));
                else if(tomato[i][j][k] == 0)
                    init++;
            }
        }
    }
    if(init != 0)
        spreadTomato();
    printf("%d",cnt);
}

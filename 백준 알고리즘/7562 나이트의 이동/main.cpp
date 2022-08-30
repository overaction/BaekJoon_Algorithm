#include <iostream>
#include <iostream>
#include <stdio.h>
#include <deque>
#include <string.h>
#include <algorithm>
using namespace std;
int T,I,startx,starty,endx,endy,minimum = 999999999;
int chess[301][301];
int visited[301][301];
int dy[8] = {-2,-1,-2,-1,2,1,2,1};
int dx[8] = {-1,-2,1,2,-1,-2,1,2};

void knight(int Y, int X) {
    if(Y == endy && X == endx) {
        minimum = 0;
        return;
    }
    deque < pair < int,int > > dq;
    dq.push_back(make_pair(Y,X));

    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= I || ny < 0 || nx >= I || nx < 0) continue;
            if(ny == endy && nx == endx) {
                minimum = (minimum >= chess[y][x]) ? chess[y][x] : minimum;
                return;
            }
            if(chess[ny][nx] != 0) continue;
            chess[ny][nx] = chess[y][x] + 1;
            dq.push_back(make_pair(ny,nx));
        }
    }
}


int main() {
    scanf("%d",&T);
    for(int t=0; t<T; t++) {
        scanf("%d",&I);
        scanf("%d %d",&startx,&starty);
        chess[starty][startx] = 1; // 현재 위치
        scanf("%d %d",&endx,&endy);

        knight(starty,startx);

        printf("%d\n",minimum);
        minimum = 9999999999; // 초기화
        memset(chess,0,sizeof(chess));
    }
}

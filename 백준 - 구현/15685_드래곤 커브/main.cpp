#include <iostream>
#include <stdio.h>
#include <deque>
using namespace std;
int N,cnt=0;
int dragon[101][101];
int dy[4] = {0,-1,0,1};
int dx[4] = {1,0,-1,0};
void makedragon(int sx, int sy, int sd, int sg) {
    deque < int > dq;
    int y = sy;
    int x = sx;
    int dir = sd;
    dragon[y][x] = 1;
    y += dy[dir];
    x += dx[dir];
    dragon[y][x] = 1;
    dq.push_back(sd);
    // 1세대부터 sg세대까지
    for(int i=1; i<=sg; i++) {
        // 역순
        int dqsize = dq.size();
        for(int j=dqsize-1; j>=0; j--) {
            dir = (dq[j] + 1)%4;
            dq.push_back(dir);
            y += dy[dir];
            x += dx[dir];
            dragon[y][x] = 1;
        }
    }
}

void solution() {
    for(int i=0; i<100; i++) {
        for(int j=0; j<100; j++) {
            if(dragon[i][j] && dragon[i+1][j] && dragon[i][j+1] && dragon[i+1][j+1])
                cnt++;
        }
    }
}

int main()
{
    int x,y,d,g;
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        scanf("%d %d %d %d",&x,&y,&d,&g);
        makedragon(x,y,d,g);
    }
    solution();
    printf("%d",cnt);
}

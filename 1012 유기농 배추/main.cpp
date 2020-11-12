#include <iostream>
#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;
int v[51][51];
int visited[51][51];
int dy[4] = {-1,1,0,0};

int dx[4] = {0,0,-1,1};
int T,M,N,K,X,Y,cnt=0;
deque < pair < int,int > > vq;
void bfs(int y, int x) {
    visited[y][x] = 1;
    deque < pair < int,int > > wq;
    wq.push_back(make_pair(y,x));
    while(!wq.empty()) {
        int y = wq.front().first;
        int x = wq.front().second;
        wq.pop_front();
        for(int i=0; i<4; i++) {
            int newy = dy[i] + y;
            int newx = dx[i] + x;
            if(newy >= N || newy < 0 || newx >= M || newx < 0) continue;
            if(visited[newy][newx] == 1 || v[newy][newx] == 0) continue;
            visited[newy][newx] = 1;
            wq.push_back(make_pair(newy,newx));
        }
    }
}

int main()
{
    scanf("%d",&T);
    for(int i=1; i<=T; i++) {
        scanf("%d %d %d",&M,&N,&K);
        for(int j=1; j<=K; j++) {
            scanf("%d %d",&X,&Y);
            v[Y][X] = 1;
            vq.push_back(make_pair(Y,X));
        }
        int vqSize = vq.size();
        for(int k=0; k<vqSize; k++) {
            int y = vq.front().first;
            int x = vq.front().second;
            vq.pop_front();
            if(!visited[y][x]) {
                bfs(y,x);
                cnt++;
            }
        }
        printf("%d\n",cnt);

        cnt = 0;
        memset(visited,0,sizeof(visited));
        memset(v,0,sizeof(v));
    }
}

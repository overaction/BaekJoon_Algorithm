#include <iostream>
#include <stdio.h>
#include <deque>
#include <string.h>
#include <algorithm>
using namespace std;
int land[51][51];
int dy[8] = {-1,1,0,0,-1,1,-1,1};
int dx[8] = {0,0,-1,1,-1,1,1,-1};
int w,h;

void dfs(int y, int x) {
    land[y][x] = 2;
    for(int i=0; i<8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny > h || ny <= 0 ||nx > w || nx <= 0) continue;
        if(land[ny][nx] == 1) {
            land[ny][nx] = 2;
            dfs(ny,nx);
        }
    }
}

int main()
{
    while(1) {
        int cnt = 0;
        deque < pair < int,int > > landq;
        scanf("%d %d",&w,&h);
        if(w == 0 && h == 0)
            return 0;
        for(int i=1; i<=h; i++) {
            for(int j=1; j<=w; j++) {
                scanf("%1d",&land[i][j]);
                if(land[i][j]) landq.push_back(make_pair(i,j));
            }
        }
        for(int i=0; i<landq.size(); i++) {
            int y = landq[i].first;
            int x = landq[i].second;
            if(land[y][x] == 1) {
                dfs(y,x);
                cnt++;
            }
        }
        printf("%d\n",cnt);
    }
}

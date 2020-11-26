#include <iostream>
#include <stdio.h>
#include <deque>
#include <vector>
#include <string.h>
using namespace std;
int L,W;
int N,M;
int maximum = 0;
int island[51][51];
int visited[51][51];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
deque < pair <int,int > > m;

void treasure(int sy, int sx) {
    // sy,sx로부터의 최단거리 저장
    deque < pair < int,int > > dq;
    dq.push_back(make_pair(sy,sx));
    visited[sy][sx] = 1;
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y +dy[i];
            int nx = x + dx[i];
            if(ny > N || ny <= 0 || nx > M || nx <= 0) continue;
            if(visited[ny][nx] || island[ny][nx] == 0) continue;
            visited[ny][nx] = visited[y][x] + 1;
            maximum = (maximum <= visited[ny][nx]) ? visited[ny][nx] : maximum;
            dq.push_back(make_pair(ny,nx));
        }
    }

}

int main()
{
    scanf("%d %d",&N,&M);
    char str[51];
    for(int i=1; i<=N; i++) {
        scanf("%s",&str);
        for(int j=0; j<M; j++) {
            if(str[j] == 'W') {
                island[i][j+1] = 0;
            }
            else {
                island[i][j+1] = 1;
                m.push_back(make_pair(i,j+1));
            }
        }
    }
    int msize = m.size();
    for(int i=0; i<msize; i++) {
        int y = m[i].first;
        int x = m[i].second;
        treasure(y,x);
        memset(visited,0,sizeof(visited));
    }
    printf("%d",maximum-1);
}

#include <iostream>
#include <stdio.h>
#include <deque>
#include <string.h>
using namespace std;
int N,result=99999999;
int islandNo = 1;
int island[101][101];
int visited[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
deque < pair < int,int > > dq;

void seperate(int sy, int sx) {
    visited[sy][sx] = 1;
    island[sy][sx] = islandNo;
    deque < pair < int,int > > tp;
    tp.push_back(make_pair(sy,sx));
    while(!tp.empty()) {
        int y = tp.front().first;
        int x = tp.front().second;
        tp.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny>N || ny<=0 || nx>N || nx<=0) continue;
            if(visited[ny][nx]) continue;
            if(island[ny][nx] == 0) continue;
            tp.push_back(make_pair(ny,nx));
            visited[ny][nx] = 1;
            island[ny][nx] = islandNo;
        }
    }
}

void bfs(int sy, int sx, int islandN) {
    visited[sy][sx] = 1;
    deque < pair < int,int > > s;
    s.push_back(make_pair(sy,sx));
    while(!s.empty()) {
        int y = s.front().first;
        int x = s.front().second;
        s.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny>N || ny<=0 || nx>N || nx<=0) continue;
            if(visited[ny][nx]) continue;
            if(island[ny][nx] == islandN) continue;
            if(island[ny][nx] != 0 && island[ny][nx] != islandN) {
                visited[ny][nx] = visited[y][x] + 1;
                result = min(result,visited[ny][nx]-2);
                continue;
            }
            if(island[ny][nx] == 0) {
                visited[ny][nx] = visited[y][x] + 1;
                s.push_back(make_pair(ny,nx));
            }
        }
    }
}

int main() {
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&island[i][j]);
            if(island[i][j]) dq.push_back(make_pair(i,j));
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(visited[i][j] || island[i][j] == 0) continue;
            seperate(i,j);
            islandNo++;
        }
    }
    memset(visited,0,sizeof(visited));
    int dqSize = dq.size();
    for(int i=0; i<dqSize; i++) {
        int y = dq[i].first;
        int x = dq[i].second;
        int islandNo = island[y][x];
        bfs(y,x,islandNo);
        memset(visited,0,sizeof(visited));
    }
    printf("%d",result);
}

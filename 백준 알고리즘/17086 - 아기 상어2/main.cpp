#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int dy[8] = {-1,1,0,0,-1,1,-1,1};
int dx[8] = {0,0,-1,1,-1,1,1,-1};
int square[51][51];
int visited[51][51];
int N,M;
vector < pair < int,int > > v;
int answer = 0;

typedef struct option {
    int y,x,depth;
}op;

void clear() {
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            visited[i][j] = 0;
}

void solution(int sy, int sx) {
    queue < op > q;
    q.push({sy,sx,0});
    visited[sy][sx] = 1;

    while(!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int depth = q.front().depth;
        q.pop();

        if(square[y][x] == 1) {
            answer = (answer < depth) ? depth : answer;
            break;
        }

        for(int i=0; i<8; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny >= N || ny < 0 || nx >= M || nx < 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            q.push({ny,nx,depth+1});
        }
    }
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%d",&square[i][j]);
            if(square[i][j] == 0) v.push_back({i,j});
        }
    }
    for(int i=0; i<v.size(); i++) {
        int y = v[i].first;
        int x = v[i].second;
        solution(y,x);
        clear();
    }
    printf("%d\n",answer);
}
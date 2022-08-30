#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int N,M;
int miro[101][101];
int visited[101][101];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int solution() {
    visited[0][0] = 1;
    queue < pair < int,int > > q;
    q.push({0,0});
    while(!q.empty()) {
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int newy = nowy + dy[i];
            int newx = nowx + dx[i];
            if(newy >= N || newy < 0 || newx >= M || newx < 0) continue;
            if(visited[newy][newx] || miro[newy][newx] == 0) continue;
            miro[newy][newx] += miro[nowy][nowx];
            visited[newy][newx] = 1;
            q.push({newy,newx});
        }
    }
    return miro[N-1][M-1];
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            scanf("%1d",&miro[i][j]);
        }
    }
    printf("%d\n",solution());
}
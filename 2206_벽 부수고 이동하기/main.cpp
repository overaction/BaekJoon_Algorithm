#include <iostream>
#include <iostream>
#include <stdio.h>
#include <deque>
#include <string.h>
#include <algorithm>
using namespace std;
int N,M,case1=0,case2=0;
int Map[1001][1001];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int visited[1001][1001][2];

int bfs() {
    deque < pair < pair < int,int >, int > > dq;
    dq.push_back(make_pair(make_pair(1,1),1));
    visited[1][1][1] = 1;
    while(!dq.empty()) {
        int y = dq.front().first.first;
        int x = dq.front().first.second;
        int wall = dq.front().second;
        dq.pop_front();
        if(y == N && x == M) return visited[y][x][wall];

        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny > N || ny <= 0 || nx > M || nx <= 0) continue;
            // ���̰� ���� �� �� �ִٸ�
            if(Map[ny][nx] == 1 && wall) {
                visited[ny][nx][0] = visited[y][x][1] + 1;
                dq.push_back(make_pair(make_pair(ny,nx),0));
                case1+=1;
            }
            else if(Map[ny][nx] == 0 && visited[ny][nx][wall] == 0) {
                visited[ny][nx][wall] = visited[y][x][wall] + 1;
                dq.push_back(make_pair(make_pair(ny,nx),wall));
                case2+=1;
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &N,&M);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%1d",&Map[i][j]);
        }
    }
    printf("%d\n",bfs());
    printf("%d\n%d\n",case1,case2);
}

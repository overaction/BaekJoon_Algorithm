#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>

#define INF 98765432
using namespace std;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int N,M,islandNumber=1;
int island[11][11];
int islandNum[11][11];

vector < pair < int,int > > V;
bool visited[11][11];

vector < pair < int,int > > Vnum[7];

typedef struct option {
    int a,b,dist;
}op;
vector < option > Bridge;
int Dist[7][7];
int selected[49];

int connect[7][7];
int connectedisland[7];

int answer = INF;

void bfs(int sy, int sx, int num) {
    deque < pair < int,int > > dq;
    dq.push_back({sy,sx});
    visited[sy][sx] = true;
    Vnum[num].push_back({sy,sx});
    islandNum[sy][sx] = num;
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny > N || ny <= 0 || nx > M || nx <= 0) continue;
            if(island[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            Vnum[num].push_back({ny,nx});
            visited[ny][nx] = true;
            islandNum[ny][nx] = num;
            dq.push_back({ny,nx});
        }
    }
}

void numbering() {
    for(int i=0; i<V.size(); i++) {
        int y = V[i].first;
        int x = V[i].second;
        if(visited[y][x] == 0) bfs(y,x,islandNumber++);
    }
}

void DFS(int a, int b, int y, int x, int dist, int cur) {
    int ny = y + dy[cur];
    int nx = x + dx[cur];
    if(ny > N || ny <= 0 || nx > M || nx <= 0) return;
    if(island[ny][nx] == 0) DFS(a,b,ny,nx,dist+1,cur);
    else if(island[ny][nx] != 0) {
        if(islandNum[ny][nx] == b) {
            if(Dist[a][b] > dist && dist >= 2) {
                Dist[a][b] = dist;
                Dist[b][a] = dist;
            }
        }
        return;
    }
}

void makeBridge(int a, int b) {
    for(int i=0; i<Vnum[a].size(); i++) {
        int y = Vnum[a][i].first;
        int x = Vnum[a][i].second;
        for(int j=0; j<4; j++) {
            int ny = y + dy[j];
            int nx = x + dx[j];
            if(ny > N || ny <= 0 || nx > M || nx <= 0) continue;
            if(island[ny][nx] != 0) continue;
            DFS(a,b,ny,nx,1,j);
        }
    }
}

void findDistance() {
    for(int i=1; i<islandNumber; i++) {
        for(int j=i+1; j<islandNumber; j++) {
            makeBridge(i,j);
            if(Dist[i][j] != INF) {
                Bridge.push_back({i,j,Dist[i][j]});
            }
        }
    }
}

bool verify() {
    memset(connect,0,sizeof(connect));
    memset(connectedisland,0,sizeof(connectedisland));
    for(int i=0; i<Bridge.size(); i++) {
        if(selected[i]) {
            int a = Bridge[i].a;
            int b = Bridge[i].b;
            connect[a][b] = 1;
            connect[b][a] = 1;
        }
    }
    deque < int > dq;
    dq.push_back(1);
    connectedisland[1] = 1;
    bool flag = false;
    int islandCounts = 1;
    while(!dq.empty()) {
        int now = dq.front();
        dq.pop_front();
        if(islandCounts == islandNumber-1) {
            flag = true;
            break;
        }
        for(int i=1; i<islandNumber; i++) {
            if(now == i) continue;
            if(connect[now][i] && !connectedisland[i]) {
                connectedisland[i] = true;
                dq.push_back(i);
                islandCounts++;
            }
        }
    }
    return flag;
}

void answering(int cnt, int idx, int sum) {
    if(cnt >= 1) {
        if(verify()) {
            if(answer > sum)
                answer = sum;
        }
    }
    for(int i=idx; i<Bridge.size(); i++) {
        if(selected[i] == false) {
            selected[i] = true;
            answering(cnt+1,i,sum+Bridge[i].dist);
            selected[i] = false;
        }
    }
}

int main() {
    for(int i=1; i<7; i++) {
        for(int j=1; j<7; j++) {
            Dist[i][j] = INF;
        }
    }
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d",&island[i][j]);
            if(island[i][j]) V.push_back({i,j});
        }
    }

    // 섬에 번호 매기기
    numbering();
    // 다리 만들기
    findDistance();
    // 최단거리 찾기
    answering(0,0,0);

    if(answer == INF) printf("-1");
    else printf("%d",answer);
}

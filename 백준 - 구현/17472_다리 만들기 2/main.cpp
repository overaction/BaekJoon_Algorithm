#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 98765432
int N,M,islandNums=1,answer=INF;

int island[11][11]; // 섬,바다
int islandNum[11][11]; // 각 섬의 번호

int Dist[7][7]; // 각각의 섬 마다의 거리 ( Dist[a][b] = c : a 섬과  b 섬의 거리는 C )
bool visited[11][11];
bool selected[49];

bool connect[7][7];
bool connectIsland[7];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
vector < pair <int,int > > V; // 모든 섬
vector < pair <int,int > > Vnum[11]; // 각각의 섬

typedef struct op {
    int a,b;
    int dist;
}op;

vector < op > Bridge;  // 섬 사이의 거리 저장

void BFS(int sy, int sx, int islandNumber) {
    deque < pair < int,int > > dq;
    dq.push_back(make_pair(sy,sx));
    islandNum[sy][sx] = islandNumber;
    Vnum[islandNumber].push_back({make_pair(sy,sx)});
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny > N || ny <= 0 || nx > M || nx <= 0 || island[ny][nx] == 0) continue;
            if(visited[ny][nx]) continue;
            visited[ny][nx] = true;
            islandNum[ny][nx] = islandNumber;
            Vnum[islandNumber].push_back({make_pair(ny,nx)});
            dq.push_back(make_pair(ny,nx));
        }
    }
}

void numbering() {
    for(int i=0; i<V.size(); i++) {
        int y = V[i].first;
        int x = V[i].second;
        if(visited[y][x] == false) BFS(y,x,islandNums++);
    }
}

void DFS(int sy, int sx, int cur, int dist, int a, int b) {
    int ny = sy+dy[cur];
    int nx = sx+dx[cur];
    if(ny > N || ny <= 0 || nx > M || nx <= 0) return; // 범위 벗어남
    if(island[ny][nx] == 0) DFS(ny,nx,cur,dist+1,a,b); // 바다라면 계속 탐색
    else if(island[ny][nx] == 1) { // 땅이라면 ?
        if(islandNum[ny][nx] == b) { // 원하던 섬에 도착
            if(dist > 1 && dist < Dist[a][b]) { // 거리가 1 이상이고 거리가 더 짧다면
                Dist[a][b] = dist;
                Dist[b][a] = dist;
            }
        }
    }
    return;
}

void makeBridge(int a, int b) {
    for(int i=0; i<Vnum[a].size(); i++) {
        int y = Vnum[a][i].first;
        int x = Vnum[a][i].second;
        // 4방향
        for(int j=0; j<4; j++) {
            int ny = y + dy[j];
            int nx = x + dx[j];
            if(ny > N || ny <= 0 || nx > M || nx <= 0) continue;
            if(island[ny][nx] == 0) DFS(y,x,j,0,a,b);
        }
    }
}

void findDisatnce() {
    for(int i=1; i<7; i++) {
        for(int j=i+1; j<7; j++) {
            makeBridge(i,j);
            if(Dist[i][j] == INF) continue;
            Bridge.push_back({i,j,Dist[i][j]});
        }
    }
}

bool verify() {
    memset(connect,false,sizeof(connect));
    memset(connectIsland,false,sizeof(connectIsland));
    for(int i=0; i<Bridge.size(); i++) {
        if(selected[i]) {
            int a = Bridge[i].a;
            int b = Bridge[i].b;
            connect[a][b] = true;
            connect[b][a] = true;
        }
    }
    //1번 섬에서부터 시작
    deque < int > dq;
    dq.push_back(1);
    connectIsland[1] = true;

    int islandCount = 1;
    bool flag = false;
    while(!dq.empty()) {
        int now = dq.front();
        dq.pop_front();
        if(islandCount == islandNums - 1) {
            flag = true;
            break;
        }
        for(int i=1; i<islandNums; i++) {
            if(now == i) continue;
            if(connect[now][i] && connectIsland[i] == false) {
                connectIsland[i] = true;
                dq.push_back(i);
                islandCount++;
            }
        }
    }
    return flag;
}

void DistDFS(int idx, int cnt, int sum) {
    if(cnt >= 1) {
        if(verify()) {
            if(answer > sum) {
                answer = sum;
            }
        }
    }
    for(int i=idx; i<Bridge.size(); i++) {
        if(selected[i]) continue;
        selected[i] = true;
        DistDFS(i,cnt+1,sum+Bridge[i].dist);
        selected[i] = false;
    }
}

int main() {
    scanf("%d %d",&N,&M);
    // 거리는 처음에 다 INF로 초기화
    for(int i=1; i<7; i++) {
        for(int j=1; j<7; j++) {
            Dist[i][j] = INF;
        }
    }
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%d",&island[i][j]);
            if(island[i][j]) V.push_back(make_pair(i,j));
        }
    }
    // 1. 섬에 번호 매기기
    numbering();
    // 2. 각 섬간의 최단거리를 찾아서 다리를 만들기
    findDisatnce();
    // 3. 모든 경우의 수 탐색
    DistDFS(0,0,0);

    if(answer == INF) printf("-1");
    else printf("%d",answer);
}

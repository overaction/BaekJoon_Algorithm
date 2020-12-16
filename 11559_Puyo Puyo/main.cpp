#include <iostream>
#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;
int N=12,M=6,cnt=0,point=0;
int puyo[13][7];
int visited[13][7];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
deque < pair <int,int > > pq;
deque < pair < int,int > > after;

void bfs(int sy, int sx) {
    deque < pair < int,int > > dq;
    deque < pair < int,int > > bomb;
    visited[sy][sx] = 1;
    int cnt = 1;
    bomb.push_back(make_pair(sy,sx));
    dq.push_back(make_pair(sy,sx));
    while(!dq.empty()) {
        int y = dq.front().first;
        int x = dq.front().second;
        int color = puyo[y][x];
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny > N || ny <= 0 || nx > M || nx <= 0) continue;
            if(visited[ny][nx]) continue;
            if(color == puyo[ny][nx]) {
                visited[ny][nx] = 1;
                cnt++;
                dq.push_back(make_pair(ny,nx));
                bomb.push_back(make_pair(ny,nx));
            }
        }
    }
    if(cnt >= 4) {
        int bombsize = bomb.size();
        for(int i=0; i<bombsize; i++) {
            int y = bomb.front().first;
            int x = bomb.front().second;
            bomb.pop_front();
            after.push_back(make_pair(y,x));
            puyo[y][x] = 0;
        }
    }
}



int main() {
    string s;
    for(int i=1; i<=N; i++) {
        cin >> s;
        for(int j=0; j<M; j++) {
            switch(s.at(j)) {
            case '.':
                puyo[i][j+1] = 0;
                break;
            case 'R':
                puyo[i][j+1] = 1;
                pq.push_back(make_pair(i,j+1));
                break;
            case 'G':
                puyo[i][j+1] = 2;
                pq.push_back(make_pair(i,j+1));
                break;
            case 'B':
                puyo[i][j+1] = 3;
                pq.push_back(make_pair(i,j+1));
                break;
            case 'P':
                puyo[i][j+1] = 4;
                pq.push_back(make_pair(i,j+1));
                break;
            case 'Y':
                puyo[i][j+1] = 5;
                pq.push_back(make_pair(i,j+1));
                break;
            }
        }
    }
    while(1) {
        // 없앨 puyo 검색후 없앰
        int qsize = pq.size();
        for(int i=0; i<qsize; i++) {
            int y = pq.front().first;
            int x = pq.front().second;
            pq.pop_front();
            if(visited[y][x] == 0)
                bfs(y,x);
        }
        int afterSize = after.size();
        // 터진 뿌요가 한뭉치도 없으면 종료
        if(afterSize == 0) {
            printf("%d",point);
            break;
        }
        // 터진 뿌요가 있으면 재배치
        for(int i=0; i<afterSize; i++) {
            int y = after.front().first;
            int x = after.front().second;
            after.pop_front();
            for(int j=y-1; j>=1; j--) {
                // 위 칸에 뿌요가 있으면 체인지
                if(puyo[j][x]) {
                    puyo[j+1][x] = puyo[j][x];
                    puyo[j][x] = 0;
                }
            }
        }
        // 바뀐 뿌요 위치를 다시 deque에 넣기
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(puyo[i][j]) pq.push_back(make_pair(i,j));
            }
        }
        memset(visited,0,sizeof(visited));
        point++;
    }
}

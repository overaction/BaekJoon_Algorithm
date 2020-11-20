#include<iostream>
#include<queue>
#include<deque>
#include<algorithm>
#include<string.h>
#define INF 1e9
using namespace std;
typedef struct options {
    int depth;
    int ry,rx,by,bx;
}options;
int N,M;
int srx,sry,sbx,sby,ex,ey;
int board[11][11];
int visited[11][11][11][11];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

int bfs() {
    deque < options > dq;
    options op = {0,sry,srx,sby,sbx};
    dq.push_back(op);
    visited[sry][srx][sby][sbx] = 1;
    while(!dq.empty()) {
        options now = dq.front();
        dq.pop_front();
        if(now.depth > 10) return -1;
        if(now.ry == ey && now.rx == ex) return now.depth;
        for(int i=0; i<4; i++) {
            int by = now.by, bx = now.bx, ry = now.ry, rx = now.rx;
            int redcnt = 0, bluecnt = 0;
            // 빨간공 이동
            while(1) {
                ry = ry + dy[i];
                rx = rx + dx[i];
                redcnt++;
                if(board[ry][rx] == 2) break;
                if(board[ry][rx] == 1) {
                    ry = ry - dy[i];
                    rx = rx - dx[i];
                    break;
                }
            }
            // 파란공 이동
            while(1) {
                by += dy[i];
                bx += dx[i];
                bluecnt++;
                if(board[by][bx] == 2) break;
                if(board[by][bx] == 1) {
                    by -= dy[i];
                    bx -= dx[i];
                    break;
                }
            }
            // 두 공이 동시에 골인하면
            if(ry == ey && rx == ex && by == ey && bx == ex) continue;
            // 두 공이 겹치면
            if(ry == by && rx == bx) {
                // 파란공이 뒤에 있었음
                if(bluecnt > redcnt) {
                    by -= dy[i];
                    bx -= dx[i];
                }
                else if(bluecnt < redcnt) {
                    ry -= dy[i];
                    rx -= dx[i];
                }
            }
            // 파란공이 골인함
            if(by == ey && bx == ex) {
                continue;
            }
            if(visited[ry][rx][by][bx] == 0) {
                visited[ry][rx][by][bx] = 1;
                options next = {now.depth+1,ry,rx,by,bx};
                dq.push_back(next);
            }
        }
    }
    return -1;
}

int main() {
    string s;
    scanf("%d %d",&N,&M);
    for(int i=1; i<=N; i++) {
        cin >> s;
        for(int j=0; j<M; j++) {
            switch(s.at(j)) {
            case '#':
                board[i][j+1] = 1;
                break;
            case '.':
                board[i][j+1] = 0;
                break;
            case 'R':
                sry = i;
                srx = j+1;
                break;
            case 'B':
                sby = i;
                sbx = j+1;
                break;
            case 'O':
                ey = i;
                ex = j+1;
                board[i][j+1] = 2;
                break;
            }
        }
    }
    printf("%d\n",bfs());
}

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
int white = 0;
int black = 0;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int war[101][101];
int visited[101][101];

void solution(int y, int x, int color) {
    visited[y][x] = 1;
    queue < pair < int, int > > q;
    q.push({y,x});
    int cnt = 1;
    while(!q.empty()) {
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int newy = nowy + dy[i];
            int newx = nowx + dx[i];
            if(newy >= M || newy < 0 || newx >= N || newx < 0) continue;
            if(color != war[newy][newx] || visited[newy][newx]) continue;
            visited[newy][newx] = 1;
            cnt++;
            q.push({newy,newx});
        }
    }
    if(color == 0) white += (cnt*cnt);
    else black += (cnt*cnt);
}

int main() {
    string s;
    scanf("%d %d",&N,&M);

    for(int i=0; i<M; i++) {
        cin >> s;
        for(int j=0; j<N; j++) {
            if(s[j] == 'B') war[i][j] = 1;
            else war[i][j] = 0; 
        }
    }
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(visited[i][j]) continue;
            solution(i,j,war[i][j]);
        }
    }
    printf("%d %d\n",white,black);
}
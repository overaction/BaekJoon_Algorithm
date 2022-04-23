#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int condo[101][101];
int visited[101][101];
int N,M,K;
int answer = 0;

void solution(int y, int x) {
    visited[y][x] = 1;
    queue < pair < int,int > > q;
    int biggest = 1;
    q.push({y,x});
    while(!q.empty()) {
        int nowy = q.front().first;
        int nowx = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int newy = nowy + dy[i];
            int newx = nowx + dx[i];
            if(newy > N || newy <= 0 || newx > M || newx <= 0) continue;
            if(visited[newy][newx] || condo[newy][newx] == 0) continue;
            visited[newy][newx] = 1;
            q.push({newy,newx});
            biggest++;
        }
    }
    answer = (answer >= biggest) ? answer : biggest;
}

int main() {
    int a,b;
    scanf("%d %d %d",&N,&M,&K);
    for(int i=0; i<K; i++) {
        scanf("%d %d",&a,&b);
        condo[a][b] = 1;
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(condo[i][j] == 1 && visited[i][j] == 0) solution(i,j);
        }
    }
    printf("%d\n",answer);
}
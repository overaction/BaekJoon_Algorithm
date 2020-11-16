#include <iostream>
#include <deque>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int M,N,maxSafe = 0;
int virus[9][9];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
deque < pair < int,int > > virusq;
deque < pair < int,int > > shieldq;

void spreadVirus(int y, int x) {
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny > N || ny <= 0 ||nx > M || nx <= 0) continue;
        if(virus[ny][nx] == 0) {
            virus[ny][nx] = 2;
            spreadVirus(ny,nx);
        }
    }
}

void calculate() {
    int num = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(virus[i][j] == 0) num++;
        }
    }
    maxSafe = (maxSafe <= num) ? num : maxSafe;
}

int main() {
    int virus_origin[9][9];
    scanf("%d %d",&N,&M);
    // 바이러스,안전지역 따로 저장
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            scanf("%1d",&virus[i][j]);
            if(virus[i][j] == 2) {
                virusq.push_back(make_pair(i,j));
            }
            else if(virus[i][j] == 0) {
                shieldq.push_back(make_pair(i,j));
            }
        }
    }
    // 원본 저장
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            virus_origin[i][j] = virus[i][j];

    // 임의의 3개 지역에 벽 세우기
    int sqSize = shieldq.size();
    for(int i=0; i<sqSize; i++)
        for(int j=i+1; j<sqSize; j++)
            for(int k=j+1; k<sqSize; k++) {
                virus[shieldq[i].first][shieldq[i].second] = 1;
                virus[shieldq[j].first][shieldq[j].second] = 1;
                virus[shieldq[k].first][shieldq[k].second] = 1;

                // 바이러스 퍼뜨리기
                for(int v=0; v<virusq.size(); v++) {
                    spreadVirus(virusq[v].first,virusq[v].second);
                }
                // 안전지역 계산
                calculate();
                // 원본 복구
                for(int i=1; i<=N; i++)
                    for(int j=1; j<=M; j++)
                        virus[i][j] = virus_origin[i][j];
            }

    printf("%d",maxSafe);
}

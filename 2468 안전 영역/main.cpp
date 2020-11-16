#include <iostream>
#include <iostream>
#include <stdio.h>
#include <deque>
#include <string.h>
#include <algorithm>
using namespace std;
int N,safes=0,highest=0;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int rain[101][101];

void safeZone(int height) {
    int cnt = 0;
    deque < pair < int,int > > dq;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            if(rain[i][j] <= height)
                rain[i][j] = 0; // 물에 잠김
            else dq.push_back(make_pair(i,j)); // 안전지역
        }
    }
    int dqSize = dq.size();
    for(int i=0; i<dqSize; i++) {
        if(rain[dq[i].first][dq[i].second] != 0) {
            cnt++;
            deque < pair < int,int > > dq2;
            dq2.push_back(make_pair(dq[i].first,dq[i].second));
            while(!dq2.empty()) {
                int y = dq2.front().first;
                int x = dq2.front().second;
                dq2.pop_front();
                rain[y][x] = 0;
                for(int i=0; i<4; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if(ny > N || ny <= 0 || nx > N || nx <= 0) continue;
                    if(rain[ny][nx] != 0) {
                        rain[ny][nx] = 0;
                        dq2.push_back(make_pair(ny,nx));
                    }
                }
            }
        }
    }
    safes = (safes <= cnt) ? cnt : safes;
}

int main()
{
    int origin[101][101];
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            scanf("%d",&rain[i][j]);
            origin[i][j] = rain[i][j];
            highest = (highest <= rain[i][j]) ? rain[i][j] : highest;
        }
    }
    for(int i=0; i<highest; i++) {
        safeZone(i);
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                rain[i][j] = origin[i][j];
    }
    printf("%d",safes);
}

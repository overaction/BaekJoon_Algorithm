#include <iostream>
#include <stdio.h>
#include <deque>
#include <string>
using namespace std;
int R,C,T;
int ms[51][51];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
deque < pair < int,int > > clean;

void spread() {
    int backup[51][51] = {0,};
    int cnt = 0;
    int next = 0;
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(ms[i][j] <= 0) continue;
            next = ms[i][j] / 5;
            for(int k=0; k<4; k++) {
                int ny = i + dy[k];
                int nx = j + dx[k];
                if(ny > R || ny <= 0 || nx > C || nx <= 0) continue;
                if(ms[ny][nx] == -1) continue;
                backup[ny][nx] = backup[ny][nx] + next;
                cnt++;
            }
            backup[i][j] = backup[i][j] - (next*cnt);
            cnt = 0;
        }
    }
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            ms[i][j] += backup[i][j];
        }
    }
}

void cleaner() {
    int cleany = clean[0].first;
    int cleanx = clean[0].second;
    // À­ºÎºÐ
    // y = 2,3
    for(int j=cleany; j>1; j--) {
        ms[j][cleanx] = ms[j-1][cleanx];
    }
    ms[cleany][cleanx] = 0;
    //x = 1 ~ 7
    for(int i=cleanx; i<C; i++) {
        ms[1][i] = ms[1][i+1];
    }
    // y == 1,2
    for(int j=1; j<cleany; j++) {
        ms[j][C] = ms[j+1][C];
    }
    ms[cleany][cleanx] = 0;
    for(int i=C; i>1; i--) {
        ms[cleany][i] = ms[cleany][i-1];
    }

    //¾Æ·§ºÎºÐ
    cleany = clean[1].first;
    cleanx = clean[1].second;
    for(int j=cleany; j<R; j++) {
        ms[j][cleanx] = ms[j+1][cleanx];
    }
    ms[cleany][cleanx] = 0;
    for(int i=cleanx; i<C; i++) {
        ms[R][i] = ms[R][i+1];
    }
    for(int j=R; j>cleany; j--) {
        ms[j][C] = ms[j-1][C];
    }
    for(int i=C; i>cleanx; i--) {
        ms[cleany][i] = ms[cleany][i-1];
    }
    ms[cleany][cleanx] = 0;

    for(int i=0; i<clean.size(); i++) {
        ms[clean[i].first][clean[i].second] = -1;
    }
}
int sum = 0;
void calculate() {
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            if(ms[i][j] > 0) sum += ms[i][j];
        }
    }
}

int main()
{
    scanf("%d %d %d",&R,&C,&T);
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            scanf("%d",&ms[i][j]);
            if(ms[i][j] == -1) {
                clean.push_back(make_pair(i,j));
            }
        }
    }
    for(int i=1; i<=T; i++) {
        spread();
        cleaner();
    }
    calculate();
    printf("%d",sum);
}

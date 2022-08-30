#include <iostream>
#include <stdio.h>
#include <deque>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef struct option {
    int y,x,scale,speed,dir;
}option;

typedef struct soption {
    int scale;
    int speed;
    int dir;
}soption;

int R,C,M;
int result = 0;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,1,-1};
vector < soption > v[101][101];

void fishing() {
    if(M == 0) {
        return;
    }
    for(int i=1; i<=C; i++) {
        for(int j=1; j<=R; j++) {
            if(v[j][i].size()) {
                result += v[j][i][0].scale;
                v[j][i].clear();
                break;
            }
        }
        deque < option > temp;
        // 임시 저장
        for(int j=1; j<=R; j++) {
            for(int k=1; k<=C; k++) {
                if(v[j][k].size()) {
                    temp.push_back({j,k,v[j][k][0].scale, v[j][k][0].speed, v[j][k][0].dir });
                    v[j][k].clear();
                }
            }
        }
        for(int t=0; t<temp.size(); t++) {
                    int y = temp[t].y;
                    int x = temp[t].x;
                    int scale = temp[t].scale;
                    int speed = temp[t].speed;
                    int dir = temp[t].dir;

                        if(dir == 0 || dir == 1) {
                            int module = (R-1)*2;
                            if(speed >= module) speed = speed % module;
                            for(int s=0; s<speed; s++) {
                            int next = y + dy[dir];
                            if(!(1 <= next && next <= R))
                                dir = 1 - dir;
                            y += dy[dir];
                            }
                        }
                        else {
                            int module = (C-1)*2;
                            if(speed >= module) speed = speed % module;
                            for(int s=0; s<speed; s++) {
                            int next = x + dx[dir];
                            if(!(1<=next && next<=C))
                                dir = 5-dir;
                            x += dx[dir];
                            }
                        }
                    //이동 완료 후 상어 위치에 대해
                    //해당 위치에 상어가 없었다면
                    if(!v[y][x].size()) {
                        v[y][x].push_back({scale,speed,dir});
                    }
                    else {
                        // "새로 이동한" 원래 있던 상어보다 더 크다면 대체
                        if(v[y][x][0].scale < scale) {
                            v[y][x].clear();
                            v[y][x].push_back({scale,speed,dir});
                        }
                    }
        }
    }
}

int main()
{
    int r,c,s,d,z;
    scanf("%d %d %d",&R,&C,&M);
    for(int i=1; i<=M; i++) {
        scanf("%d %d %d %d %d",&r,&c,&s,&d,&z);
        v[r][c].push_back({z,s,d-1});
    }
    fishing();
    printf("%d",result);
}

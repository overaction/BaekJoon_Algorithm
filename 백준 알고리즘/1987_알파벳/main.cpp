#include <iostream>
#include <iostream>
#include <stdio.h>
#include <deque>
#include <string.h>
#include <algorithm>
using namespace std;
int R,C,maximum = 0;
int graph[21][21];
deque < int > dq[26];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void calculate(int y, int x, int cnt) {
    maximum = (maximum <= cnt) ? cnt : maximum;
    for(int i=0; i<4; i++) {
        int ny = y +dy[i];
        int nx = x +dx[i];
        if(ny >= R || ny < 0 || nx >= C || nx < 0 ) continue;
        int num = graph[ny][nx] - 65;
        if(dq[num].size() >= 1) continue;
        dq[num].push_back(1);
        calculate(ny,nx,cnt+1);
        dq[num].pop_back();
    }
}

int main() {
    char str[21];
    scanf("%d %d",&R,&C);
    for(int i=0; i<R; i++) {
        scanf("%s",&str);
        for(int j=0; j<C; j++) {
            graph[i][j] = str[j];
        }
    }
    int init = graph[0][0] - 65;
    dq[init].push_back(1);
    calculate(0,0,1);
    printf("%d",maximum);
}

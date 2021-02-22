#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int A,B;
int N,M;
typedef struct op {
    int x,y,cur;
}op;
deque < op > Rob;
int Map[101][101]; // 좌표에 로봇 위치와 로봇 번호 기록
int counts = 0;

int moving(int num, char option, int rep) {
    bool flag = false;
    int y = Rob[num].y;
    int x = Rob[num].x;
    int cur = Rob[num].cur;
    if(option == 'R') {
        cur = cur - (rep % 4);
        if(cur < 0) cur += 4;
        Rob[num].cur = cur;
    }
    else if(option == 'L') {
        cur = cur + (rep % 4);
        if(cur > 3) cur -= 4;
        Rob[num].cur = cur;
    }
    else {
        int nowy = y;
        int nowx = x;
        for(int i=1; i<=rep; i++) {
            y = y + dy[cur];
            x = x + dx[cur];
            // 범위를 벗어난다
            if(y > B || y <= 0 || x > A || x <= 0) {
                printf("Robot %d crashes into the wall",num+1);
                counts++;
                flag = true;
                return flag;
            }
            // 만약 가는 도중에 로봇과 만난다면
            if(Map[y][x] != 0) {
                printf("Robot %d crashes into robot %d",num+1,Map[y][x]);
                counts++;
                flag = true;
                return flag;
            }
        }
        Map[nowy][nowx] = 0;
        Map[y][x] = num+1;
        Rob[num].y = y;
        Rob[num].x = x;
    }
    return flag;
}

int main() {
    int x,y;
    char cur;
    int num,rep;
    char option;
    scanf("%d %d %d %d",&A,&B,&N,&M);
    for(int i=1; i<=N; i++) {
        scanf("%d %d %c",&x,&y,&cur);
        Map[y][x] = i;
        switch(cur) {
        case 'E':
            Rob.push_back({x,y,0});
            break;
        case 'S':
            Rob.push_back({x,y,1});
            break;
        case 'W':
            Rob.push_back({x,y,2});
            break;
        case 'N':
            Rob.push_back({x,y,3});
        }
    }
    for(int i=1; i<=M; i++) {
        scanf("%d %c %d",&num,&option,&rep);
        if(moving(num-1,option,rep)) break;
    }
    if(counts == 0) printf("OK");
}


#include <iostream>
#include <stdio.h>
#include <vector>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;
int r1,c1,r2,c2;
int midy,midx;
int square[50][5];
int dy[4] = {-1,0,1,0};
int dx[4] = {0,-1,0,1};

int main()
{
    scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
    // 네 꼭지점이 0이 아닐동안
    // (y-r1,x-c1) 이 첫 시작점이 된다
    int y = 0, x = 0;
    int dir = 3;
    int cnt = 0, num = 1, dcnt = 1;
    while(!square[r2-r1][c2-c1] || !square[0][0] || !square[r2-r1][0] || !square[0][c2-c1]) {
        // 범위 내에 있을때
        if(y-r1 >= 0 && y-r1 <= r2-r1 && x-c1 >= 0 && x-c1 <= c2-c1) {
            square[y-r1][x-c1] = num;
        }
        cnt+=1;
        num+=1;
        y += dy[dir];
        x += dx[dir];

        if(cnt == dcnt) {
            cnt = 0;
            dir = (dir+1) % 4;
            // 방향을 돌릴때마다 소용돌이가 커진다
            if(dir == 1 || dir == 3) dcnt+=1;
        }
    }

    cnt = 0;
    while(num) {
        num /= 10;
        cnt += 1;
    }
    for(int i=0; i<=r2-r1; i++) {
        for(int j=0; j<=c2-c1; j++) {
            printf("%*d ",cnt,square[i][j]);
        }
        printf("\n");
    }
}

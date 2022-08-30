#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int N,M;
int board[1024][1024];
// y좌표에서 각각 0~x좌표까지 더한 합
int cache[1024][1024];

// (y,0) ~ (y,x) 까지 더한 값을 반환
int solution(int y, int x) {
    if(x < 0) return 0;
    int &ret = cache[y][x];
    if(ret != 0) return ret;

    for(int i=0; i<=x; i++) {
        ret += board[y][i];
    }
    return ret;
}

int main()
{
    int x1,x2;
    int y1,y2;
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d",&board[i][j]);
        }
    }
    for(int m=0; m<M; m++) {
        scanf("%d %d %d %d",&y1,&x1,&y2,&x2);
        int result = 0;
        for(int i=y1-1; i<y2; i++) {
            result = result + (solution(i,x2-1)-solution(i,x1-2));
        }
        printf("%d\n",result);
    }
}

#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
int N;
int board[101][101];
long long cache[101][101];

// cache 확인하는 함수
void prin() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ",cache[i][j]);
        }
        printf("\n");
    }
}

long long solution(int y, int x) {
    // 기저사례 : 오른쪽 끝 도달
    if(y == N-1 && x == N-1) return 1;
    if(y >= N || x >= N) return 0;
    // 메모이제이션
    long long &ret = cache[y][x];
    if(ret != -1)
        return ret;
    // 칸에 0이 적혀있다면
    if(board[y][x] == 0)
        return 0;
    int jump = board[y][x];
    return ret = (solution(y+jump,x) + solution(y,x+jump));
}

int main()
{
    scanf("%d",&N);
    memset(cache,-1,sizeof(cache));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d",&board[i][j]);
        }
    }
    printf("%lld\n",solution(0,0));
}

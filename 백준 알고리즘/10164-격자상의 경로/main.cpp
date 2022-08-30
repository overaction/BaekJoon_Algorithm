#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int N,M;
int K;
int A[16][16];
// y,x에서 시작해서 끝에 도달하는 경우의수
int cache[16][16];
// y,x에서 시작해서 K에 도달하는 경우의수
int cache2[16][16];
int ky,kx;
int dy[2] = {1,0};
int dx[2] = {0,1};

int solution(int y, int x) {
    if(y == N-1 && x == M-1) return 1;
    if(y >= N || x >= M) return 0;

    int &ret = cache[y][x];
    if(ret != -1) return ret;

    ret = 0;
    for(int i=0; i<2; i++) {
        int newy = y + dy[i];
        int newx = x + dx[i];
        ret += solution(newy,newx);
    }
    return ret;
}

int solution2(int y, int x) {
    if(A[y][x] == K) return 1;
    if(y >= N || x >= M || A[y][x] > K) return 0;

    int &ret = cache2[y][x];
    if(ret != -1) return ret;

    ret = 0;
    for(int i=0; i<2; i++) {
        int newy = y + dy[i];
        int newx = x + dx[i];
        ret += solution2(newy,newx);
    }
    return ret;
}

int main()
{
    int num = 1;
    memset(cache,-1,sizeof(cache));
    memset(cache2,-1,sizeof(cache2));
    scanf("%d %d %d",&N,&M,&K);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            A[i][j] = num++;
            if(A[i][j] == K) {
                ky = i;
                kx = j;
            }
        }
    }
    if(K == 0)
        printf("%d\n",solution(0,0));
    else
        printf("%d\n",solution2(0,0) * solution(ky,kx));
}

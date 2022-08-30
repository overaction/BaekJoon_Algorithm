#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int M,N;
int A[501][501];
// i,j ���� ���� �� �ִ� ����� �� ��ȯ
int cache[501][501];

int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

int solution(int y, int x) {
    if(x==N-1 && y==M-1) return 1;
    int &ret = cache[y][x];
    if(ret != -1) return ret;

    ret = 0;
    for(int i=0; i<4; i++) {
        int newy = y + dy[i];
        int newx = x + dx[i];
        // �� ���̰� ����������
        if((newy < M || newy >= 0 || newx < N || newx >= 0) && A[y][x] > A[newy][newx])
            ret += solution(newy,newx);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d %d",&M,&N);
    for(int i=0; i<M; i++)
        for(int j=0; j<N; j++)
            scanf("%d",&A[i][j]);
    printf("%d\n",solution(0,0));
}

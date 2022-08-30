#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
int N;
int board[101][101];
long long cache[101][101];

// cache Ȯ���ϴ� �Լ�
void prin() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ",cache[i][j]);
        }
        printf("\n");
    }
}

long long solution(int y, int x) {
    // ������� : ������ �� ����
    if(y == N-1 && x == N-1) return 1;
    if(y >= N || x >= N) return 0;
    // �޸������̼�
    long long &ret = cache[y][x];
    if(ret != -1)
        return ret;
    // ĭ�� 0�� �����ִٸ�
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

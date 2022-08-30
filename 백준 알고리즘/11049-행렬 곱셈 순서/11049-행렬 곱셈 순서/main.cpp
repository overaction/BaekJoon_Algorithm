#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int N;
int cache[501][501];
int matrix[501][2];

// 행렬 a ~ b까지 곱한 최소값 반환

int solution(int a, int b) {
    if(a == b) return 0;
    // 2개밖에 안남았으면 그냥 계산
    if(a+1 == b)
        return matrix[a][0] * matrix[a][1] * matrix[b][1];
    int &ret = cache[a][b];
    if(ret != -1) return ret;

    for(int i=a; i<b; i++) {
        int temp = solution(a,i) + solution(i+1,b);
        if(ret == -1 || ret > temp + matrix[a][0]*matrix[i][1]*matrix[b][1])
            ret = temp+matrix[a][0]*matrix[i][1]*matrix[b][1];
    }
    return ret;
}

int main()
{
    int r,c;
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d %d",&r,&c);
        matrix[i][0] = r;
        matrix[i][1] = c;
    }
    printf("%d\n",solution(0,N-1));
}

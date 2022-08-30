#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define INF 987654321
using namespace std;
int N,M;
int A[2001];
int cache[2001][2001];

// a~b까지 숫자가 팰린드롬인지 아닌지 반환
int solution(int a, int b) {
    // 아무일 없이 끝까지 왔다면
    if(a >= b) return 1;
    // 양끝 하나씩 남았을때 검사
    if((a+1) == b) {
        if(A[a] == A[b]) return 1;
        else return 0;
    }
    int &ret = cache[a][b];
    if(ret != -1) return ret;

    ret = 0;
    // 양끝이 같다면 양끝을 한칸씩 당김
    if(A[a] == A[b])
        ret = solution(a+1,b-1);
    printf("ret %d\n",ret);
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
    scanf("%d",&M);
    int a,b;
    for(int i=0; i<M; i++) {
        scanf("%d %d",&a,&b);
        printf("%d\n",solution(a-1,b-1));
    }
}

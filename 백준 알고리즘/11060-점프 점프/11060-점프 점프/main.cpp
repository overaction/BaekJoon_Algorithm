#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <deque>
#define INF 987654321
using namespace std;
int N;
int miro[1001];
int cache[1001];

// idx위치에 있고 끝에 도달했을 때 최소 점프 수 반환
int solution(int idx) {
    if(idx >= N) return INF;
    if(idx == N-1) return 0;
    int &ret = cache[idx];
    if(ret != -1) return ret;

    ret = INF;
    for(int i=1; i<=miro[idx]; i++) {
        ret = min(ret,solution(idx+i)+1);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&miro[i]);
    int result = solution(0);
    result == INF ? printf("-1\n") : printf("%d\n",result);
}

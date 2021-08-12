#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
/*
    최대 메모리가 10,000,000이기 때문에 메모리초과 발생 가능
    대신 최대 cost를 메모이제이션 한다
*/
int N,M;
int memory[101];
int cost[101];

// idx까지 왔고 총 비용이 cost일때 확보되는 최대 메모리
int cache[101][10001];

int solution(int idx, int totalCost) {
    if(idx == N) return 0;
    int &ret = cache[idx][totalCost];
    if(ret !=- 1) return ret;

    ret = 0;
    // 앱을 비활성화 안함
    ret = solution(idx+1,totalCost);
    // cost가 남아있다면 앱을 비활성화 함
    if(totalCost - cost[idx] >= 0) {
        ret = max(ret,solution(idx+1,totalCost-cost[idx])+memory[idx]);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) {
        scanf("%d",&memory[i]);
    }
    for(int i=0; i<N; i++) {
        scanf("%d",&cost[i]);
    }
    int totalCost = 0;
    while(1) {
        if(solution(0,totalCost) >= M) {
            printf("%d\n",totalCost);
            break;
        }
        totalCost++;
    }
}

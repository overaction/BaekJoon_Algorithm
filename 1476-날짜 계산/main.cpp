#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define MIN -987654321;
int N;
int cache[100001];
int cost[100001];

// idx번째 숫자까지 더한 최대값 반환
int solution(int idx) {
    int &ret = cache[idx];
    if(ret != -1) return ret;

    // 자기자신 또는 자기자신+이전 합
    ret = max(cost[idx], cost[idx]+cache[idx-1]);
    return ret;
}

int main() {
    scanf("%d",&N);
    memset(cache,-1,sizeof(cache));
    for(int i=0; i<N; i++) {
        scanf("%d",&cost[i]);
    }
    cache[0] = cost[0];
    int result = MIN;
    for(int i=0; i<N; i++) {
        result = max(result,solution(i));
    }
    printf("%d\n",result);
}


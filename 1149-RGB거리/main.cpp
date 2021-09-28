#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define MAX 987654321;
int N;
// 색깔이 color인 idx번째 집까지의 최소 코스트
int cache[4][1001];
int cost[4][1001];


int solution(int idx, int color) {
    int &ret = cache[color][idx];
    if(ret != -1) return ret;
    
    ret = MAX;
    for(int i=0; i<3; i++) {
        if(i == color) continue;
        ret = min(solution(idx-1,i)+cost[color][idx],ret);
    }
    return ret;
}

int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<3; j++) {
            scanf("%d",&cost[j][i]);
        }
    }
    memset(cache,-1,sizeof(cache));
    for(int i=0; i<3; i++) {
        cache[i][0] = cost[i][0];
    }
    int result = MAX;
    for(int i=0; i<3; i++) {
        result = min(result,solution(N-1,i));
    }
    printf("%d\n",result);
}
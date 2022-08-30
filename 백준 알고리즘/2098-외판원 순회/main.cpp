#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#define INF 987654321
using namespace std;
int W[17][17];
int N;
// 1 << 16 = 1 * 2^16
int cache[17][1 << 16];
int complete;

// 현재 위치 cur에 있을 때 visited도시들을 방문 했을 때 최소값 반환
int solution(int cur, int visited) {
    // 전부 방문했다면 처음 자리로 복귀해야한다
    if(visited == complete) {
        // 돌아오는 길이 없다면 실패
        if(W[cur][0] == 0) return INF;
        else return W[cur][0];
    }

    int &ret = cache[cur][visited];
    if(ret != -1) return ret;

    ret = INF;
    for(int i=0; i<N; i++) {
        if(W[cur][i] == 0) continue;
        // 이미 방문했으면
        if((visited & (1 << i)) == (1 << i)) continue;
        ret = min(ret,solution(i,visited | (1 << i))+W[cur][i]);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    complete = (1 << N) - 1;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d",&W[i][j]);
        }
    }
    printf("%d\n",solution(0,1));
}

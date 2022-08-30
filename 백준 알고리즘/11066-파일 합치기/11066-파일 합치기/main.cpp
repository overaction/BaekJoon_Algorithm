#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int T;
int K;
int social[501];
int hap[501];
int cache[501][501];

// 소설 a~b까지 합치는데 드는 최소비용 리턴
// cache[a][b] = cache[a][i]+cache[i+1][b] , cache[a][i+1]+cache[i+2][b] , ... , cache[a][b-1]+cache[b][b]
int solution(int a, int b) {
    if(a == b) return 0;
    if(a+1 == b) return social[a] + social[b];

    int &ret = cache[a][b];
    if(ret != -1) return ret;

    for(int i=a; i<=b; i++) {
        int temp = solution(a,i) + solution(i+1,b);
        if(ret == -1 || ret > temp + hap[b] - hap[a-1])
            ret = temp + hap[b] - hap[a-1];
    }
    return ret;
}

int main()
{
    scanf("%d",&T);
    for(int i=0; i<T; i++) {
        memset(cache,-1,sizeof(cache));
        memset(hap,0,sizeof(hap));
        scanf("%d",&K);
        scanf("%d",&social[0]);
        hap[0] = social[0];
        for(int j=1; j<K; j++) {
            scanf("%d",&social[j]);
            hap[j] = hap[j-1] + social[j];
        }
        printf("%d\n",solution(0,K-1));
    }
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N,W,V,K;
int cache[101][100001];
typedef struct items {
    int w,v;
}items;

vector <items> bag;

// idx번째 물건까지 선택했고 weight만큼 남아있을 때 최대 가치합 반환
int solution(int idx, int weight) {
    if(weight <= 0 || idx == N) return 0;

    int &ret = cache[idx][weight];
    if(ret != -1) return ret;

    // 물건을 선택하지 않고 넘어갈 경우
    ret = solution(idx+1,weight);
    if(weight - bag[idx].w >= 0)
        ret = max(ret, solution(idx+1,weight-bag[idx].w)+bag[idx].v);
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; i++) {
        scanf("%d %d",&W,&V);
        bag.push_back({W,V});
    }
    int result = solution(0,K);
    printf("%d\n",result);
}

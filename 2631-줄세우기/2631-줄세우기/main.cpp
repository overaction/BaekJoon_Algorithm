#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N;
int child[201];
int cache[201];

// start에서 시작하는 최대 증가 부분 수열 크기 계산
int solution(int start) {
    int &ret = cache[start];
    if(ret != -1) return ret;

    ret = 1;
    for(int i=start+1; i<N; i++) {
        if(child[start] < child[i])
            ret = max(ret, solution(i)+1);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&child[i]);
    }
    int result = 0;
    for(int i=0; i<N; i++)
        result = max(result,solution(i));
    printf("%d\n",N-result);
}

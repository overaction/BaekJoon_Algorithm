#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int bitonic[1001];
int cache1[1001];
int cache2[1001];

// ends에서 끝나는 최대 LIS 길이 반환
int LIS(int ends) {
    int &ret = cache1[ends];
    if(ret != -1) return ret;

    ret = 1;
    for(int i=0; i<=ends; i++) {
        if(bitonic[i] < bitonic[ends])
            ret = max(ret, LIS(i) + 1);
    }
    return ret;
}

// start 에서 시작하는 최대 LDS 길이 반환
int LDS(int start) {
    if(start == N) return 0;
    int &ret = cache2[start];
    if(ret != -1) return ret;

    ret = 1;
    for(int i=start+1; i<N; i++) {
        if(bitonic[start] > bitonic[i]) {
            ret = max(ret, LDS(i)+1);
        }
    }
    return ret;
}

int main() {
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d",&bitonic[i]);
    memset(cache1,-1,sizeof(cache1));
    memset(cache2,-1,sizeof(cache2));
    int result = 0;
    for(int i=0; i<N; i++) {
        result = max(result,LIS(i)+LDS(i));
    }
    printf("%d\n",result-1);
}



#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int T,N;
int cache[12];

int solution(int n) {
    int &ret = cache[n];
    if(ret != -1) return ret;

    ret = solution(n-3) + solution(n-2) + solution(n-1);
    return ret;
}

int main() {
    scanf("%d",&T);
    memset(cache,-1,sizeof(cache));
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    for(int t=0; t<T; t++) {
        scanf("%d",&N);
        printf("%d\n",solution(N));
    }
}


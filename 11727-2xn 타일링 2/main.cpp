#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int N;
int cache[1001];

// n크기의 직사각형을 채우는 방법의 수 반환
int solution(int n) {
    int &ret = cache[n];
    if(ret != -1) return ret;

    ret = solution(n-2) + solution(n-1);
    return ret % 10007;
}

int main() {
    scanf("%d",&N);
    memset(cache,-1,sizeof(cache));
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;
    printf("%d\n",solution(N));
}
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#define MOD 9901
using namespace std;

int N;
int zoo[100001][2];
int cache[100001][3];

int solution(int n, int status) {
    if(n == N) return 1;

    int &ret = cache[n][status];
    if(ret != -1) return ret;

    // 배치하지 않고 넘어감
    ret = solution(n+1,0) % MOD;
    // 오른쪽에 배치하고 넘어감
    if(status != 2)
        ret += solution(n+1,2) % MOD;
    // 왼쪽에 배치하고 넘어감
    if(status != 1)
        ret += solution(n+1,1) % MOD;

    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    printf("%d\n",solution(0,0) % MOD);
}

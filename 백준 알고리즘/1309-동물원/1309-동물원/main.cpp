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

    // ��ġ���� �ʰ� �Ѿ
    ret = solution(n+1,0) % MOD;
    // �����ʿ� ��ġ�ϰ� �Ѿ
    if(status != 2)
        ret += solution(n+1,2) % MOD;
    // ���ʿ� ��ġ�ϰ� �Ѿ
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

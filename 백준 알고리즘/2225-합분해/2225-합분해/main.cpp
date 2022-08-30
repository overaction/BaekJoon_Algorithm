#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#define MOD 1000000000;
using namespace std;
int N,K;
// k���� ������ �� ���� n�̵Ǵ� ����Ǽ� ����
int cache[201][201];


// cache[k][n] = cache[k-1][n]+cache[k-2][n]
int solution(int n, int k) {
    int &ret = cache[k][n];
    if(ret != -1) return ret;
    // �� ���� 0�� ���� 1���� ��
    if(n == 0) return ret = 1;
    // 1���� ������ �� n�� ���� 1���� ��
    if(k == 1) return ret = 1;

    // �ʱⰪ 0
    ret = 0;

    for(int i=n; i>=0; i--) {
        ret += solution(i,k-1);
        ret %= MOD;
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d %d",&N, &K);
    printf("%d\n",solution(N,K));
}

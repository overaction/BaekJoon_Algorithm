#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <deque>
using namespace std;
/*
    �ִ� �޸𸮰� 10,000,000�̱� ������ �޸��ʰ� �߻� ����
    ��� �ִ� cost�� �޸������̼� �Ѵ�
*/
int N,M;
int memory[101];
int cost[101];

// idx���� �԰� �� ����� cost�϶� Ȯ���Ǵ� �ִ� �޸�
int cache[101][10001];

int solution(int idx, int totalCost) {
    if(idx == N) return 0;
    int &ret = cache[idx][totalCost];
    if(ret !=- 1) return ret;

    ret = 0;
    // ���� ��Ȱ��ȭ ����
    ret = solution(idx+1,totalCost);
    // cost�� �����ִٸ� ���� ��Ȱ��ȭ ��
    if(totalCost - cost[idx] >= 0) {
        ret = max(ret,solution(idx+1,totalCost-cost[idx])+memory[idx]);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d %d",&N,&M);
    for(int i=0; i<N; i++) {
        scanf("%d",&memory[i]);
    }
    for(int i=0; i<N; i++) {
        scanf("%d",&cost[i]);
    }
    int totalCost = 0;
    while(1) {
        if(solution(0,totalCost) >= M) {
            printf("%d\n",totalCost);
            break;
        }
        totalCost++;
    }
}

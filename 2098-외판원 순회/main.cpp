#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#define INF 987654321
using namespace std;
int W[17][17];
int N;
// 1 << 16 = 1 * 2^16
int cache[17][1 << 16];
int complete;

// ���� ��ġ cur�� ���� �� visited���õ��� �湮 ���� �� �ּҰ� ��ȯ
int solution(int cur, int visited) {
    // ���� �湮�ߴٸ� ó�� �ڸ��� �����ؾ��Ѵ�
    if(visited == complete) {
        // ���ƿ��� ���� ���ٸ� ����
        if(W[cur][0] == 0) return INF;
        else return W[cur][0];
    }

    int &ret = cache[cur][visited];
    if(ret != -1) return ret;

    ret = INF;
    for(int i=0; i<N; i++) {
        if(W[cur][i] == 0) continue;
        // �̹� �湮������
        if((visited & (1 << i)) == (1 << i)) continue;
        ret = min(ret,solution(i,visited | (1 << i))+W[cur][i]);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    complete = (1 << N) - 1;

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            scanf("%d",&W[i][j]);
        }
    }
    printf("%d\n",solution(0,1));
}

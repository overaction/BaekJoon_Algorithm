#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define INF 987654321
using namespace std;
int N,M;
int A[2001];
int cache[2001][2001];

// a~b���� ���ڰ� �Ӹ�������� �ƴ��� ��ȯ
int solution(int a, int b) {
    // �ƹ��� ���� ������ �Դٸ�
    if(a >= b) return 1;
    // �糡 �ϳ��� �������� �˻�
    if((a+1) == b) {
        if(A[a] == A[b]) return 1;
        else return 0;
    }
    int &ret = cache[a][b];
    if(ret != -1) return ret;

    ret = 0;
    // �糡�� ���ٸ� �糡�� ��ĭ�� ���
    if(A[a] == A[b])
        ret = solution(a+1,b-1);
    printf("ret %d\n",ret);
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&A[i]);
    scanf("%d",&M);
    int a,b;
    for(int i=0; i<M; i++) {
        scanf("%d %d",&a,&b);
        printf("%d\n",solution(a-1,b-1));
    }
}

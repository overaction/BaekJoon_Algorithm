#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N;
int num[101];
long long int cache[101][21]; // cache[idx][������]

// solution(idx,hap) = idx���� �԰� �������� hap�϶� ������ ���� �� ���� �´� ����� ��
// solution(0,
long long int solution(int idx, int hap) {
    // �߰� ����� �׻� 0~20 �̾�� �Ѵ�
    if(hap > 20 || hap < 0)
        return 0;
    if((idx == N-2) && hap == num[N-1])
        return 1;

    long long int &ret = cache[idx][hap];
    if(ret != -1) return ret;

    ret = 0;
    ret = solution(idx+1,hap+num[idx+1]) + solution(idx+1, hap-num[idx+1]);
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&num[i]);
    }
    cout << solution(0,num[0]) <<endl;
}

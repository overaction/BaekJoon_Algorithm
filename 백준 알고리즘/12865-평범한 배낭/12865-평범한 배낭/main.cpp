#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int N,W,V,K;
int cache[101][100001];
typedef struct items {
    int w,v;
}items;

vector <items> bag;

// idx��° ���Ǳ��� �����߰� weight��ŭ �������� �� �ִ� ��ġ�� ��ȯ
int solution(int idx, int weight) {
    if(weight <= 0 || idx == N) return 0;

    int &ret = cache[idx][weight];
    if(ret != -1) return ret;

    // ������ �������� �ʰ� �Ѿ ���
    ret = solution(idx+1,weight);
    if(weight - bag[idx].w >= 0)
        ret = max(ret, solution(idx+1,weight-bag[idx].w)+bag[idx].v);
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; i++) {
        scanf("%d %d",&W,&V);
        bag.push_back({W,V});
    }
    int result = solution(0,K);
    printf("%d\n",result);
}

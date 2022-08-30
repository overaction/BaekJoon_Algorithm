#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

// �ִ� ���� �κ� ������ ����ؼ� Ǯ���Ѵ�.
// ���� �����븦 �������� �����ϰ� ������ �����븦 �������� LIS�� ���� ���� ���� ���� ���´�.

int N;
vector < pair < int,int > > v;
int cache[501];

// start���� �����ϴ� ���� �� ���� ��ȯ
int solution(int start) {
    int &ret = cache[start];
    if(ret != -1) return ret;

    ret = 1;
    for(int i=start+1; i<v.size(); i++) {
        if(v[i].second > v[start].second)
            ret = max(ret,solution(i)+1);
    }
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    int a,b;
    for(int i=0; i<N; i++) {
        scanf("%d %d",&a,&b);
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    int result = 0;
    for(int i=0; i<v.size(); i++) {
        result = max(result,solution(i));
    }
    printf("%d\n",N-result);
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

// 최대 증가 부분 수열을 사용해서 풀이한다.
// 왼쪽 전봇대를 기준으로 정렬하고 오른쪽 전봇대를 기준으로 LIS를 구한 값을 빼면 답이 나온다.

int N;
vector < pair < int,int > > v;
int cache[501];

// start에서 시작하는 가장 긴 수열 반환
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

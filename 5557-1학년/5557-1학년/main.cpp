#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int N;
int num[101];
long long int cache[101][21]; // cache[idx][숫자합]

// solution(idx,hap) = idx까지 왔고 숫자합이 hap일때 끝까지 갔을 때 답이 맞는 경우의 수
// solution(0,
long long int solution(int idx, int hap) {
    // 중간 결과가 항상 0~20 이어야 한다
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

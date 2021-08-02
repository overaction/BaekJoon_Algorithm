#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int A[1001];
int cache[1001];

// start에서 시작하는 증가부분 수열 중 가장 큰 합을 반환
int solution(int start) {
    if(start == N) return 0;

    int &ret = cache[start];
    if(ret != -1) return ret;
    ret = A[start];
    for(int i=start+1; i<N; i++) {
        if(A[start] < A[i]) {
            ret = max(ret, solution(i)+A[start]);
        }
    }
    return ret;
}

int main()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++)
        scanf("%d",&A[i]);
    memset(cache,-1,sizeof(cache));
    int result = 0;
    for(int i=0; i<N; i++) {
        result = max(result,solution(i));
    }
    printf("%d\n",result);
}

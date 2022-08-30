#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int N;
int cache[1001];
int box[1001];

// start에서 시작해서 넣을 수 있는 최대 상자의 개수
// cache[start] = max(ret, sigma(solution(idx)))
int solution(int start) {
    if(start >= N) return 0;
    int &ret = cache[start];
    if(ret != -1) return ret;

    ret = 1;
    for(int i=start+1; i<N; i++) {
        if(box[start] < box[i])
            ret = max(ret,solution(i)+1);
    }

    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d",&N);
    for(int i=0; i<N; i++) scanf("%d",&box[i]);
    int result = 0;
    for(int i=0; i<N; i++)
        result = max(result,solution(i));
    printf("%d\n",result);
}

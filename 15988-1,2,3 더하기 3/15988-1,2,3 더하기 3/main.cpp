#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#define MOD 1000000009
using namespace std;
int N,T;
long long int cache[1000001];

// cache[n] = cache[n-1]+cache[n-2]+cache[n-3]
long long int solution(int num) {
    long long int &ret = cache[num];
    if(ret != -1) return ret;

    ret = solution(num-1)%MOD+solution(num-2)%MOD+solution(num-3)%MOD;
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    scanf("%d",&T);
    for(int i=0; i<T; i++) {
        scanf("%d",&N);
        cout << solution(N)%MOD << endl;
    }
}

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define MAX 987654321;

int cache[1000001];

int solution(int n) {
    int &ret = cache[n];
    if(ret != -1) return ret;

    ret = MAX;
    if(n % 3 == 0)
        ret = min(ret,solution(n/3)+1);
    if(n % 2 == 0)
        ret = min(ret,solution(n/2)+1);
    ret = min(ret,solution(n-1)+1);

    return ret;
}

int main()
{
    int num;
    scanf("%d",&num);
    memset(cache,-1,sizeof(cache));
    cache[1] = 0;
    cache[2] = 1;
    cache[3] = 1;
    printf("%d\n",solution(num));
}
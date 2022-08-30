#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int a,b,c;
int cache[51][51][51];
int solution(int a, int b, int c) {
    if(a<=0 || b<=0 || c<=0)
        return 1;
    int &ret = cache[a][b][c];
    if(ret != -1) return ret;

    if(a>20||b>20||c>20)
        return ret = solution(20,20,20);
    if(a<b && b<c)
        return ret = solution(a,b,c-1) + solution(a,b-1,c-1) - solution(a,b-1,c);
    else
        return ret = solution(a-1, b, c) + solution(a-1, b-1, c) + solution(a-1, b, c-1) - solution(a-1, b-1, c-1);


}

int main()
{
    memset(cache,-1,sizeof(cache));
    while(1) {
        scanf("%d %d %d",&a,&b,&c);
        if(a==-1 && b==-1 && c==-1)
            return 1;
        printf("w(%d, %d, %d) = %d\n",a,b,c,solution(a,b,c));
    }
}

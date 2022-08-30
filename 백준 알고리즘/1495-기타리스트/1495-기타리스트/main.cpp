#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
// 곡 개수 , 시작 볼륨 , 최대 볼륨
int N,S,M;
int songs[101];
// index번째 노래이며 볼륨이 vol일때 마지막 노래에서의 최대 볼륨
int cache[101][1001];

int solution(int idx, int vol) {
    if(idx == N)
        return vol;
    int &ret = cache[idx][vol];
    if(ret != -1) return ret;

    ret = -2;
    if(vol+songs[idx] <= M)
        ret = max(ret,solution(idx+1,vol+songs[idx]));
    if(vol-songs[idx] >= 0)
        ret = max(ret,solution(idx+1,vol-songs[idx]));
    return ret;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d %d %d",&N,&S,&M);
    for(int i=0; i<N; i++)
        scanf("%d",&songs[i]);
    int result = solution(0,S);
    if(result == -2) printf("-1");
    else printf("%d\n",result);
}

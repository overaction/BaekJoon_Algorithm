#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
int n,m;
int A[1001][1001];
int cache[1001][1001];

int dy[3] = {1,0,1};
int dx[3] = {0,1,1};

// y,x 까지 도달했을 때 최대 정사각형 한 변 길이 반환
int solution(int y, int x) {
    // 기저사례
    if(y >= n || y < 0 || x >= m || x < 0) return 0;
    if(A[y][x] == 0) return 0;

    int &ret = cache[y][x];
    if(ret != -1) return ret;
    ret = 1;
    int res = 987654321;
    for(int i=0; i<3; i++) {
        res = min(res, solution(y+dy[i],x+dx[i]));
    }
    return ret+=res;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d",&A[i][j]);
        }
    }
    int result = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            result = max(result,solution(i,j));
        }
    }
    printf("%d\n",result*result);
}

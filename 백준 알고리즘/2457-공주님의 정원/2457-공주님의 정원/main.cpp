#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
// 3.1 ~ 11.30
// 가능한 적게
typedef struct option {
    int starts,ends;
}op;
vector < op > v;

bool cmp(const op &a, const op &b) {
    if(a.starts < b.starts) return true;
    else if(a.starts == b.starts) {
        if(a.ends < b.ends) return true;
    }
    return false;
}

int solution() {
    int now = 301;
    int idx = -1;
    int flag = false;
    int cnt = 0;
    int endDate = 0;
    int nextIdx = 0;
    while(now <= 1130 && idx < N) {
        idx++;
        flag = false;
        endDate = 0;
        for(int i=idx; i<N; i++) {
            if(now < v[i].starts)
                break;
            // 가장 늦게 지는 꽃 찾기
            if(endDate < v[i].ends) {
                endDate = v[i].ends;
                flag = true;
                nextIdx = i;
            }
        }
        if(flag) {
            now = endDate;
            cnt++;
            idx = nextIdx;
        }
    }
    now > 1130 ? cnt = cnt : cnt = 0;
    return cnt;
}

int main() {
    int a,b,c,d;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        v.push_back({a*100+b, c*100+d});
    }
    sort(v.begin(),v.end(),cmp);
    printf("%d\n",solution());
}



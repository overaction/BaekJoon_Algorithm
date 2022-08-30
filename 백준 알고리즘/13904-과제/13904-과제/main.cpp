#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int N;
int d,w;
vector < pair <int,int> > v;
int order[1001];

// 가장 높은 점수부터 최대한 늦게
int solution() {
    for(int i=0; i<N; i++) {
        int nextVal = v[i].first;
        int nextDate = v[i].second;
        if(order[nextDate] == 0)
            order[nextDate] = nextVal;
        else {
            for(int j=nextDate-1; j>0; j--) {
                if(order[j] == 0) {
                    order[j] = nextVal;
                    break;
                }
            }
        }
    }
    // answer
    int ans = 0;
    for(int i=1; i<=7; i++) {
        ans+=order[i];
    }
    return ans;
}

int main()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d %d",&d,&w);
        v.push_back({w,d});
    }
    sort(v.begin(),v.end(), greater<pair < int,int >>());
    printf("%d\n",solution());
}

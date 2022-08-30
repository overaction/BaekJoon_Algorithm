#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;
int N;
int p,d;
typedef struct option {
    int range, money;
}op;
vector < op > v;
priority_queue < int , vector < int >, greater < int > > pq;

bool cmp(const op &a, const op &b) {
    if(a.range < b.range) return true;
    else if(a.range == b.range) {
        if(a.money < b.money) return true;
    }
    return false;
}

int solution() {
    int ans = 0;
    for(int i=0; i<N; i++) {
        pq.push(v[i].money);
        ans += v[i].money;

        if(pq.size() > v[i].range) {
            ans -= pq.top();
            pq.pop();
        }
    }
    return ans;
}

int main()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d %d",&p,&d);
        v.push_back({d,p});
    }
    sort(v.begin(),v.end(),cmp);
    printf("%d\n",solution());
}

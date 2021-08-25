#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,K;
priority_queue < pair < int,int > > info;
multiset< int > bag;
long long int sum = 0;

void solution() {
    while(!info.empty()) {
        int value = info.top().first;
        int weight = info.top().second;
        info.pop();

        multiset < int >::iterator iter = bag.lower_bound(weight);
        if(iter == bag.end()) continue;

        bag.erase(iter);
        sum += value;
    }
}

int main()
{
    int a,b;
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; i++) {
        scanf("%d %d",&a,&b);
        info.push({b,a});
    }
    int c;
    for(int i=0; i<K; i++) {
        scanf("%d",&c);
        bag.insert(c);
    }
    solution();
    cout << sum << endl;
}

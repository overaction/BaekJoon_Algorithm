#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
vector < pair <int,int > > v;
priority_queue < int, vector <int>, greater < int > > pq;

int solution() {
    pq.push(v[0].second);

    for(int i=1; i<N; i++) {
        int next = v[i].first;

        if(pq.top() > next) {
            pq.push(v[i].second);
        }
        else {
            pq.pop();
            pq.push(v[i].second);
        }
    }
    return pq.size();
}

int main()
{
    int s,t;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d %d",&s,&t);
        v.push_back({s,t});
    }
    sort(v.begin(),v.end());
    printf("%d\n",solution());
}

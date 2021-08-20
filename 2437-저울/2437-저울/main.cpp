#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N;
priority_queue < int, vector < int >, greater <int > > pq;

int solution() {
    int minimum = pq.top();
    pq.pop();
    if(minimum != 1)
        return 1;

    while(!pq.empty()) {
        int next = pq.top();
        pq.pop();

        if(minimum+1 < next)
            break;
        minimum += next;
    }
    return minimum+1;
}

int main()
{
    int num;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&num);
        pq.push(num);
    }
    printf("%d\n",solution());
}

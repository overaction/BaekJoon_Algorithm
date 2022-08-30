#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int N;
int cards[100001];
priority_queue < int > pq;

int solution() {
    int ans = 0;
    for(int i=0; i<N; i++) {
        pq.push(-cards[i]);
    }
    while(pq.size() > 1) {
        int a = -pq.top();
        pq.pop();
        int b = -pq.top();
        pq.pop();
        int next = a+b;
        ans += next;
        pq.push(-next);
    }
    return ans;
}

int main()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&cards[i]);
    }
    printf("%d\n",solution());
}

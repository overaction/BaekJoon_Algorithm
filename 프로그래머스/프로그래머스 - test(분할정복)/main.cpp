#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cache[100001];
int v[100001];
int main() {
    int N,num;
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        scanf("%d",&num);
        v[i] = num;
    }
    cache[1] = v[1];
    cache[2] = v[2]+v[1];
    for(int i=3; i<=N; i++) {
        cache[i] = max(cache[i-2]+v[i],v[i]+v[i-1]+cache[i-3]);
        cache[i] = max(cache[i],cache[i-1]);
    }
    printf("%d\n",cache[N]);
}
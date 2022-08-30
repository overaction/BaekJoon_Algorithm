#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int cache[100001];

int main() {
    int N;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&cache[i]);
    }
    int answer = 2e9;
    for(int i=1; i<N; i++) {
        cache[i] = max(cache[i-1]+cache[i], cache[i]);
        answer = max(answer,cache[i]);
    }
    printf("%d\n",answer);
}
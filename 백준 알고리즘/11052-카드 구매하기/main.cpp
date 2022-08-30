#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define MAX 987654321;
int N;
int cards[1001];
int cache[1001];

int solution(int n) {
    int &ret = cache[n];
    if(ret!=-1) return ret;
    
    for(int i=)
}

int main() {
    scanf("%d",&N);
    memset(cache,-1,sizeof(cache));
    for(int i=1; i<=N; i++) {
        scanf("%d",&cards[i]);
    }

}


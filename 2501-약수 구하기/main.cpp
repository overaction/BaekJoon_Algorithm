#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

void solution(int n) {
    int cnt = 0;
    while(1) {
        if(n == 0) break;
        if(n % 2 == 1) printf("%d ",cnt);
        n = n / 2;
        cnt++;
    }
}

int main() {
    int n,T;
    scanf("%d",&T);
    for(int t=0; t<T; t++) {
        scanf("%d",&n);
        solution(n);
        printf("\n");
    }
}


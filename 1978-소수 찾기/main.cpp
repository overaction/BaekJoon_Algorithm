#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int solution(int num) {
    int cnt = 0;
    for(int i=1; i<=num; i++) {
        if(num % i == 0) cnt++;
    }
    if(cnt == 2) return 1;
    else return 0;
}

int main() {
    int n, num;
    int ans = 0;
    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf("%d",&num);
        if(solution(num)) ans++;
    }
    printf("%d\n",ans);
}
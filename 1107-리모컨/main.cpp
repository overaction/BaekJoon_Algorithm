#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int N,M;
int now = 100;
vector < int > v;
int broken[11];

int check(int n) {
    if (n == 0) {
        if (broken[0]) {
            return 0;
        }
        else {
            return 1;
        }
    }
    int len = 0;
    while (n > 0) {
        if (broken[n % 10]) return 0;
        n = n / 10;
        len += 1;
    }

    return len;
}

int main() {
    scanf("%d %d",&N,&M);
    for(int i=0; i<M; i++) {
        int x;
        scanf("%d",&x);
        broken[x] = 1;
    }
    int result = abs(N-100);
    for(int i=0; i<1000000; i++) {
        int length = check(i);
        if(length > 0) {
            int press = abs(i-N);
            if(result > press+length)
                result = press+length;
        }
    }
    printf("%d\n",result);
}
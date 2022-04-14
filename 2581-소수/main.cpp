#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define MAX 10000;

int solution(int num) {
    int cnt = 0;
    bool flag = 0;
    for(int i=1; i<=num; i++) {
        if(num % i == 0) cnt++;
        if(cnt > 2) {
            flag = 1;
            break;
        }
    }
    if(flag || cnt != 2) return 0;
    else return 1;
}

int searchMinimum(int a, int b) {
    int result = 0;
    (a < b) ? result = a : result = b;
    return result;
}

int main() {
    int M,N;
    int sum = 0;
    int minimum = 10000;
    int cntOfAns = 0;

    scanf("%d %d",&M,&N);
    for(int i=M; i<=N; i++) {
        if(solution(i)) {
            cntOfAns++;
            sum += i;
            minimum = searchMinimum(minimum, i);
        }
    }
    if(cntOfAns) printf("%d %d\n",sum,minimum);
    else printf("-1");
}
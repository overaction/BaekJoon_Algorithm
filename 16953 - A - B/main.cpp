#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define MAX 10001;
int A,B;
int answer = MAX;
void solution(long long int num, int cnt) {
    if(num == B) answer = (answer > cnt) ? cnt : answer;
    if(num * 2 <= B) solution(num*2,cnt+1);
    if(num*10+1 <= B) solution(num*10+1,cnt+1);
}

int main() {
    scanf("%d %d",&A,&B);
    solution(A,0);
    if(answer == 10001) printf("-1");
    else printf("%d\n",answer+1);
}
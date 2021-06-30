#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define INF 98765432
int N;

int solution(int N) {
    if(N < 100) return N;
    int cnt = 99;
    for(int i=100; i<=N; i++) {
        int a= i / 100;
        int b = i / 10 % 10;
        int c = i % 10;

        if((c-b) == (b-a)) cnt++;
    }
    return cnt;
}

int main()
{
    scanf("%d",&N);
    printf("%d",solution(N));
}

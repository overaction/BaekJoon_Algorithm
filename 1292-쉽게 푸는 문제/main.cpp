#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int arr[1001];

void solution() {
    int cnt = 1;
    for(int i=1; i<=1000;) {
        for(int j=1; j<=cnt && i <= 1000; j++) {
            arr[i++] = cnt;
        }
        cnt++;
    }
}

int main() {
    int a,b;
    int sum = 0;
    scanf("%d %d",&a,&b);
    solution();

    for(int i=a; i<=b; i++) sum += arr[i];
    printf("%d\n",sum);
}
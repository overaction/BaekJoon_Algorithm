#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int M,N;
int arr[1000001];

int main() {
    scanf("%d %d",&M,&N);
    memset(arr,1,sizeof(arr));
    arr[1] = 0;
    for(int i=2; i<=N; i++) {
        // 소수를 찾았으면 그것의 배수를 전부 지우기
        if(arr[i]) {
            int num = i;
            int cnt = 2;
            while(num*cnt <= N) {
                arr[num*cnt] = 0;
                cnt += 1;
            }
        }
    }
    for(int i=M; i<=N; i++) {
        if(arr[i]) printf("%d\n",i);
    }
}
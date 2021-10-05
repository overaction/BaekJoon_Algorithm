#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int arr[1000001];
int main() {
    int n;
    memset(arr,1,sizeof(arr));
    arr[1] = 0;
    // 소수 구해놓기
    for(int i=2; i<1000001; i++) {
        if(arr[i]) {
            int num = i;
            int cnt = 2;
            while(num*cnt <= 1000000) {
                arr[num*cnt] = 0;
                cnt++;
            }
        }
    }

    int flag;
    while(1) {
        scanf("%d",&n);
        if(n == 0) exit(0);
        flag = false;
        int a = 3;
        int b = n-3;
        
        while(1) {
            // 두 수가 모두 소수라면 출력
            if(arr[a] && arr[b]) {
                flag = true;
                printf("%d = %d + %d\n",n,a,b);
                break;
            }

            // 두 수가 모두 홀수이기 때문에 +-2
            a+=2, b-=2;
        }
        if(!flag) printf("Goldbach's conjecture is wrong.\n");
    }
}
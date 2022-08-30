#include <iostream>
#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;
int N,K,cnt=0;
int isPrime[1001]; // 1 : 소수, 0 : 합성수
int main()
{
    scanf("%d %d",&N,&K);
    for(int i=2; i<=N; i++) {
        if(isPrime[i] == 0) {
            isPrime[i] = 1;
            cnt++;
            if(cnt == K) {
                printf("%d",i);
                break;
            }
            for(int j=i*i; j<=N; j+=i) {
                if(isPrime[j] == 0) {
                    isPrime[j] = 1;
                    cnt++;
                    if(cnt == K) {
                        printf("%d",j);
                        break;
                    }
                }
            }
        }
    }
}

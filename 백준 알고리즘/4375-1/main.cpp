#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        int num = 0;
        int cnt = 0;
        while(1) {
            // 자리수 추가
            num = num*10 +1;
            // 모듈러 연산을 통해 무한히 커지는걸 방지
            num %= n;
            cnt++;
            if(num == 0) {
                printf("%d\n",cnt);
                break;
            }
        }
    }
}
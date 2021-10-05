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
        // 몇자리수인지 구하기
        for (int i = 1;i<=n; i++) {
            num = num * 10 + 1;
            num %= n;
            if (num == 0) {
                printf("%d\n", i);;
                break;
            }
        }
    }
}
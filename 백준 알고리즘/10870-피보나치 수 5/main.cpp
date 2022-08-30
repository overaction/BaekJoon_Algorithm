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
    scanf("%d",&n);
    int x1 = 0;
    int x2 = 1;
    if(n == 0) printf("0");
    else if(n == 1) printf("1");
    else {
        int sum = 0;
        for(int i=2; i<=n; i++) {
            sum = x1 + x2;
            x1 = x2;
            x2 = sum;
        }
        printf("%d\n",sum);
    }
}
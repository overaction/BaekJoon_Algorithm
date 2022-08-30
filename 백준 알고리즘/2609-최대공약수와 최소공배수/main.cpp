#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int gcd(int num1, int num2) {
    while(num2 > 0) {
        int r = num1%num2;
        num1 = num2;
        num2 = r;
    }
    return num1;
}

int lcm(int num1, int num2, int max) {
    return num1*num2 / max;
}

int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    int maximum = gcd(a,b);
    int minimum = lcm(a,b,maximum);
    printf("%d %d",maximum,minimum);
}
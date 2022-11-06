#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 최대공약수
int GCD(int a, int b) {
    if(a == 0) return b;
    return GCD(b%a,a);
}

// 최소공배수
int LCM(int a, int b) {
    return a*b / GCD(a,b);
}

int solution(vector<int> arr) {
    int now = arr[0];
    for(int i=1; i<arr.size(); i++) {
        now = LCM(now,arr[i]);
    }
    return now;
}
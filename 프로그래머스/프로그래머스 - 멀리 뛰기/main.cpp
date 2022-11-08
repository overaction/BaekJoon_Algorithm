#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long cache[2000];

long long solution(int n) {
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 3;
    for(int i=4; i<=n; i++) {
        cache[i] = (cache[i-1] + cache[i-2]) % 1234567;
    }
    return cache[n];
}
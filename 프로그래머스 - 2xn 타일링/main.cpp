#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cache[60000];

int tiling(int n) {
	int &ret = cache[n];
	if(ret != -1) return ret;

	ret = (tiling(n-2) + tiling(n-1))%1000000007;
	return ret;
}

int solution(int n) {
    int answer = 0;
	for(int i=0; i<=n; i++) cache[i] = -1;
	cache[0] = 0;
	cache[1] = 1;
	cache[2] = 2;
	tiling(n);
	answer = cache[n];
    return answer;
}
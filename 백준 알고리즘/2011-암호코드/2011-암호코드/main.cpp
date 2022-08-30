#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#define MOD 1000000
using namespace std;
int N;
// 각 idx에서 시작해서 만들 수 있는 경우의수
int cache[5001];
// 각 암호 저장
vector < int > v;

/*
    0. 첫 자리가 0이아닌 1의자리 숫자여야 한다
    1. 둘째 자리가 1의자리 숫자인 경우 추가
    2. 첫째 둘째 자리 수가 26 이하인 경우 셋째자리가 1의자리 숫자인 경우 추가
*/
int solution(int start) {
    // 초과 시 경우의수 1 추가
    if(start == v.size()) return 1;
    int &ret = cache[start];
    if(ret != -1) return ret;

    ret = 0;
    if(v[start] != 0) {

        ret += solution(start+1);

        if(v[start]*10 + v[start+1] <= 26)
            ret += solution(start+2);
    }
    return ret % MOD;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        v.push_back(s[i]-48);
    }
    printf("%d\n",solution(0));
}

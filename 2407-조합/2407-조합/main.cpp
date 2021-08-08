#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n,m;
string cache[101][101];

string solution(string n1, string n2) {
    long long sum = 0;
    string ret;

    // 1의자리부터 차례대로 더한다
    while(!n1.empty() || !n2.empty() || sum) {
        if(!n1.empty()) {
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if(!n2.empty()) {
            sum += n2.back() - '0';
            n2.pop_back();
        }
        // 첫 자리수 추가
        ret.push_back((sum%10)+'0');
        // sum이 10 이상이었다면 10의자리 수 이월
        sum = sum / 10;
    }
    // 반대로 넣었기때문에 리버스
    reverse(ret.begin(),ret.end());
    return ret;
}

// nCr = n-1Cr-1 + n-1Cr
string combination(int n, int r) {
    if(n == r || r == 0)
        return "1";
    string &ret = cache[n][r];
    if(ret != "") return ret;

    ret = solution(combination(n-1,r-1),combination(n-1,r));
    return ret;
}

int main()
{
    scanf("%d %d",&n,&m);
    cout << combination(n,m) << endl;
}

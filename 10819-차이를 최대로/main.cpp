#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
using namespace std;
int N, ans = 0;
int A[8];
bool check[8];

void calculate(vector < int > &v) {
    int result = 0;
    for(int i=0; i<v.size()-1; i++) {
        result += abs(v[i]-v[i+1]);
    }
    ans = max(ans,result);
}

void solution(vector < int > &v, int cnt) {
    if(cnt == N) {
        calculate(v);
        return;
    }
    for(int i=0; i<N; i++) {
        if(!check[i]) {
            check[i] = true;
            v.push_back(A[i]);
            solution(v,cnt+1);
            v.pop_back();
            check[i] = false;
        }
    }
}

int main()
{
    scanf("%d",&N);
    vector < int > v;
    for(int i=0; i<N; i++) {
        scanf("%d",&A[i]);
    }
    solution(v,0);
    printf("%d\n",ans);
}

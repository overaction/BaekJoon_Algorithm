#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,K;
vector < int > v;
vector < int > diff;

int solution() {
    if(N <= K) return 0;
    for(int i=0; i<v.size()-1; i++) {
        int dif = v[i+1] - v[i];
        diff.push_back(dif);
    }
    sort(diff.begin(),diff.end());

    int sum = 0;
    for(int i=0; i<diff.size() - (K-1); i++) {
        sum += diff[i];
    }
    return sum;
}

int main()
{
    int num;
    scanf("%d %d",&N,&K);
    for(int i=0; i<N; i++) {
        scanf("%d",&num);
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    printf("%d\n",solution());
}

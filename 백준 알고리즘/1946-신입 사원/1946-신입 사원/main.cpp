#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include <algorithm>
using namespace std;
int T;
int N;
vector <pair<int,int>>v;

int solution() {
    int cnt = 1;
    int minimum_m = v[0].second;
    for(int i=1; i<N; i++) {
        if(minimum_m >= v[i].second) {
            minimum_m = v[i].second;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int a,b;
    scanf("%d",&T);
    for(int i=0; i<T; i++) {
        scanf("%d",&N);
        for(int j=0; j<N; j++) {
            scanf("%d %d",&a,&b);
            v.push_back({a,b});
        }
        sort(v.begin(),v.end());
        printf("%d\n",solution());
        v.clear();
    }
}

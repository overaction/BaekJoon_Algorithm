#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include <algorithm>
using namespace std;
int N;
vector < pair < int,int > > v;

int solution() {
    int cnt = 1;
    int endP = v[0].first;
    for(int i=1; i<N; i++) {
        if(v[i].second < endP) continue;
        cnt++;
        endP = v[i].first;
    }
    return cnt;
}

int main()
{
    int s,e;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d %d",&s,&e);
        v.push_back({e,s});
    }
    // 회의가 일찍 끝나는 순서대로 정렬
    sort(v.begin(),v.end());
    printf("%d",solution());
}

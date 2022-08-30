#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include <algorithm>
using namespace std;
int N;
vector < pair <int,int > > order;
int solution() {
    sort(order.begin(),order.end());
    int temp=0,total=0;
    for(int i=0; i<N; i++) {
        temp += order[i].first;
        total += temp;
    }
    return total;
}

int main()
{
    int num;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&num);
        order.push_back({num,i});
    }
    printf("%d\n",solution());
}

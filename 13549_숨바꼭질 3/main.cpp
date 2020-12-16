#include <iostream>
#include <stdio.h>
#include <string.h>
#include <deque>
using namespace std;
int N,K;
int run[100001];
int dy[3] = {-1,1,2};
deque < pair < int,int > > dq;
int hide(int v) {
    dq.push_back(make_pair(0,v));
    run[v] = 1;
    while(!dq.empty()) {
        int time = dq.front().first;
        int y = dq.front().second;
        dq.pop_front();
        if(y == K) return time;
        if(y+1 <= 100000 && run[y+1] == -1) {
            run[y+1] = 1;
            dq.push_back(make_pair(time+1,y+1));
        }
        if(y-1 >= 0 && run[y-1] == -1) {
            run[y-1] = 1;
            dq.push_back(make_pair(time+1,y-1));
        }
        if(y*2 <= 100000 and run[y*2] == -1) {
            run[y*2] = 1;
            dq.push_front(make_pair(time,y*2));
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d",&N,&K);
    for(int i=0; i<100001; i++)
        run[i] = -1;
    int result = hide(N);
    printf("%d",result);
}

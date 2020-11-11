#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int N,K, time=0;
deque < int > dq;
int visited[100001];

int bfs(int n, int k) {
    dq.push_back(n);
    while(1) {
        int dq_size = dq.size();
        for(int i=0; i<dq_size; i++) {
            int q = dq.front();
            dq.pop_front();
            if(q == k)
                return time;
            if(q+1 <= 100000 && visited[q+1] == 0) {
                visited[q+1] = 1;
                dq.push_back(q+1);
            }
            if(q-1 >= 0 && visited[q-1] == 0) {
                visited[q-1] = 1;
                dq.push_back(q-1);
            }
            if(q*2 <= 100000 && visited[q*2] == 0) {
                visited[q*2] = 1;
                dq.push_back(q*2);
            }
        }
        time++;
    }
}

int main()
{
    scanf("%d %d",&N,&K);
    printf("%d",bfs(N,K));
}

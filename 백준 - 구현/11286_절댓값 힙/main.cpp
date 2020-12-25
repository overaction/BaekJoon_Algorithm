#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
typedef pair <int, int> pi;

int main() {
    int N,x;
    pi temp;
    priority_queue < pi, vector <pi>, greater <pi> > pq;
    scanf("%d",&N);
    for(int i=1; i<=N; i++) {
        scanf("%d",&x);
        if(x == 0) {
            if(pq.empty()) printf("0\n");
            else {
                temp = pq.top();
                printf("%d\n",temp.second);
                pq.pop();
            }
        }
        else {
            pq.push(make_pair(abs(x),x));
        }
    }
}

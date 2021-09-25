#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
int N;
stack < int > st;
vector < int > v;
vector < char > vc;

int solution() {
    int num = 1;
    int idx = 0;
    while(idx < N) {
        if(!st.empty() && st.top() == v[idx]) {
            st.pop();
            idx++;
            vc.push_back('-');
        }
        else if(num <= v[idx]) {
            for(int i=num; i<=v[idx]; i++) {
                st.push(i);
                num++;
                vc.push_back('+');
            }
        }
        else return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&n);
        v.push_back(n);
    }
    int result = solution();
    if(result) {
        for(int i=0; i<vc.size(); i++)
            printf("%c\n",vc[i]);
    }
    else printf("NO");
}
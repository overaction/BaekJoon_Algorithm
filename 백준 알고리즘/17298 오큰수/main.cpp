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
vector < int > v;
stack < int > st;
int answer[1000001];

void solution() {
    for(int i=N-1; i>=0; i--) {
        int now = v[i];
        // stack이 비어있다면 오큰수가 없음
        if(st.empty()) {
            answer[i] = -1;
            st.push(now);
        }
        else {
            while(!st.empty()) {
                if(now < st.top()) {
                    answer[i] = st.top();
                    st.push(now);
                    break;
                }
                else if(now >= st.top()) {
                    st.pop();
                }
            }
            if(st.empty()) {
                answer[i] = -1;
                st.push(now);
            }
        }
    }
}

int main() {
    int num;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&num);
        v.push_back(num);
    }
    solution();
    for(int i=0; i<N; i++)
        printf("%d ",answer[i]);
}
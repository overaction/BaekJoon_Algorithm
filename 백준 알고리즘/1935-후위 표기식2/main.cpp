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
stack < double > st;
vector < int > v;
string s;

void solution() {
    for(int i=0; i<s.size(); i++) {
        char now = s[i];
        if(now != '*' && now != '+' && now != '/' && now != '-') {
            st.push(v[now-65]);
        }
        else {
            if(now == '*') {
                double first = st.top();
                st.pop();
                double second = st.top();
                st.pop();
                st.push(first*second);
            }
            else if(now == '+') {
                double first = st.top();
                st.pop();
                double second = st.top();
                st.pop();
                st.push(first+second);
            }
            else if(now == '/') {
                double first = st.top();
                st.pop();
                double second = st.top();
                st.pop();
                st.push(second/first);
            }
            else if(now == '-') {
                double first = st.top();
                st.pop();
                double second = st.top();
                st.pop();
                st.push(second-first);
            }
        }
    }
    printf("%.2lf\n",st.top());
}

int main() {
    scanf("%d",&N);
    cin >> s;
    int num;
    for(int i=0; i<N; i++) {
        scanf("%d",&num);
        v.push_back(num);
    }
    solution();
}
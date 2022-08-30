#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int M;
stack < char > st;
stack < char > st2;
vector < pair < char,char > > v;

void solution() {
    for(int i=0; i<M; i++) {
        char nowCommand = v[i].first;
        char nowCh = v[i].second;

        if(nowCommand == 'L') {
            if(!st.empty()) {
                st2.push(st.top());
                st.pop();
            }
        }
        else if(nowCommand == 'D') {
            if(!st2.empty()) {
                st.push(st2.top());
                st2.pop();
            }
        }
        else if(nowCommand == 'B') {
            if(!st.empty()) {
                st.pop();
            }
        }
        else {
            st.push(nowCh);
        }
    }
}

int main() {
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++)
        st.push(s[i]);
    scanf("%d",&M);
    char command, ch;
    for(int i=0; i<M; i++) {
        cin >> command;
        if(command == 'P') {
            cin >> ch;
            v.push_back({command, ch});
        }
        else v.push_back({command,'o'});
    }
    solution();
    while(!(st.empty())){
        st2.push(st.top());
        st.pop();
    } 
    while(!(st2.empty())){
        cout << st2.top();
        st2.pop();
    }
}
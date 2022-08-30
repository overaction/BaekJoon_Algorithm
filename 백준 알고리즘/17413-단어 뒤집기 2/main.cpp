#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

stack < char > st;
string s;
vector < char > v;

void solution() {
    for(int i=0; i<s.size(); i++) {
        char now = s[i];
        if(now == ' ') cout << now;
        else if(now == '<') {
            v.push_back(now);
            while(1) {
                i++;
                v.push_back(s[i]);
                if(s[i] == '>') break;
            }
            // vector에 넣은 <> 부분 출력
            for(int j=0; j<v.size(); j++)
                printf("%c",v[j]);
            v.clear();
        }
        else {
            while(i < s.size() && s[i] != '<' && s[i] != ' ') {
                st.push(s[i]);
                i++;
            }
            i--;
            // stack에 넣은 부분 출력
            while(!st.empty()) {
                cout << st.top();
                st.pop();
            }
        }
    }
}

int main() {
    getline(cin,s);
    solution();
}
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int T;

int main()
{
    string s;
    stack < int > st;
    scanf("%d",&T);
    for(int i=0; i<T; i++) {
        cin >> s;
        for(int j=0; j<s.size(); j++) {
            if(s[j] == '(') {
                st.push(s[j]);
            }
            else if(s[j] == ')' && !st.empty() && st.top() == '(') {
                st.pop();
            }
            else {
                st.push(s[j]);
            }
        }
        if(st.empty()) printf("YES\n");
        else printf("NO\n");
        while(!st.empty()) st.pop();
    }
}

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
string s;
stack < char > st;

int solution() {
    int ans = 0;
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '(') st.push(s[i]);
        else {
            st.pop();
            if(s[i-1] == '(') {
                ans += st.size();
            }
            else ans++;
        }
    }
    return ans;
}

int main() {
    cin >> s;
    printf("%d\n",solution());
}
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int L,C;
char strs[16];

void solution(vector <char> &s, int cnt) {
    if(s.size() == L) {
        int cnt1=0,cnt2=0;
        for(int i=0; i<L; i++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') cnt1++;
            else cnt2++;
        }
        if(cnt1 >= 1 && cnt2 >= 2) {
            for(int i=0; i<s.size(); i++) printf("%c",s[i]);
            printf("\n");
        }
        return;
    }
    //
    for(int i=cnt; i<C; i++) {
        s.push_back(strs[i]);
        solution(s,i+1);
        s.pop_back();
    }
}

int main()
{
    scanf("%d %d",&L,&C);
    char c;
    for(int i=0; i<C; i++) {
        scanf(" %c",&strs[i]);
    }
    vector < char > s;
    sort(strs, strs+C);
    solution(s,0);
}

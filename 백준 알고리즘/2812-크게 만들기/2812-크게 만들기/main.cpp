#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,K;
bool checked[500001];
deque < char > dq;
int main()
{
    string s;
    scanf("%d %d",&N,&K);
    cin >> s;

    for(int i=0; i<N; i++) {
        while(!dq.empty() && dq.back() < s[i] && K) {
            K--;
            dq.pop_back();
        }
        dq.push_back(s[i]);
    }
    for(int i=0; i<dq.size()-K; i++)
        cout << dq[i];
}

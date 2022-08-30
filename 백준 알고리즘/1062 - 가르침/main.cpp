#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int N,K;
int result = 0;
bool learned[26];
vector < string > wordV;

void solution(int idx, int cnt) {
    // 배울 단어 다 배움
    if(cnt == K-5) {
        int possible = 0;
        for(int i=0; i<wordV.size(); i++) {
            string now = wordV[i];
            bool flag = true;
            for(int j=0; j<now.length(); j++) {
                if(!learned[now[j] - 'a']) {
                    flag = false;
                    break;
                }
            }
            if(flag) possible++;
        }
        result = (result <= possible) ? possible : result;
    }
    // 모든 알파벳
    for(int i=idx; i<=26; i++) {
        if(!learned[i]) {
            learned[i] = true;
            solution(i,cnt+1);
            learned[i] = false;
        }
    }
}

int main() {
    string word;
    scanf("%d %d",&N,&K);
    // a,n,t,i,c 5개 필수
    if(K < 5) {
        printf("0");
        return 0;
    }
    // 모든 경우의 수 가능
    if(K == 26) {
        printf("%d",N);
        return 0;
    }
    for(int i=0; i<N; i++) {
        cin >> word;
        word = word.substr(4,word.length()-8);
        wordV.push_back(word);
    }
    learned['a'-'a'] = true;
    learned['n'-'a'] = true;
    learned['t'-'a'] = true;
    learned['i'-'a'] = true;
    learned['c'-'a'] = true;

    solution(0,0);
    printf("%d\n",result);
}
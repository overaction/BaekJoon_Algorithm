#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
int N;
int answer = 0;
priority_queue < int > m;
priority_queue < int, vector < int >, greater < int > > p;
int ones = 0;
int zeros = 0;

void solution() {
    // ¾ç¼ö°¡ È¦¼ö°³¶ó¸é 1À» Ãß°¡ÇØ¼­ ±ÕÇü ¸ÂÃçÁÜ
    if(p.size() % 2 == 1)
        p.push(1);
    while(!p.empty()) {
        int a = p.top();
        p.pop();
        int b = p.top();
        p.pop();
        answer += (a*b);
    }

    // È¦¼ö°³¸é 1 Ãß°¡
    if(m.size() % 2 == 1)
        zeros ? m.push(0) : m.push(1);

    while(!m.empty()) {
        int a = m.top();
        m.pop();
        int b = m.top();
        m.pop();
        answer += (a*b);
    }
}

int main()
{
    int num;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&num);
        if(num == 1) ones++;
        else if(num > 0) p.push(num);
        else if(num == 0) zeros++;
        else if(num != 0) m.push(num);
    }
    solution();
    printf("%d\n",answer+ones);
}

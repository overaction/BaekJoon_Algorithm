#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int N,C;
int M;
typedef struct option {
    int starts,ends,box;
}op;

vector < op > v;

int boxes[2001];

bool cmp(const op &a, const op &b) {
    if(a.ends < b.ends) return true;
    else if(a.ends == b.ends) {
        if(a.starts < b.starts) return true;
    }
    return false;
}

int solution() {
    int answer = 0;
    for(int i=0; i<M; i++) {
        int maxCnt = 0;
        // 보내는곳 ~ 받는곳 까지
        for(int j=v[i].starts; j<v[i].ends; j++) {
            maxCnt = max(boxes[j],maxCnt);
        }
        int val = min(v[i].box, C-maxCnt);
        answer += val;

        for(int j=v[i].starts; j<v[i].ends; j++) {
            boxes[j] += val;
        }
    }
    return answer;
}

int main()
{
    int a,b,c;
    scanf("%d %d",&N,&C);
    scanf("%d",&M);
    for(int i=0; i<M; i++) {
        scanf("%d %d %d",&a,&b,&c);
        v.push_back({a,b,c});
    }
    sort(v.begin(),v.end(),cmp);

    printf("%d\n",solution());
}

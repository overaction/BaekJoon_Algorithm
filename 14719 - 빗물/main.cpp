#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

vector < int > v;

int solution(int W) {
    int nowHeight;
    int maxLeft,maxRight;
    int maximum;
    int answer = 0;
    for(int i=1; i<W-1; i++) {
        maxLeft = 0, maxRight = 0;
        nowHeight = v[i];
        // left
        for(int j=0; j<i; j++) {
            maxLeft = (maxLeft < v[j]) ? v[j] : maxLeft;
        }
        // right
        for(int k=i+1; k<W; k++) {
            maxRight = (maxRight < v[k]) ? v[k] : maxRight;
        }
        maximum = (maxLeft <= maxRight) ? maxLeft : maxRight; 
        if(maximum <= nowHeight) continue;
        answer += (maximum - nowHeight);
    }
    return answer;
}

int main() {
    int H,W;
    int height;
    scanf("%d %d",&H,&W);
    for(int i=0; i<W; i++) {
        scanf("%d",&height);
        v.push_back(height);
    }
    printf("%d\n",solution(W));
}
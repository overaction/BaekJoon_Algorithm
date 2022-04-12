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
bool cmp(int a, int b) {
    return a < b;
}

int main() {
    int height;
    int sum = 0;
    for(int i=0; i<9; i++) {
        scanf("%d",&height);
        v.push_back(height);
        sum += height;
    }
    sort(v.begin(),v.end(),cmp);
    int idx1, idx2;
    int check = 0;
    for(int i=0; i<9; i++) {
        for(int j=i+1; j<9; j++) {
            if(sum - v[i] - v[j] == 100) {
                idx1 = i, idx2 = j;
                check = 1;
                break;
            }
        }
        if(check) break;
    }
    for(int i=0; i<9; i++) {
        if(i == idx1 || i == idx2) continue;
        printf("%d\n",v[i]);
    }
}
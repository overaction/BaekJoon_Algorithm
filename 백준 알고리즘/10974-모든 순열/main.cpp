#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
int N;
bool check[8];

void printR(vector < int > &v) {
    for(int i=0; i<v.size(); i++) {
        printf("%d ",v[i]);
    }
    printf("\n");
}

void solution(vector < int > &v, int cnt) {
    if(cnt == N)
        printR(v);

    for(int i=0; i<N; i++) {
        if(!check[i]) {
            check[i] = true;
            v.push_back(i+1);
            solution(v,cnt+1);
            v.pop_back();
            check[i] = false;
        }
    }
}

int main()
{
    vector <int> v;
    scanf("%d",&N);
    solution(v,0);
}

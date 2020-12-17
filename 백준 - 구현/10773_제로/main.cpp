#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
vector < int > v;
int K;

int main()
{
    int num,sum=0;
    scanf("%d",&K);
    for(int i=1; i<=K; i++) {
        scanf("%d",&num);
        if(num)
            v.push_back(num);
        else
            v.pop_back();
    }
    for(int i=0; i<v.size(); i++)
        sum += v[i];
    printf("%d",sum);
}

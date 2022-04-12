#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int max = 0;
    int in,out;
    int next = 0;
    for(int i=0; i<10; i++) {
        scanf("%d %d",&out,&in);
        next = next + in - out;
        max = (max < next) ? next : max;
    }
    printf("%d",max);
}
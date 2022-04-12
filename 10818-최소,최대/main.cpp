#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
#define MIN -1000000;
#define MAX 1000000;

int main() {
    int N,num;
    int min = MAX;
    int max = MIN;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&num);
        min = (num < min) ? num : min;
        max = (num > max) ? num : max;
    }

    printf("%d %d",min,max);
}

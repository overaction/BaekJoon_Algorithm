#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

int solution(int arr[]) {
    int tmp;
    for(int i=0; i<9; i++) {
        for(int j=i+1; j<10; j++) {
            if(arr[j] < arr[i]) {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            } 
        }
    }
    return arr[7];
}

int main() {
    int T,num;
    int arr[10];
    scanf("%d",&T);
    for(int t=0; t<T; t++) {
        for(int i=0; i<10; i++) {
            scanf("%d",&arr[i]);
        }
        printf("%d\n",solution(arr));
    }
}
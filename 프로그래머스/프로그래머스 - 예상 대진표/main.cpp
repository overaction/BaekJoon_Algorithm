#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int n, int a, int b)
{
    for(int i=0; i<n; i++) {
        if(a % 2 == 1) a++;
        if(b % 2 == 1) b++;
        a = a/2;
        b = b/2;

        if(a == b) return i+1;
    }
}
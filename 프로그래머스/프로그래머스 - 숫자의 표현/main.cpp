#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    int sum = 0, j = 1;
    for(int i=1; i<=(n+1)/2; i++) {
        sum += i;
        if(sum >= n) {
            while(sum > n) sum -= j++;
            if(sum == n) answer++;
        }
    }
    return (n == 1) ? 1 : answer+1;
}

int main() {
    printf("%d\n",solution(15));
}
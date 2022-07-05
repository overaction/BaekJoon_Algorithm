#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long gcd(int a, int b) {
    long long c;
    while(b != 0) {
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w,int h) {
    // 미리 long long형으로 바꿔서 저장해줘야 한다
    long long W = w;
    long long H = h;
    long long gcdResult = gcd(w,h);
    long long answer = W*H - (w+h-gcdResult);
    return answer;
}

int main() {
    long long int a = 100000000;
    long long int b = 100000000;
    long long answer = a*b;
    printf("%lld\n",answer); 
}
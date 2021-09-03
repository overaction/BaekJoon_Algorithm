#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
string S,T;

int solution() {
    while(1) {
        // 기저사례
        if(S.length() == T.length()) {
            if(S == T) return 1;
            else return 0;
        }

        // 맨 뒤가 A인경우 제거
        if(T.back() == 'A')
            T.pop_back();
        // B인경우 제거하고 뒤집기
        else if(T.back() == 'B') {
            T.pop_back();
            reverse(T.begin(),T.end());
        }
        cout << T <<endl;
    }
}
int main()
{

    cin >> S;
    cin >> T;
    printf("%d\n",solution());
}

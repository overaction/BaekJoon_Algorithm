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
        // �������
        if(S.length() == T.length()) {
            if(S == T) return 1;
            else return 0;
        }

        // �� �ڰ� A�ΰ�� ����
        if(T.back() == 'A')
            T.pop_back();
        // B�ΰ�� �����ϰ� ������
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

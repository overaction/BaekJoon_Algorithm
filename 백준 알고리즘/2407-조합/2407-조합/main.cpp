#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n,m;
string cache[101][101];

string solution(string n1, string n2) {
    long long sum = 0;
    string ret;

    // 1���ڸ����� ���ʴ�� ���Ѵ�
    while(!n1.empty() || !n2.empty() || sum) {
        if(!n1.empty()) {
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if(!n2.empty()) {
            sum += n2.back() - '0';
            n2.pop_back();
        }
        // ù �ڸ��� �߰�
        ret.push_back((sum%10)+'0');
        // sum�� 10 �̻��̾��ٸ� 10���ڸ� �� �̿�
        sum = sum / 10;
    }
    // �ݴ�� �־��⶧���� ������
    reverse(ret.begin(),ret.end());
    return ret;
}

// nCr = n-1Cr-1 + n-1Cr
string combination(int n, int r) {
    if(n == r || r == 0)
        return "1";
    string &ret = cache[n][r];
    if(ret != "") return ret;

    ret = solution(combination(n-1,r-1),combination(n-1,r));
    return ret;
}

int main()
{
    scanf("%d %d",&n,&m);
    cout << combination(n,m) << endl;
}

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#define MOD 1000000
using namespace std;
int N;
// �� idx���� �����ؼ� ���� �� �ִ� ����Ǽ�
int cache[5001];
// �� ��ȣ ����
vector < int > v;

/*
    0. ù �ڸ��� 0�̾ƴ� 1���ڸ� ���ڿ��� �Ѵ�
    1. ��° �ڸ��� 1���ڸ� ������ ��� �߰�
    2. ù° ��° �ڸ� ���� 26 ������ ��� ��°�ڸ��� 1���ڸ� ������ ��� �߰�
*/
int solution(int start) {
    // �ʰ� �� ����Ǽ� 1 �߰�
    if(start == v.size()) return 1;
    int &ret = cache[start];
    if(ret != -1) return ret;

    ret = 0;
    if(v[start] != 0) {

        ret += solution(start+1);

        if(v[start]*10 + v[start+1] <= 26)
            ret += solution(start+2);
    }
    return ret % MOD;
}

int main()
{
    memset(cache,-1,sizeof(cache));
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++) {
        v.push_back(s[i]-48);
    }
    printf("%d\n",solution(0));
}

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int answer = 0;
int N;
// �� �ܾ� ����
vector < string > word;
// ���Ǵ� ���ĺ� ����
vector < char > type;
int alpha[26];

// ���ĺ����� ũ�� ����
vector < int > alphaSize;
int check[10];

void calculate() {
    int result = 0;
    int usedAlphaNum[26];
    // ����� ���ĺ��� ũ�� ����
    for(int i=0; i<type.size(); i++) {
        char c = type[i];
        int num = c - 'A';
        usedAlphaNum[num] = alphaSize[i];
    }
    // �� �ܾ�� ũ�� ���
    for(int i=0; i<word.size(); i++) {
        int temp = 0;
        for(int j=0; j<word[i].size(); j++) {
            temp *= 10;
            temp += usedAlphaNum[word[i][j] - 'A'];
        }
        result += temp;
    }
    answer = max(result,answer);
}

void solution(int cnt) {
    // �� ���ĺ����� ũ�Ⱑ �������ٸ� ����
    if(cnt == type.size()) {
        calculate();
        return;
    }
    // ���� ū ���ڵ�θ� �����ϵ��� �Ѵ�
    for(int i=10-type.size(); i<10; i++) {
        if(check[i] == 0) {
            check[i] = 1;
            alphaSize.push_back(i);
            solution(cnt+1);
            check[i] = 0;
            alphaSize.pop_back();
        }
    }
}

int main()
{
    scanf("%d",&N);
    string s;
    for(int i=0; i<N; i++) {
        cin >> s;
        word.push_back(s);
        for(int j=0; j<s.size(); j++) {
            int num = s.at(j) - 'A';
            // ���� ���ĺ� ������ üũ�Ѵ�
            if(alpha[num] == 0) {
                alpha[num] = 1;
                type.push_back(s.at(j));
            }
        }
    }
    solution(0);
    printf("%d\n",answer);
}

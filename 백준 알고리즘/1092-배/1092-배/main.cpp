#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector < int > crain;
vector < int > box;
int answer = 0;

void solution() {
    // �� ���� �� ���°��
    if(crain[0] < box[0])
        return;
    // �ڽ��� ���� ���������� �ݺ�
    while(!box.empty()) {
        int crainIdx = 0;
        for(int i=0; i<box.size(); i++) {
            // ũ���� ��ȸ�� ��ħ
            if(crainIdx == crain.size())
                break;
            // ���� ũ������ �ڽ��� �� �� �ִ�
            if(crain[crainIdx] > box[i]) {
                crainIdx++;
                box.erase(box.begin() + i);
                i -= 1;
            }
        }
        answer++;
    }
}

int main()
{
    int num;
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d",&num);
        crain.push_back(num);
    }
    scanf("%d",&M);
    for(int i=0; i<M; i++) {
        scanf("%d",&num);
        box.push_back(num);
    }
    // �������� ����
    sort(crain.begin(),crain.end(), greater<int>());
    sort(box.begin(),box.end(),greater<int>());

    solution();
    printf("%d",answer);
}

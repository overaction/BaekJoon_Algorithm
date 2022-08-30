#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int g,p;
// �� ��帶�� ��Ʈ���� ����
int gate[100001];
bool checked[100001];

int finding(int x) {
    if(x == gate[x]) return x;
    gate[x] = finding(gate[x]);
    return gate[x];
}

void unioning(int a, int b) {
    a = finding(a);
    b = finding(b);
    // ��Ʈ�� ���ٸ� �׳� ����
    if(a == b) return;
    // �ƴ϶�� ��ħ
    gate[a] = b;
}

int main()
{
    int gt;
    int cnt = 0;
    scanf("%d %d",&g,&p);

    // ó���� �ڱ� �ڽ��� �θ� ����� ������ ����
    for(int i=0; i<=g; i++) gate[i] = i;

    for(int i=0; i<p; i++) {
        scanf("%d",&gt);

        int parent = finding(gt);
        // ��ŷ ������ ����Ʈ�� ����
        if(parent == 0)
            break;
        else {
            cnt++;
            unioning(parent, parent-1);
        }
    }
    printf("%d\n",cnt);
}

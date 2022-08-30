#include <iostream>
#include <set>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N,K;
int order[101];
int plug[101];

void solution() {
    int answer = 0;
    for(int i=0; i<K; i++) {
        // �̹� �����ֳ� Ȯ��
        bool isPlug = false;
        for(int j=0; j<N; j++) {
            if(plug[j] == order[i]) {
                isPlug = true;
                break;
            }
        }
        // �����ִٸ� ����ؼ� Ž��
        if(isPlug) continue;

        // ����� Ž��
        for(int j=0; j<N; j++) {
            // ����� �߰�
            if(plug[j] == 0) {
                isPlug = true;
                plug[j] = order[i];
                break;
            }
        }
        if(isPlug) continue;

        // ������� ������� �����ִ� ��� ��
        // ������ ������ �ʴ� ��� �Ǵ� ���� ���߿� ���� ��� Ž��
        int unplugIdx = -1;
        int idx = 0;
        bool unplagPossible = false;
        for(int j=0; j<N; j++) {
            int lastIdx = 0;
            for(int k=i+1; k<K; k++) {
                // �󸶳� ���߿� ������ Ȯ��
                if(plug[j] == order[k]) {
                    lastIdx = k;
                    unplagPossible = true;
                    break;
                }
            }
            // ���߿� ������ ����
            if(unplagPossible == false) {
                plug[j] = order[i];
                answer++;
                break;
            }
            // ���� ���߿� ���Ǵ°� ������Ʈ
            if(lastIdx > unplugIdx) {
                unplugIdx = lastIdx;
                idx = j;
            }
        }
        if(unplagPossible) {
            plug[idx] = order[unplugIdx];
            answer++;
        }
    }
    printf("%d\n",answer);
}

int main()
{
    int a;
    scanf("%d %d",&N,&K);
    for(int i=0; i<K; i++) {
        scanf("%d",&order[i]);
    }
    solution();
}

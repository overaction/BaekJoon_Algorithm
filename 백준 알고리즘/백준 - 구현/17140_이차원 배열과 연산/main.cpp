#include <iostream>
#include <stdio.h>
#include <deque>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
int r,c,k;
int time = 0;
int Arr[101][101];
int number_cnt[101];
int row = 3, column = 3; // ��(����) ��(����)
void print() {
    for(int i=1; i<=10; i++) {
        for(int j=1; j<=10; j++) {
            printf("%d ",Arr[i][j]);
        }
        printf("\n");
    }
    printf("#######################\n");
}
int main()
{
    scanf("%d %d %d",&r,&c,&k);
    for(int i=1; i<=3; i++) {
        for(int j=1; j<=3; j++) {
            scanf("%d",&Arr[i][j]);
        }
    }
    while(1) {
        if(time > 100 || Arr[r][c] == k) break;
        time++;
        int maximum = 0;
        if(row >= column) {
            for(int i=1; i<=row; i++) {
                vector < pair <int,int > > v;
                memset(number_cnt,0,sizeof(number_cnt));
                // ���� �ľ�
                for(int j=1; j<=column; j++) number_cnt[Arr[i][j]]++;
                // vector�� ����,���� ������ ����
                for(int j=1; j<=100; j++)
                    if(number_cnt[j] > 0) v.push_back({number_cnt[j],j});
                // ����
                sort(v.begin(),v.end());
                // �̸� 0���� �ʱ�ȭ
                for(int j=1; j<=column; j++) Arr[i][j] = 0;
                int idx = 1;
                for(int j=0; j<v.size(); j++) {
                    Arr[i][idx++] = v[j].second;
                    Arr[i][idx++] = v[j].first;
                }
                maximum = max(idx-1,maximum);
            }
            column = maximum;
        }
        else {
            for(int i=1; i<=column; i++) {
                vector < pair <int,int > > v;
                memset(number_cnt,0,sizeof(number_cnt));
                // ���� �ľ�
                for(int j=1; j<=row; j++) number_cnt[Arr[j][i]]++;
                // vector�� ����,���� ������ ����
                for(int j=1; j<=100; j++)
                    if(number_cnt[j] > 0) v.push_back({number_cnt[j],j});
                // ����
                sort(v.begin(),v.end());
                for(int j=1; j<=row; j++) Arr[j][i] = 0;
                int idx = 1;
                for(int j=0; j<v.size(); j++) {
                    Arr[idx++][i] = v[j].second;
                    Arr[idx++][i] = v[j].first;
                }
                maximum = max(idx-1,maximum);
            }
            row = maximum;
        }
    }
    (time > 100) ? printf("-1") : printf("%d",time);
}

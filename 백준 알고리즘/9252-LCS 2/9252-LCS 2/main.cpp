#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
string A,B;
int cache[1001][1001];
string result;

// idxA idxB���� �����ϴ� �ִ� ����κм��� ���� ��ȯ
int solution(int idxA, int idxB) {
    if(idxA == A.size() || idxB == B.size()) return 0;
    int &ret = cache[idxA][idxB];
    if(ret != -1) return ret;

    ret = 0;
    ret = max(solution(idxA+1,idxB),solution(idxA,idxB+1));
    ret = max(ret,solution(idxA+1,idxB+1)+(A[idxA] == B[idxB]));
    return ret;
}

void reconstruct(int idxA, int idxB) {
    if(idxA == A.size() || idxB == B.size()) return;
    // ���ڰ� ������ �߰�
    if(A[idxA] == B[idxB]) {
        result += A[idxA];
        reconstruct(idxA+1,idxB+1);
    }
    // �ƴ϶�� �� ū ������ �̵�
    else {
        if(cache[idxA+1][idxB] > cache[idxA][idxB+1])
            reconstruct(idxA+1,idxB);
        else
            reconstruct(idxA,idxB+1);
    }
}

int main()
{
    memset(cache,-1,sizeof(cache));
    cin >> A >> B;
    printf("%d\n",solution(0,0));
    reconstruct(0,0);
    cout << result << endl;
}

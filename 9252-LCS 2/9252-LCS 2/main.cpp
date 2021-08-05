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

// idxA idxB에서 시작하는 최대 공통부분수열 길이 반환
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
    // 문자가 같으면 추가
    if(A[idxA] == B[idxB]) {
        result += A[idxA];
        reconstruct(idxA+1,idxB+1);
    }
    // 아니라면 더 큰 쪽으로 이동
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

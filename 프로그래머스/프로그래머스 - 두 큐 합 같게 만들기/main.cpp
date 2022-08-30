#include <string>
#include <vector>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
	long long hap1 = 0, hap2 = 0;
	int idx1 = 0, idx2 = 0;
	int maxIdx = queue1.size() + queue2.size();
	for(int i=0; i<queue1.size(); i++) hap1 += queue1[i];
	for(int i=0; i<queue2.size(); i++) hap2 += queue2[i];

	while(idx1 < maxIdx && idx2 < maxIdx) {
		if(hap1 == hap2) return answer;
		if(hap1 < hap2) {
			queue1.push_back(queue2[idx2]);
			hap1 += queue2[idx2];
			hap2 -= queue2[idx2];
			idx2++;
		}
		else {
			queue2.push_back(queue1[idx1]);
			hap2 += queue1[idx1];
			hap1 -= queue1[idx1];
			idx1++;
		}
		answer++;
	}
    return -1;
}
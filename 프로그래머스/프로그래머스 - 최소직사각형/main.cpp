#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
	int maxW = 0, maxH = 0;
	for(int i=0; i<sizes.size(); i++) {
		if(sizes[i][0] >= sizes[i][1]) {
			maxW = (maxW > sizes[i][0]) ? maxW : sizes[i][0];
			maxH = (maxH > sizes[i][1]) ? maxH : sizes[i][1];
		}
		else {
			maxW = (maxW > sizes[i][1]) ? maxW : sizes[i][1];
			maxH = (maxH > sizes[i][0]) ? maxH : sizes[i][0];
		}
	}
	answer = maxW*maxH;
    return answer;
}
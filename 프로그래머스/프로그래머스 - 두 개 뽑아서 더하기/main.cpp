#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

vector <int> answer;
unordered_set <int> us;
bool checked[100];
vector <int> v;

void comb(int idx, int cnt, int res, vector<int> numbers) {
	if(cnt == 2) {
		us.insert(res);
		return;
	}
	for(int i=idx; i<numbers.size(); i++) {
		if(checked[i] == 0) {
			checked[i] = 1;
			res += numbers[i];
			comb(i,cnt+1,res,numbers);
			res -= numbers[i];
			checked[i] = 0;
		}
	}
}

vector<int> solution(vector<int> numbers) {
	comb(0,0,0,numbers);
	for(auto itr = us.begin(); itr != us.end(); itr++) {
		answer.push_back(*itr);
	}
    sort(answer.begin(), answer.end());
	return answer;
}
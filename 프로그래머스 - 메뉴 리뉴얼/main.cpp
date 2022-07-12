#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool check[10];
map < string, int > ordersMap;

// 조합 
void comb(string s, int idx, int cnt, string result, int size) {
	if(cnt == size) {
		ordersMap[result]++;
		return;
	}
	for(int i=idx; i<s.size(); i++) {
		if(check[i] == 0) {
			check[i] = 1;
			result += s[i];
			comb(s,i,cnt+1,result,size);
			result.pop_back();
			check[i] = 0;
		}
	}
}

bool cmp(pair<int,string> a, pair<int,string> b) {
	return a.first > b.first;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
	// 주문으로 만들 수 있는 모든 조합을 찾는다.
	for(string order:orders) {
		sort(order.begin(), order.end());
		for(int i=0; i<course.size(); i++) {
			comb(order,0,0,"",course[i]);
		}
	}

	vector < pair <int, string> > sortV;
	for(auto item:ordersMap) {
		if(item.second >= 2) sortV.push_back({item.second, item.first});
	}
	// 주문 횟수로 내림차순 정렬
	sort(sortV.begin(),sortV.end(),cmp);

	for(int i=0; i<course.size(); i++) {
		int maxCnt = 0;
		for(int j=0; j<sortV.size(); j++) {
			string food = sortV[j].second;
			// 크기가 같은 주문에 대해서만 체크
			if(course[i] != food.size()) continue;
			// 가장 많이 주문한 주문 저장
			if(maxCnt == 0) {
				answer.push_back(sortV[j].second);
				maxCnt = sortV[j].first;
			}
			// 가장 많은 주문횟수가 또 있다면 저장
			else if(maxCnt == sortV[j].first) answer.push_back(sortV[j].second);
			// 그 이후는 고려하지 않음
			else break;
		}
	}
	sort(answer.begin(),answer.end());
    return answer;
}

int main() {
	vector <string> test;
	string s = "EBCAD";
	comb(s,0,0,"",2);
}
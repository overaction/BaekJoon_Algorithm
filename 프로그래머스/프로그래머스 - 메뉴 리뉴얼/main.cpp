#include <iostream>
#include <vector>
using namespace std;

vector <int> answer;
bool selected[10];

void printAnswer() {
	for(int i=0; i<answer.size(); i++) printf("%d ",answer[i]);
	printf("\n");
}

// 파라미터 차례로 "원본 배열" / "현재 인덱스" / "선택한 개수" / "선택할 개수" 
void solution(vector <int> &v, int idx, int cnt, int size) {
	// 원하는 개수가 선택되었으면 출력
	if(cnt == size) {
		printAnswer();
		return;
	}
	for(int i=idx; i<v.size(); i++) {
		// 선택된적 없는 숫자라면 저장 후 재귀호출
		if(selected[i] == false) {
			selected[i] = true;
			answer.push_back(v[i]);
			solution(v,i+1,cnt+1,size);
			answer.pop_back();
			selected[i] = false;
		}
	}
}

int main() {
	vector <int> test;
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);

	// 4개중에 3개 고르기
	solution(test,0,0,3);
}
#include <iostream>
using namespace std;
#include <vector>

bool checked[7];
int originalNum;
int num,maximum = 0;
int nums[7];
bool isAns = false;
vector < int > v;

void solution(int cnt) {
	if (cnt == maximum) {
		int now = 0, count = 1;
		for (int i = 0; i < maximum; i++) {
			now += v[i] * count;
			count *= 10;
		}
		if (now > originalNum && now % originalNum == 0) isAns = true;
		return;
	}
	for (int i = 0; i < maximum; i++) {
		if (checked[i] == false) {
			checked[i] = true;
			v.push_back(nums[i]);
			solution(cnt + 1);
			v.pop_back();
			checked[i] = false;
		}
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &num);
		originalNum = num;
		while (num != 0) {
			nums[maximum] = num % 10;
			num = num / 10;
			maximum++;
		}
		solution(0);
		if (isAns) printf("#%d possible\n", i + 1);
		else printf("#%d impossible\n", i + 1);
		maximum = 0;
		isAns = false;
	}
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int checking(char c) {
	if(c >= 'a' && c <= 'z') return 1;
	if(c >= 'A' && c <= 'Z') return 2;
	return 0;
}

int solution(string str1, string str2) {
    int answer = 0;
	// str1, str2 문자 조합 당 개수
	unordered_map <string,int> mapA,mapB;
	// 만들 수 있는 전체 문자 조합
	vector < string > strV;

	// str1, str2 각각 조합 시작
	string temp;
	for(int i=0; i<str1.size()-1; i++) {
		temp = "";
		if(checking(str1[i]) == 1) temp += str1[i];
		else if(checking(str1[i]) == 2) temp += str1[i]+32;
		else continue;

		if(checking(str1[i+1]) == 1) temp += str1[i+1];
		else if(checking(str1[i+1]) == 2) temp += str1[i+1]+32;
		else continue;

		if(mapA[temp] == 0) strV.push_back(temp);
		mapA[temp]++;
		cout << temp << endl;
	}
	for(int i=0; i<str2.size()-1; i++) {
		temp = "";
		if(checking(str2[i]) == 1) temp += str2[i];
		else if(checking(str2[i]) == 2) temp += str2[i]-32;
		else continue;

		if(checking(str2[i+1]) == 1) temp += str2[i+1];
		else if(checking(str2[i+1]) == 2) temp += str2[i+1]-32;
		else continue;

		if(mapA[temp] == 0 && mapB[temp] == 0) strV.push_back(temp);
		mapB[temp]++;
		cout << temp << endl;
	}
	// A, B 둘다 공집합일 경우
	if(strV.size() == 0) return 65536;
	// 자카드 유사도 찾기 A U B = A + B - 교집합(A,B)
	int hap = 0;
	int min = 0;
	// 전체, 교집합 찾기
	for(int i=0; i<strV.size(); i++) {
		string now = strV[i];
		min += (mapA[now] >= mapB[now]) ? mapB[now] : mapA[now];
		hap += (mapA[now] <= mapB[now]) ? mapB[now] : mapA[now];
	}
	printf("%d %d\n",hap,min);
	double res = (double)min / hap;
	res *= 65536;
	answer = (int)res;
    return answer;
}

int main() {
	solution("FRANCE","french");
}
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
	unordered_map <string,int> hashMap;
	for(int i=0; i<phone_book.size(); i++) {
		hashMap[phone_book[i]] = 1;
	}
	for(int i=0; i<phone_book.size(); i++) {
		string number = "";
		for(int j=0; j<phone_book[i].size(); j++) {
			number += phone_book[i][j];
			if(hashMap[number] && number != phone_book[i]) return false;
		}
	}
    return answer;
}
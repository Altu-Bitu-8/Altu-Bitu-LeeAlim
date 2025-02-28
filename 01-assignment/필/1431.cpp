#include <iostream>
#include <set>
#include <string>
using namespace std;

void gen_sub(const string& S, set<string>& st) {//부분 문자열을 생성
	for (int i = 0; i < S.length(); i++) {
		for (int k = 1; k <= S.length() - i; k++) {
			st.insert(S.substr(i, k));
		}
	}


}
int main() {
	string S;
	cin >> S;

	set<string> st;

	gen_sub(S, st);
	cout << st.size();//st1에 담은 문자열의 개수


	return 0;
}

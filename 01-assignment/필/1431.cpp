#include <iostream>
#include <set>
#include <string>
using namespace std;

void gen_sub(const string& S, set<string>& st) {//�κ� ���ڿ��� ����
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
	cout << st.size();//st1�� ���� ���ڿ��� ����


	return 0;
}

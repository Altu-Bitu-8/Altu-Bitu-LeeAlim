#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct guitar { // 기타 구조체
	string serial;
};

//길이가 같을 때 자리수 더하는 함수
int sum_cal(const string& s) {
	int sum = 0;
	for (char c : s) {
		if (isdigit(c)) {
			sum = sum + c - '0';//아스키코드에서 진짜 수 가져오려고
		}
	}
	return sum;
}
// 비교 함수
bool cmpSer(const guitar& g1, const guitar& g2) {
	if (g1.serial.length() != g2.serial.length()) {//길이 비교
		return g1.serial.length() < g2.serial.length();//<는 길이가 짧은거부터 오도록 정렬
	}
	int sum1, sum2;
	sum1 = sum_cal(g1.serial);
	sum2 = sum_cal(g2.serial);
	if (sum1 != sum2) {
		return sum1 < sum2;//작은거부터 오도록 정렬
	}
	return g1.serial < g2.serial;//사전순


}

int main()
{
	int N;

	cin >> N;

	vector<guitar> guitars(N);
	for (int i = 0; i < N; i++) {
		cin >> guitars[i].serial;
	}//시리얼 번호 입력 받기

	sort(guitars.begin(), guitars.end(), cmpSer);

	//정렬된거 다시 출력
	for (const guitar& g : guitars) {
		cout << g.serial << '\n';
	}

	return 0;
}

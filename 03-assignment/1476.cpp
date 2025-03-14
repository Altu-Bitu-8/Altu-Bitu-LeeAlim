#include <iostream>

using namespace std;
int date(int E, int S, int M) {
	int year=1;

	//모듈러 사용 힌트로 모듈러 사용했습니다!
	while (true)
	{
		if ((year - E) % 15 == 0 && (year - S) % 28 == 0 && (year - M) % 19 == 0) {
			break; //최소공배수 개념을 사용했고 E S M을 나머지처럼 생각해서 뺐습니다!
		}
		year++;//만족못하면 1더해서 될때까지 while문돌리기
	}

		return year;

}

int main() {
	int E, S, M;
	cin >> E >> S >> M;
	cout << date(E,S,M);
}
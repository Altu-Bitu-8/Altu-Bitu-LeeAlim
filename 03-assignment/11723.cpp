#include <iostream>
#include <string>

using namespace std;
//비트마스킹

//S &= ~(1 << x); 제거하는 부분이 어려워서 perplexity 사용했습니다
//~는 비트를 반전시킴 따라서 x번째 비트를 1로 만든 것에 ~적용하면 제거하는 기능을 만들 수 있음


int main() {

	ios_base::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);
	int S = 0;
	int x;
	int M = 0;
	string ins;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> ins;


		if (ins == "add") {
			cin >> x;
			S |= (1 << x);
		}

		if (ins == "remove") {
			cin >> x;
			S &= ~(1 << x);//perplexity 사용
		}

		if (ins == "check") {
			cin >> x;
			if (S & (1 << x)) {
				cout << '1' << "\n";
			}
			else if (S ^ (1 << x))
				cout << '0' << "\n";
		}

		if (ins == "toggle") {
			cin >> x;
			if (S & (1 << x)) {
				S &= ~(1 << x);//perplexity 사용
			}
			else
				S |= (1 << x);

		}

		if (ins == "all") {
			for (int i = 1; i <= 20; i++) {
				S ^= (1 << i);
			}
		}

		if (ins == "empty") {
			S = 0;
		}

	}
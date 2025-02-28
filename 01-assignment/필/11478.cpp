#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct guitar { // ��Ÿ ����ü
	string serial;
};

//���̰� ���� �� �ڸ��� ���ϴ� �Լ�
int sum_cal(const string& s) {
	int sum = 0;
	for (char c : s) {
		if (isdigit(c)) {
			sum = sum + c - '0';//�ƽ�Ű�ڵ忡�� ��¥ �� ����������
		}
	}
	return sum;
}
// �� �Լ�
bool cmpSer(const guitar& g1, const guitar& g2) {
	if (g1.serial.length() != g2.serial.length()) {//���� ��
		return g1.serial.length() < g2.serial.length();//<�� ���̰� ª���ź��� ������ ����
	}
	int sum1, sum2;
	sum1 = sum_cal(g1.serial);
	sum2 = sum_cal(g2.serial);
	if (sum1 != sum2) {
		return sum1 < sum2;//�����ź��� ������ ����
	}
	return g1.serial < g2.serial;//������


}

int main()
{
	int N;

	cin >> N;

	vector<guitar> guitars(N);
	for (int i = 0; i < N; i++) {
		cin >> guitars[i].serial;
	}//�ø��� ��ȣ �Է� �ޱ�

	sort(guitars.begin(), guitars.end(), cmpSer);

	//���ĵȰ� �ٽ� ���
	for (const guitar& g : guitars) {
		cout << g.serial << '\n';
	}

	return 0;
}

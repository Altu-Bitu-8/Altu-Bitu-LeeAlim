#include <iostream> // 입출력 헤더
#include <tuple> // tuple 사용 튜플)) 순서가 있는 불변의 컬렉션, 함수에서 여러 값을 반환할 때 사용  
#include <cmath> //abs 함수를 위한 헤더
using namespace std; //표준 네임스페이스 사용
tuple<int, int, int> diet(int w0, int i0, int i, int a, int d, int t) {
    // w: 몸무게, m: 기초대사량
    int w1 = w0, m1 = i0; // 기초대사량 변화 고려 X하고 초기화
    int w2 = w0, m2 = i0; // 기초대사량 변화 고려 O하고 초기화

    while (d--) { //다이어트 기간 내내 반복하도록 d--
        // 체중 += 일일 에너지 섭취량 - 일일 에너지 소비량
        // 일일 에너지 소비량 = 일일 기초 대사량 + 일일 활동 대사량
        w1 += i - (m1 + a);
        w2 += i - (m2 + a);

        // 일일 기초대사량 변화 (m2만 변화)
        // 변화 고려 o
        if (abs(i - (m2 + a)) > t) {
            // [주의] 음수의 나눗셈에 주의: ⌊−5 / 2⌋를 수행하면 3이 나와야 하지만
            //                              C++에서 int i = (-5) / 2를 수행할 경우 -2가 나옴
            //                              => float끼리의 나눗셈으로 수행하고 소숫점 버림
            m2 += float(i - (m2 + a)) / 2.0;
        }
    }
    return { w1, w2, m2 };//결과 반환 : 기초대사량 변화 고려하지 않은 체중, 고려한 체중, 변화된 기초대사량
}
int main() {
    int w0, i0, i, a; // 초기 체중, 초기 기초대사량, 일일 섭취한 칼로리, 일일 활동한 칼로리
    int d, t; // 다이어트 기간, 기초대사량 변화 역치
    
    cin >> w0 >> i0 >> t;//초기 체중, 초기 기초대사량, 변화 역치 입력받기
    cin >> d >> i >> a; // 다이어트 기간, 일일 섭취한 칼로리, 일일 활동한 칼로리 입력받기

    tuple<int, int, int> tmp = diet(w0, i0, i, a, d, t);
    int w1 = get<0>(tmp), m1 = i0;          // 기초대사량 변화 고려 X
    int w2 = get<1>(tmp), m2 = get<2>(tmp); // 기초대사량 변화 고려 O 
    //기초대사량 변화 고려한 결과 출력
    if (w1 <= 0) {
        // m1은 i0에서 변화하지 않고, i0는 0보다 크므로 기초대사량이 0kcal 이하가 되지 않음
        cout << "Danger Diet\n";//체중이 0이하가 되면 danger diet 출력
    }
    else {
        cout << w1 << " " << m1 << "\n";
    }
    //기초대사량의 변화를 고려한 결과 출력
    if (w2 <= 0 || m2 <= 0) {
        cout << "Danger Diet";//체중이나 기초대사량이 0이하가 되면 danger diet 출력
    }
    else {
        cout << w2 << " " << m2 << " "; //최종 체중과 변화된 기초대사량 출력
        if (m2 < i0) {
            cout << "YOYO";//기초대사량이 감소했으면 요요 있음
        }
        else {
            cout << "NO"; //기초대사량이 유지되거나 증가했으면 요요 없음
        }
    }
    return 0;
}
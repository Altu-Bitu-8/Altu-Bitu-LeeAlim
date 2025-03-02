#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

/**
 * [HINT]
 * 주어지는 a와 b는 0보다 크고 10의 100승보다 작은 정수로,
 * C++에서 사용할 수 있는 정수 자료형의 크기를 벗어나요.
 * 어떻게 하면 바로 a+b를 더하지 않는 방법으로, 그 결과를 구할 수 있을까요?
 */

void printResult(stack<int> result) {
    while (!result.empty()) {//비어있는지 확인
        cout << result.top();//스택의 top 출력
        result.pop();//출력하고는 top pop으로 꺼내기
    }
    cout << '\n';//줄바꿈
}

int char2int(char c) {
    return c - '0';//아스키코드 문자열-> 숫자로 간주하기 위해 '0' 빼기
}

// A+B를 수행하는 함수
stack<int> addLargeNumbers(string& a, string& b) {
    stack<int> result; //배열말고 스택 사용

    int idx_a = a.length() - 1;  // 1의 자리 인덱스
    int idx_b = b.length() - 1; //인덱스는 0부터 시작하니까 1을 빼준다

    bool carry = false;  // 올림 숫자
    int sum = 0; //sum 초기화

    while (idx_a >= 0 && idx_b >= 0) {  // 자릿 수 더하기
        sum = char2int(a[idx_a--]) + char2int(b[idx_b--]) + carry;//올림되는 값+a와b각각의 자릿수를 인덱스 내림차순으로 더한다
        carry = sum / 10;//10이상이 되면 올려지니까 10 나눈 값의 몫
        sum %= 10;//올림되고 나서 나머지는 남는다

        result.push(sum);//남은 값을 스택에 푸시
    }

    while (idx_a >= 0) {                     // a에서 남는 숫자 반영
        sum = char2int(a[idx_a--]) + carry;  // 이때도 계속 올림이 있을 수 있음 (ex. 9999 + 1)
        carry = sum / 10;//올림될 값
        sum %= 10;// 올림되고 난 후 나머지는 sum에 잔류

        result.push(sum);//잔류된 값을 스택에 푸시
    }

    if (carry) {  // 마지막으로 남아 있는 올림 수 확인
        result.push(carry);//마지막 계산 후 올림 수가 남아있으면 스택에 추가
    }

    return result;//더한 결과값 반환
}

/*
 * [큰 수 A+B]
 * 두 수의 자리수가 최대 10000으로, 매우 크기 때문에 절대 기본 자료형으로 저장할 수 없어요!
 * 직접 더하기를 구현해 주어야 해요.
 *
 * 1. 한 자릿수씩 더해서 스택(혹은 배열)에 저장
 * 2. 한 자릿수씩 더할 때, 값이 10을 넘어가는 경우 고려 -> 자릿수 올림
 * 3. A와 B의 길이가 같지만, 둘의 합의 길이는 다른 경우 고려 -> 마지막 자리에서 올림
 * 4. A와 B의 길이가 다른 경우 고려 -> 더 긴 길이 처리 주의,
 *                                코드 중복을 피하기 위해 A가 B보다 길도록 먼저 처리하고 시작
 *
 * 본 풀이에서 더한 결과 값을 스택에 넣는 이유는 일의 자릿수부터 더하기 때문입니다.
 * => 스택이 아닌 배열을 사용할 경우 마지막 인덱스부터 출력
 * */

int main() {
    string a, b;//숫자-> 오버플로우발생 그래서 문자열로 받기
    cin >> a >> b;//입력받기

    if (b.length() > a.length()) {//b 길이가 a보다 길면 바꿔야 됨
        swap(a, b);//a가 b보다 길도록 둘을 바꾼다
    }
        

    printResult(addLargeNumbers(a, b));//더한 값 print함수에 넣었으니까 출력하기 위해 printResult함수를 호출
}
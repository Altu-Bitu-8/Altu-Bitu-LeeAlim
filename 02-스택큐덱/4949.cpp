#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool check(const string& line) {
    stack<char> s;

    for (char c : line) {
        if (c == '.') {
            break;  // 온점일 때 검사 종료
        }
        if (c == '[' || c == '(') {
            s.push(c);
        }
        else if (c == ']' || c == ')') {
            if (s.empty()) {
                return false;
            }
            else if ((c == ']' && s.top() == '[') || (c == ')' && s.top() == '(')) {
                s.pop();
            }
            else {
                return false;
            }
        }
    }
    return s.empty();  // 문자열 끝에서 스택이 비어있는지 유무에 따라 예스/노
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string line;

    while (true) {

        getline(cin, line);

        if (line == ".") {
            break;  // 온점일 때 입력 종료
        }

        check(line);
        if (check(line)) {
            cout << "yes" << "\n";

        }
        else
            cout << "no" << "\n";


    }

    return 0;
}
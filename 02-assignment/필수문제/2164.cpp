#include <iostream>
#include <queue>

using namespace std;

void checkCard(int n, queue<int>& q) {
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() > 1) {
        q.pop();

        if (!q.empty()) {
            int top = q.front();
            q.pop();
            q.push(top);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    queue<int> q; //큐 선언

    checkCard(n, q);

    cout << q.front() << "\n";

    return 0;
}
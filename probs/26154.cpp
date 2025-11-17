#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

priority_queue<int> A[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2; j++) {
            int p; cin >> p;
            A[i].push(i ? p : -p);
        }
    }
    if (N < M) M = N + M%N;

    while (M--) {
        int p = A[0].top(); A[0].pop();
        for (int i = 1; i < N; i++) {
            A[i-1].push(i-1 ? A[i].top() : -A[i].top());
            A[i].pop();
        }
        A[N-1].push(-p);
    }

    for (int i = 0; i < N; i++) {
        if (i) {
            int p = A[i].top(); A[i].pop();
            cout << A[i].top() << ' ' << p << '\n';
        }
        else {
            cout << -A[i].top() << ' ';
            A[i].pop();
            cout << -A[i].top() << '\n';
        }
    }

    return 0;
}

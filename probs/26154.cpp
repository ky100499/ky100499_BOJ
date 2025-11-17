#include <bits/stdc++.h>

using namespace std;
using di = deque<int>;

const int MAX = 1000;

di A[MAX];

void push(di &D, int n)
{
    D.back() < n ? D.push_back(n) : D.push_front(n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int p; cin >> p;
        A[i].push_back(p);
        cin >> p;
        A[i].back() < p ? A[i].push_back(p) : A[i].push_front(p);
    }
    if (N < M) M = N + M%N;

    while (M--) {
        int p = A[0].front(); A[0].pop_front();
        for (int i = 1; i < N; i++) {
            push(A[i-1], A[i].back());
            A[i].pop_back();
        }
        push(A[N-1], p);
    }

    for (int i = 0; i < N; i++) {
        for (int p : A[i]) cout << p << ' ';
        cout << '\n';
    }

    return 0;
}

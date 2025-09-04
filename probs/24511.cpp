#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

int A[MAX];
deque<int> Q;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) {
        int b; cin >> b;
        if (!A[i]) Q.push_back(b);
    }

    int M; cin >> M;
    while (M--) {
        int c; cin >> c;
        Q.push_front(c);
        cout << Q.back() << ' ';
        Q.pop_back();
    }
    cout << '\n';

    return 0;
}

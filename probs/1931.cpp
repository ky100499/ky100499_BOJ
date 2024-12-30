#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 1e5;

pi A[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int s, e; cin >> s >> e;
        A[i] = {e, s};
    }
    sort(A, A+N);

    int t = 0, cnt = 0;
    for (int i = 0; i < N; i++) {
        auto [e, s] = A[i];
        if (s >= t) {
            t = e;
            cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}

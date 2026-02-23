#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A[100000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, K; cin >> N >> K;

    memset(A, 0, sizeof A);
    for (int i = 0; i < N; i++) {
        int P; cin >> P;
        while (P--) {
            ll x, y; cin >> x >> y;
            A[i] = max(A[i], x*x + y*y);
        }
    }
    sort(A, A+N);

    cout << A[K-1] << ".00\n";

    return 0;
}

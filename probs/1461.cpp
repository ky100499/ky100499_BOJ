#include <bits/stdc++.h>

using namespace std;

int A[50];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A+N);

    int ans = 0, i = 0, j = N-1,
        Z = lower_bound(A, A+N, 0) - A;

    while (i < Z) ans += -A[i], i += M;
    while (j >= Z) ans += A[j], j -= M;
    ans *= 2;

    if (Z == 0) ans -= A[N-1];
    else if (Z == N) ans -= -A[0];
    else ans -= max(-A[0], A[N-1]);

    cout << ans << '\n';

    return 0;
}

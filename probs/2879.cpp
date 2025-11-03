#include <bits/stdc++.h>

using namespace std;

int A[1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];

    int ans = 0, v = 0;
    for (int i = 0; i < N; i++) {
        int t, d; cin >> t; d = t - A[i];
        ans += v * d > 0 ? max(0, abs(d) - abs(v)) : abs(d);
        v = d;
    }

    cout << ans << '\n';

    return 0;
}

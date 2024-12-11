#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 3e5,
          MOD = 1e9+7;

int A[MAX], pows[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        pows[i] = i ? pows[i-1] * 2 % MOD : 1;
    }
    sort(A, A+N);

    int ans = 0;
    for (int i = 0; i < N; i++)
        ans = (ans + (ll)A[i] * (pows[i] - pows[N-1-i]) % MOD + MOD) % MOD;
    cout << ans << '\n';

    return 0;
}

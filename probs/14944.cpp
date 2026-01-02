#include <bits/stdc++.h>

using namespace std;

int S[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    S[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
        S[i] += S[i-1];
    }

    int ans = 1e9;
    while (M--) {
        int a, b, c; cin >> a >> b >> c;
        if (a > b) swap(a, b);

        if (b-a == 1) ans = min(ans, S[N] - S[b] + S[a] + c);
        ans = min(ans, 2*S[N] - S[b] - S[a+1] + S[a] + c);
        ans = min(ans, S[N] + S[b] - S[a] + c);
        ans = min(ans, 2*S[N] - 2*S[b] + S[b-1] + 2*c);
        ans = min(ans, S[N] + 2*c);
    }

    cout << ans << '\n';

    return 0;
}

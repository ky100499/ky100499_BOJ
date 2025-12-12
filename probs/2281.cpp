#include <bits/stdc++.h>

using namespace std;

int S[1001], dp[1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M; M++;
    memset(S, 0, sizeof S);
    for (int i = 1; i <= N; i++) {
        cin >> S[i];
        S[i] += S[i-1] + 1;
    }

    fill(dp, dp+N, 1e9); dp[0] = 0;
    for (int i = 1; i < N; i++) {
        for (int j = i-1; j >= 0; j--) {
            int l = S[i]-S[j];
            if (l > M) break;

            dp[i] = min(dp[i], dp[j]+(M-l)*(M-l));
        }
    }

    int ans = 1e9;
    for (int i = N-1; i >= 0; i--) {
        int l = S[N]-S[i];
        if (l > M) break;
        ans = min(ans, dp[i]);
    }

    cout << ans << '\n';

    return 0;
}

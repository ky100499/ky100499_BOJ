#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; string S; cin >> N >> S;

    int ans = 1e9, b = 0, r = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'B' && (r || S[0] == 'R')) b++;
        if (S[i] == 'R' && (b || S[0] == 'B')) r++;
    }
    ans = min(ans, min(b, r));
    b = r = 0;
    for (int i = N-1; i >= 0; i--) {
        if (S[i] == 'B' && (r || S[N-1] == 'R')) b++;
        if (S[i] == 'R' && (b || S[N-1] == 'B')) r++;
    }
    ans = min(ans, min(b, r));

    cout << ans << '\n';

    return 0;
}

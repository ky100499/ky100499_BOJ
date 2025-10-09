#include <bits/stdc++.h>

using namespace std;

int A[8], V[8];
int ans = 1e9;

void solve(int i)
{
    if (i == 8) {
        int S[2] = { 0, };
        for (int j = 0; j < 8; j++)
            S[V[j]/4] += (V[j]/2) % 2 ? A[j] : -A[j];
        ans = min(ans, max(abs(S[0]), abs(S[1])));
        return;
    }

    for (int j = 0; j < 8; j++) {
        if (V[j] == -1) {
            V[j] = i;
            solve(i+1);
            V[j] = -1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    for (int i = 0; i < 8; i++) cin >> A[i];
    memset(V, -1, sizeof V);

    solve(0);
    cout << fixed;
    cout.precision(ans%2 + 1);
    cout << 1 - ans / 20.0 << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int T;
string S;

void solve(int s, int e, int t)
{
    if (s > e) return;
    if (t % 2) {
        S[s] = ((S[s]-'A')^1)+'A';
        if (s != e) S[e] = ((S[e]-'A')^1)+'A';
    }
    solve(s+1, e-1, min(T, t+1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N >> T >> S;

    int s = 1;
    for (int i = 1; i+1 < N; i++) {
        if (S[i] == S[i-1] || S[i] == S[i+1]) {
            if (s < i) solve(s, i-1, 1);
            s = i+1;
        }
    }
    solve(s, N-2, 1);

    cout << S << '\n';

    return 0;
}

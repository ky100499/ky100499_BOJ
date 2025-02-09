#include <bits/stdc++.h>

using namespace std;

vector<string> S;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        S.clear(); S.resize(N);
        for (int i = 0; i < N; i++) cin >> S[i];
        sort(S.begin(), S.end());

        int ans = 1;
        for (int i = 1; i < N; i++)
            ans &= S[i].find(S[i-1]) != 0;
        cout << (ans ? "YES" : "NO") << '\n';
    }

    return 0;
}

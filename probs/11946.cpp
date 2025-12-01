#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

int C[101], T[101], V[101][16], W[101][16];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, Q; cin >> N >> M >> Q;

    memset(C, 0, sizeof C);
    memset(T, 0, sizeof T);
    memset(V, 0, sizeof V);
    memset(W, 0, sizeof W);
    while (Q--) {
        int t, n, m; string r; cin >> t >> n >> m >> r;
        if (r == "AC" && !V[n][m]) {
            T[n] += t + 20*W[n][m];
            C[n]++;
            V[n][m] = 1;
        }
        else W[n][m]++;
    }

    vector<ti> ans; ans.reserve(N);
    for (int i = 1; i <= N; i++) ans.emplace_back(-C[i], T[i], i);
    sort(ans.begin(), ans.end());

    for (auto [c, t, i] : ans) cout << i << ' ' << -c << ' ' << t << '\n';

    return 0;
}

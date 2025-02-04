#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 1000;

pi G[MAX+1];
int B[MAX+1], V[MAX+1];

bool match(int u)
{
    for (int b = G[u].first; b <= G[u].second; b++) {
        if (V[b]) continue;
        V[b] = 1;

        if (!B[b] || match(B[b])) {
            B[b] = u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        for (int i = 1; i <= M; i++)
            cin >> G[i].first >> G[i].second;

        memset(B, 0, sizeof B);
        int ans = 0;
        for (int i = 1; i <= M; i++) {
            memset(V, 0, sizeof V);
            if (match(i)) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}

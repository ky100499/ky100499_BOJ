#include <bits/stdc++.h>

using namespace std;

const int MAX = 50,
          INF = 1e9;

int D[MAX+1][MAX+1];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    fill(&D[0][0], &D[N+1][0], INF);
    for (int i = 1; i <= N; i++) D[i][i] = 0;
    while (1) {
        int u, v; cin >> u >> v;
        if (u == -1) break;
        D[u][v] = D[v][u] = 1;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                D[i][j] = min(D[i][j], D[i][k]+D[k][j]);

    int p = INF;
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        int m = *max_element(&D[i][1], &D[i][N+1]);
        if (m < p) {
            p = m;
            ans.clear();
        }
        if (m == p) ans.push_back(i);
    }

    cout << p << ' ' << ans.size() << '\n';
    for (int a : ans) cout << a << ' '; cout << '\n';

    return 0;
}

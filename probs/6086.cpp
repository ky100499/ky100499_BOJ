#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;

const int MAX = 26*2,
          INF = 1e9,
          A = 0, Z = 25;

int F[MAX][MAX],
    C[MAX][MAX],
    pre[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    memset(F, 0, sizeof F);
    memset(C, 0, sizeof C);

    int N; cin >> N;
    while (N--) {
        char a, b; int c, u, v; cin >> a >> b >> c;
        if (in(a, 'A', 'Z'+1)) u = a - 'A';
        else u = a - 'a' + 26;
        if (in(b, 'A', 'Z'+1)) v = b - 'A';
        else v = b - 'a' + 26;
        C[u][v] = C[v][u] = C[u][v] + c;
    }

    int ans = 0;
    while (1) {
        memset(pre, -1, sizeof pre);
        queue<int> q({A});
        while (!q.empty()) {
            int u = q.front(); q.pop();

            if (u == Z) break;

            for (int v = 0; v < MAX; v++) {
                if (pre[v] == -1 && C[u][v] > F[u][v]) {
                    pre[v] = u;
                    q.push(v);
                }
            }
        }

        if (pre[Z] == -1) break;

        int f = INF;
        for (int u = Z; u != A; u = pre[u])
            f = min(f, C[pre[u]][u] - F[pre[u]][u]);
        for (int u = Z; u != A; u = pre[u]) {
            F[pre[u]][u] += f;
            F[u][pre[u]] -= f;
        }

        ans += f;
    }

    cout << ans << '\n';

    return 0;
}

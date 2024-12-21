#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 10001,
          INF = 1e9;

int children[MAX][2],
    cnt[MAX][2] = {},
    ans[MAX][2],
    isroot[MAX] = {};

void dfs(int u)
{
    cnt[u][0] = cnt[u][1] = 0;
    for (int i = 0; i < 2; i++) {
        if (children[u][i] != -1) {
            dfs(children[u][i]);
            cnt[u][i] = cnt[children[u][i]][0]+cnt[children[u][i]][1]+1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        ans[i][0] = INF;
        ans[i][1] = 0;

        int n, l, r; cin >> n >> l >> r;
        children[n][0] = l;
        children[n][1] = r;
        isroot[l] = isroot[r] = 1;
    }

    int root;
    for (int i = 1; i <= N; i++) if (!isroot[i]) root = i;

    dfs(root);

    queue<ti> q; q.emplace(1, root, 0);
    while (!q.empty()) {
        auto [d, n, b] = q.front(); q.pop();
        int pos = b + cnt[n][0];
        ans[d][0] = min(ans[d][0], pos);
        ans[d][1] = max(ans[d][1], pos);

        if (children[n][0] != -1) q.emplace(d+1, children[n][0], b);
        if (children[n][1] != -1) q.emplace(d+1, children[n][1], pos+1);
    }

    int ansr, answ = -1;
    for (int i = 1; i <= N; i++) {
        int w = ans[i][1] - ans[i][0];
        if (w > answ) {
            ansr = i;
            answ = w;
        }
    }
    cout << ansr << ' ' << answ+1 << '\n';

    return 0;
}

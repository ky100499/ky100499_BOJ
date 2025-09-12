#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

vector<pi> G, R;

int parent[50], ans[50];

int find(int x)
{
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    parent[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        for (int j = 0; j < N; j++) {
            char c; cin >> c;
            if (i < j && c == 'Y') G.emplace_back(i, j);
        }
    }
    sort(G.begin(), G.end());

    int cnt = 0;
    memset(ans, 0, sizeof ans);
    for (auto [u, v] : G) {
        if (cnt < N-1 && find(u) != find(v)) {
            merge(u, v);
            ans[u]++;
            ans[v]++;
            cnt++;
        }
        else R.emplace_back(u, v);
    }

    if (cnt != N-1 || G.size() < M) cout << "-1\n";
    else {
        for (auto [u, v] : R) {
            if (++cnt > M) break;
            ans[u]++;
            ans[v]++;
        }

        for (int i = 0; i < N; i++) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}

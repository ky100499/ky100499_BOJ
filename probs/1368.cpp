#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 301, INF = 1e9;

int parent[MAX];
vector<ti> G;

int find(int x)
{
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b) parent[max(a, b)] = min(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N; parent[0] = 0;
    for (int i = 1; i <= N; i++) {
        int w; cin >> w;
        G.push_back({w, 0, i});
        parent[i] = i;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int w; cin >> w;
            if (i < j) G.push_back({w, i, j});
        }
    }
    sort(G.begin(), G.end());

    int ans = 0, cnt = 0;
    for (auto [w, u, v] : G) {
        if (find(u) != find(v)) {
            merge(u, v);
            ans += w;
            cnt++;
        }
        if (cnt == N) break;
    }

    cout << ans << '\n';

    return 0;
}

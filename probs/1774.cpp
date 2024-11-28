#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using tdi = tuple<double, int, int>;

const int MAX = 1000;

pii pos[MAX];
vector<tdi> G;
int parent[MAX];

int find(int a)
{
    return a == parent[a] ? a : parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b) parent[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M; G.reserve(N*N+M);
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        int x, y; cin >> x >> y;
        pos[i] = {x, y};
        for (int j = 0; j < i; j++)
            G.emplace_back(sqrt(pow(x-pos[j].first, 2) + pow(y-pos[j].second, 2)), i, j);
    }
    while (M--) {
        int x, y; cin >> x >> y;
        G.emplace_back(0, x-1, y-1);
    }
    sort(G.begin(), G.end());

    double ans = 0; int cnt = 0;
    for (auto [w, u, v] : G) {
        if (find(u) != find(v)) {
            ans += w; cnt++;
            merge(u, v);
        }
        if (cnt == N-1) break;
    }

    cout.precision(2);
    cout << fixed << ans << '\n';

    return 0;
}

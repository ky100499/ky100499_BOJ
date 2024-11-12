#include <bits/stdc++.h>

using namespace std;
using ti = tuple<int, int, int>;

int parent[10001];

int find(int a)
{
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    int pa = find(a), pb = find(b);
    if (pa != pb) parent[pb] = pa;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int V, E; cin >> V >> E;
    for (int i = 1; i <= V; i++) parent[i] = i;
    vector<ti> edges; edges.reserve(E);
    while (E--) {
        int a, b, c; cin >> a >> b >> c;
        edges.emplace_back(c, a, b);
    }
    sort(edges.begin(), edges.end());

    int weight = 0;
    for (auto [w, u, v] : edges) {
        if (find(u) != find(v)) {
            merge(u, v);
            weight += w;
        }
    }
    cout << weight << '\n';

    return 0;
}

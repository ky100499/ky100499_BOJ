#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 100000;

int parent[MAX];
pi X[MAX], Y[MAX], Z[MAX];

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

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        parent[i] = i;
        int x, y, z; cin >> x >> y >> z;
        X[i] = {x, i};
        Y[i] = {y, i};
        Z[i] = {z, i};
    }
    sort(X, X+N);
    sort(Y, Y+N);
    sort(Z, Z+N);

    vector<ti> edges; edges.reserve(3*N);
    for (int i = 1; i < N; i++) {
        edges.emplace_back(abs(X[i].first-X[i-1].first), X[i].second, X[i-1].second);
        edges.emplace_back(abs(Y[i].first-Y[i-1].first), Y[i].second, Y[i-1].second);
        edges.emplace_back(abs(Z[i].first-Z[i-1].first), Z[i].second, Z[i-1].second);
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

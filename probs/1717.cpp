#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6+1;

int parent[MAX];

int find(int a)
{
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    int pa = find(a), pb = find(b);
    if (pa < pb) parent[pb] = pa;
    else if (pa > pb) parent[pa] = pb;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i <= N; i++) parent[i] = i;
    while (M--) {
        int o, a, b; cin >> o >> a >> b;
        if (o) cout << (find(a) == find(b) ? "YES" : "NO") << '\n';
        else merge(a, b);
    }

    return 0;
}

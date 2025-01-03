#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3;

int parent[MAX+1];

int find(int a)
{
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    a = find(a); b = find(b);
    if (a != b) parent[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) parent[i] = i;

    int ans = N;
    while (M--) {
        int u, v; cin >> u >> v;
        if (find(u) != find(v)) {
            merge(u, v);
            ans--;
        }
    }

    cout << ans << '\n';

    return 0;
}

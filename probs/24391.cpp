#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5;

int parent[MAX+1];

int find(int x)
{
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void merge(int a, int b)
{
    a = find(a); b = find(b);
    if (a != b) parent[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) parent[i] = i;
    while (M--) {
        int i, j; cin >> i >> j;
        merge(i, j);
    }

    int ans = 0, p; cin >> p;
    while (--N) {
        int c; cin >> c;
        if (find(c) != find(p)) ans++;
        p = c;
    }

    cout << ans << '\n';

    return 0;
}

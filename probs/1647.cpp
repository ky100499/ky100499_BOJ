#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

int parent[100001];
ti edges[1000000];

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

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) parent[i] = i;
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = {c, a, b};
    }
    sort(edges, edges+M);

    int ans = 0, cnt = 0;
    for (int i = 0; i < M; i++) {
        if (cnt == N-2) break;
        auto [c, a, b] = edges[i];
        if (find(a) != find(b)) {
            merge(a, b);
            ans += c;
            cnt++;
        }
    }
    cout << ans << '\n';

    return 0;
}

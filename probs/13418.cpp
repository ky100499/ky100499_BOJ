#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 1001;

int parent[MAX];

int find(int x)
{
    return x == parent[x] ? x : parent[x] = find(parent[x]);
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

    int N, M; cin >> N >> M;
    vector<ti> G; G.reserve(M+1);
    for (int i = 0; i <= M; i++) {
        int a, b, c; cin >> a >> b >> c;
        G.emplace_back(c^1, a, b);
    }
    sort(G.begin(), G.end());

    int m1 = 0, m2 = 0, cnt = 0;
    for (int i = 0; i <= N; i++) parent[i] = i;
    for (int i = 0; i <= M; i++) {
        auto [c, a, b] = G[i];
        if (find(a) != find(b)) {
            merge(a, b);
            m1 += c;
            cnt++;
        }
        if (cnt == N) break;
    }

    cnt = 0;
    for (int i = 0; i <= N; i++) parent[i] = i;
    for (int i = M; i >= 0; i--) {
        auto [c, a, b] = G[i];
        if (find(a) != find(b)) {
            merge(a, b);
            m2 += c;
            cnt++;
        }
        if (cnt == N) break;
    }

    cout << (m2 + m1) * (m2 - m1) << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 1001;

int parent[MAX];
char U[MAX];

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

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        cin >> U[i];
    }
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    while (M--) {
        int u, v, d; cin >> u >> v >> d;
        if (U[u] != U[v]) pq.emplace(d, u, v);
    }

    int ans = 0, cnt = 0;
    while (!pq.empty() && cnt < N-1) {
        auto [d, u, v] = pq.top(); pq.pop();
        if (find(u) != find(v)) {
            merge(u, v);
            cnt++;
            ans += d;
        }
    }

    cout << (cnt == N-1 ? ans : -1) << '\n';

    return 0;
}

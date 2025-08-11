#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 1001;

int A[MAX], parent[MAX];

int find(int x)
{
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

bool merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (A[a] && A[b]) return false;
    else if (A[b]) parent[a] = b;
    else parent[b] = a;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K; cin >> N >> M >> K;
    if (N == K) {
        cout << "0\n";
        return 0;
    }

    memset(A, 0, sizeof A);
    for (int i = 0; i < K; i++) {
        int n; cin >> n;
        A[n] = 1;
    }
    vector<ti> G; G.reserve(M);
    while (M--) {
        int u, v, w; cin >> u >> v >> w;
        G.emplace_back(w, u, v);
    }
    sort(G.begin(), G.end());

    for (int i = 1; i <= N; i++) parent[i] = i;

    int ans = 0;
    for (auto [w, u, v] : G) {
        if (find(u) != find(v) && merge(u, v)) {
            K++;
            ans += w;
        }
        if (K == N) break;
    }

    cout << ans << '\n';

    return 0;
}

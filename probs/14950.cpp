#include <bits/stdc++.h>

using namespace std;

int P[10001];

int find(int x)
{
    return x == P[x] ? x : P[x] = find(P[x]);
}

bool merge(int a, int b)
{
    a = find(a); b = find(b);
    if (a == b) return 0;
    else P[b] = a;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, T; cin >> N >> M >> T;

    for (int i = 1; i <= N; i++) P[i] = i;

    vector<tuple<int, int, int>> V; V.reserve(M);
    while (M--) {
        int a, b, c; cin >> a >> b >> c;
        V.emplace_back(c, a, b);
    }
    sort(V.begin(), V.end());

    int ans = T * (N-2)*(N-1)/2, cnt = 1;
    for (auto [c, a, b] : V) {
        if (merge(a, b)) ans += c, cnt++;
        if (cnt == N) break;
    }

    cout << ans << '\n';

    return 0;
}

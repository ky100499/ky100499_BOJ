#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int C[30001], parent[30001];

int find(int a)
{
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
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

    int N, M, K; cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) { cin >> C[i]; parent[i] = i; }
    while (M--) {
        int a, b; cin >> a >> b;
        merge(a, b);
    }

    map<int, int[2]> cnt;
    for (int i = 1; i <= N; i++) {
        int x = find(i);
        cnt[x][0]++;
        cnt[x][1] += C[i];
    }

    vector<pi> candy;
    for (auto [_, v] : cnt) candy.emplace_back(v[0], v[1]);

    int l = candy.size();
    vector<vector<int>> dp(l+1, vector<int>(K));
    for (int i = 1; i <= l; i++) {
        auto [p, c] = candy[i-1];
        for (int j = 0; j < min(p, K); j++) dp[i][j] = dp[i-1][j];
        for (int j = p; j < K; j++) dp[i][j] = max(dp[i-1][j], dp[i-1][j-p] + c);
    }

    cout << dp[l][K-1] << '\n';

    return 0;
}

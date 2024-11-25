#include <bits/stdc++.h>

using namespace std;

int C[30001],
    P[30001],
    parent[30001];

int find(int a)
{
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b) {
        C[a] += C[b]; C[b] = 0;
        P[a] += P[b]; P[b] = 0;
        parent[b] = a;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K; cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
        P[i] = 1;
        parent[i] = i;
    }
    while (M--) {
        int a, b; cin >> a >> b;
        merge(a, b);
    }

    vector<int> dp(K);
    for (int i = 1; i <= N; i++) {
        if (i == parent[i]) {
            for (int j = K-1; j >= P[i]; j--) {
                dp[j] = max(dp[j], dp[j-P[i]] + C[i]);
            }
        }
    }

    cout << dp[K-1] << '\n';

    return 0;
}

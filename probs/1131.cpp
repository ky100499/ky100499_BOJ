#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e7;

int K, S[MAX+1], P[10];

int dfs(int n)
{
    int tmp = n, m = 0;
    while (tmp) {
        m += P[tmp%10];
        tmp /= 10;
    }

    if (S[n] > 0) return S[n];
    else if (S[n] == -2) return n;
    else {
        S[n]--;
        return S[n] = min(n, dfs(m));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int A, B; cin >> A >> B >> K;

    for (int i = 0; i < 10; i++) P[i] = pow(i, K);

    memset(S, 0, sizeof S);
    long long ans = 0;
    for (int i = A; i <= B; i++) ans += dfs(i);
    cout << ans << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 15;

ll dp[1<<MAX][100] = {};
int dgt[51],
    len[MAX],
    res[MAX];
string A[MAX];

ll fact(int n)
{
    if (n == 0 || n == 1) return 1;
    else return n*fact(n-1);
}

ll gcd(ll a, ll b)
{
    while (b) tie(a, b) = make_pair(b, a%b);
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        len[i] = A[i].size();
    }
    int K; cin >> K;

    for (int i = 0; i < N; i++) {
        int r = 0;
        for (int j = 0; j < len[i]; j++)
            r = (10*r + A[i][j]-'0') % K;
        res[i] = r;
    }

    dgt[0] = 1;
    for (int i = 1; i <= 50; i++) dgt[i] = dgt[i-1] * 10 % K;

    for (int i = 0; i < N; i++)
        dp[1<<i][res[i]] = 1;
    for (int i = 1; i < (1<<N); i++) {
        for (int j = 0; j < N; j++) {
            if (i & (1<<j)) {
                for (int k = 0; k < K; k++) {
                    dp[i][(k*dgt[len[j]] + res[j]) % K] += dp[i^(1<<j)][k];
                }
            }
        }
    }

    ll ans = dp[(1<<N)-1][0];
    if (ans) {
        ll f = fact(N);
        ll g = gcd(ans, f);
        cout << ans / g << '/' << f / g << '\n';
    }
    else cout << "0/1\n";

    return 0;
}

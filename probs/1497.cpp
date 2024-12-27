#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = 1e9;

ll G[10];
int N, M, maxs = 0, ans = INF;

int bit_count(ll c)
{
    int ret = 0;
    while (c) {
        ret += c&1;
        c >>= 1;
    }
    return ret;
}

void bt(int i, int n, ll c)
{
    if (i == N) {
        int cnt = bit_count(c);
        if (cnt > maxs) {
            maxs = cnt;
            ans = n;
        }
        else if (cnt && cnt == maxs) {
            ans = min(ans, n);
        }
    }
    else {
        bt(i+1, n, c);
        bt(i+1, n+1, c | G[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string a, b; cin >> a >> b;
        ll x = 0;
        for (int j = 0; j < M; j++)
            if (b[j] == 'Y')
                x |= 1LL<<j;
        G[i] = x;
    }

    bt(0, 0, 0);
    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}

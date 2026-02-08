#include <bits/stdc++.h>

using namespace std;

int mul(unsigned int a, int b, const int MOD)
{
    unsigned int ret = 0;
    while (b) {
        if (b&1) {
            ret += a;
            ret %= MOD;
        }
        a *= 2;
        a %= MOD;
        b >>= 1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;

    int ans = 1;
    while (N--) {
        int a; cin >> a;
        ans = mul(ans, a, M);
    }

    cout << ans << '\n';

    return 0;
}

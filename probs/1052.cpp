#include <bits/stdc++.h>

using namespace std;

int bit_count(int n)
{
    int ret = 0;
    while (n) {
        ret += n&1;
        n >>= 1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, K; cin >> N >> K;
    int ans = 0, i = 1;
    while (bit_count(N) > K) {
        while ((N&i) == 0) i <<= 1;
        N += i;
        ans += i;
    }
    cout << ans << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int R[1000];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, s = 0; cin >> N >> M;
    ll ans = 0;
    memset(R, 0, sizeof R); R[0] = 1;
    for (int i = 1; i <= N; i++) {
        int a; cin >> a;
        s += a; s %= M;
        ans += R[s]++;
    }

    cout << ans << '\n';

    return 0;
}

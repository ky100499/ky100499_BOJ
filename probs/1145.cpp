#include <bits/stdc++.h>

using namespace std;

int ans = 1e9, A[5];

void bt(int i, int v, int n)
{
    if (n == 3) {
        ans = min(ans, v);
        return;
    }
    if (i == 5) return;

    bt(i+1, v, n);
    bt(i+1, lcm(v, A[i]), n+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    for (int i = 0; i < 5; i++) cin >> A[i];
    bt(0, 1, 0);
    cout << ans << '\n';

    return 0;
}

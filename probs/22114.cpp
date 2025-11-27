#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, K; cin >> N >> K;

    int a = 1, b = 0, ans = 0;
    while (--N) {
        int l; cin >> l;
        if (l > K) b = a, a = 1;
        else a++;
        ans = max(ans, a+b);
    }

    cout << ans << '\n';

    return 0;
}

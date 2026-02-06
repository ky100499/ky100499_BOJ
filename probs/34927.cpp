#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MAX = 3e5;

int W[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> W[i];
    sort(W, W+N);

    ll s = 0; int ans = 0;
    for (int i = 0; i < N; i++) {
        if (s <= W[i]) {
            s += W[i];
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}

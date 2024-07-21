#include <iostream>

#define MOD 998'244'353

using namespace std;

int main()
{
    freopen("input.txt", "rt", stdin);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int W, H, K, T;
    cin >> W >> H >> K >> T;

    long long ans = 1;
    int x, y;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;

        int w = min(W, x+T) - max(1, x-T) + 1,
            h = min(H, y+T) - max(1, y-T) + 1;
        ans = (ans * w) % MOD;
        ans = (ans * h) % MOD;
    }

    cout << ans;
}

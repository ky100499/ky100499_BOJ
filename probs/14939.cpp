#include <bits/stdc++.h>

using namespace std;

int A[11], B[11];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    for (int i = 1; i <= 10; i++) {
        for (int j = 0; j < 10; j++) {
            char c; cin >> c;
            A[i] += (c == 'O') << j;
        }
    }

    int ans = 1e9;
    for (int x = 0; x < 1<<10; x++) {
        memcpy(B, A, sizeof A);
        B[0] = x;

        int cnt = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (B[i] & (1<<j)) {
                    B[i] ^= 1<<j;
                    B[i+1] ^= (7<<j)>>1;
                    if (i != 9) B[i+2] ^= 1<<j;
                    cnt++;
                }
            }
        }

        if (!(B[10] & 1023)) ans = min(ans, cnt);
    }

    cout << ans << '\n';

    return 0;
}

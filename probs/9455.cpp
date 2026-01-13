#include <bits/stdc++.h>

using namespace std;

int C[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;

    while (T--) {
        int N, M; cin >> N >> M;

        memset(C, 0, sizeof C);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int a; cin >> a;
                if (a) ans += N-i-++C[j];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int A[1111];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int C, N; cin >> C >> N;

    int ans = 1e9;
    fill(A, A+1111, 1e9); A[0] = 0;
    while (N--) {
        int c, p; cin >> c >> p;
        A[p] = min(A[p], c);
        if (p >= C) ans = min(ans, A[p]);
        for (int i = 1; i < C; i++) {
            if (A[i]) A[i+p] = min(A[i+p], A[i]+c);
            if (i+p >= C) ans = min(ans, A[i+p]);
        }
    }

    cout << ans << '\n';

    return 0;
}

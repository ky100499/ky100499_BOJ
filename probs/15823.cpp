#include <bits/stdc++.h>

using namespace std;

int H[100000], L[500001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    memset(L, -1, sizeof L);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        H[i] = L[a];
        L[a] = i;
    }

    int ans, l = 1, h = N;
    while (l <= h) {
        int m = (l+h)/2;

        int cnt = 0, i = -1;
        for (int j = 0; j < N; j++) {
            i = max(i, H[j]);
            if (j-i == m) cnt++, i = j;
        }

        if (cnt < M) h = m-1;
        else l = m+1, ans = m;
    }

    cout << ans << '\n';

    return 0;
}

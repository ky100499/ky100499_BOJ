#include <bits/stdc++.h>

using namespace std;

int N, H, ans = 4,
    L[31][11];

void dfs(int n, int h, int cnt)
{
    if (cnt >= ans) return;

    if (h == H+1) {
        n++; h = 1;
    }

    if (n == N) {
        for (int i = 1; i <= N; i++) {
            int x = i;
            for (int y = 1; y <= H; y++) {
                x += L[y][x];
            }
            if (x != i) return;
        }
        ans = cnt;
        return;
    }

    dfs(n, h+1, cnt);
    if (L[h][n] == 0 && L[h][n+1] == 0) {
        L[h][n] = 1; L[h][n+1] = -1;
        dfs(n, h+1, cnt+1);
        L[h][n] = L[h][n+1] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int M; cin >> N >> M >> H;
    memset(L, 0, sizeof L);
    while (M--) {
        int a, b; cin >> a >> b;
        L[a][b] = 1; L[a][b+1] = -1;
    }

    dfs(1, 1, 0);
    cout << (ans > 3 ? -1 : ans) << '\n';

    return 0;
}

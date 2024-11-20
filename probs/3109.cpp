#include <bits/stdc++.h>

#define in(x, a, b) a <= x && x < b

using namespace std;

int B[10000][500],
    mv[] = {-1, 0, 1},
    cnt = 0,
    R, C;

int dfs(int x, int y)
{
    if (y == C-1) { return ++cnt; }
    else {
        for (int dx : mv) {
            int nx = x+dx, ny = y+1;
            if (in(nx, 0, R) && B[nx][ny]) {
                B[nx][ny] = 0;
                if (dfs(nx, ny)) return 1;
            }
        }
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char ipt; cin >> ipt;
            B[i][j] = ipt == '.';
        }
    }

    for (int i = 0; i < R; i++) dfs(i, 0);
    cout << cnt << '\n';

    return 0;
}

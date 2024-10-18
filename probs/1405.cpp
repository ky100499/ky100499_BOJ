#include <bits/stdc++.h>

using namespace std;

int mv[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} },
    V[30][30] = {{0,},},
    prob[4],
    N;

double dfs(int x, int y, int n, double p)
{
    if (n == N) return p;

    double ret = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x+mv[i][0], ny = y+mv[i][1];
        if (!V[nx][ny]) {
            V[nx][ny] = 1;
            ret += dfs(nx, ny, n+1, p*prob[i]/100);
            V[nx][ny] = 0;
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < 4; i++) cin >> prob[i];

    V[15][15] = 1;
    cout << fixed;
    cout.precision(10);
    cout << dfs(15, 15, 0, 1) << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int B[10][10],
    P[5],
    ans;

void solve(int x, int y, int n)
{
    if (x == 10) {
        ans = min(ans, n);
        return;
    }

    if (B[x][y]) {
        for (int i = 0; i < 5; i++) {
            if (x+i == 10 || y+i == 10) break;

            int sqr = 1;
            for (int j = 0; j <= i; j++) {
                if (!B[x+i][y+j] || !B[x+j][y+i]) {
                    sqr = 0;
                    break;
                }
            }

            if (!sqr) break;
            if (!P[i]) continue;

            for (int j = 0; j <= i; j++)
                for (int k = 0; k <= i; k++)
                    B[x+j][y+k] = 0;
            P[i]--;

            solve(x+(y+1)/10, (y+1)%10, n+1);

            for (int j = 0; j <= i; j++)
                for (int k = 0; k <= i; k++)
                    B[x+j][y+k] = 1;
            P[i]++;
        }
    }
    else solve(x+(y+1)/10, (y+1)%10, n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            cin >> B[i][j];

    fill(P, P+5, 5);
    ans = INF;
    solve(0, 0, 0);

    cout << (ans == INF ? -1 : ans) << '\n';

    return 0;
}

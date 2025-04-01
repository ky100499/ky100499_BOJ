#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;

int A[50][5],
    mv[4][2] = { {0,-1}, {1,0}, {0,1}, {-1,0} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;

    int len = 1, r = 0, c = 0, d = 2, n = 1, l = 0,
        m = max(max(abs(r1), abs(r2)), max(abs(c1), abs(c2)));
    m = 4*m*m+4*m+1;
    while (len++) {
        for (int i = 0; i < len/2; i++) {
            if (in(r, r1, r2+1) && in(c, c1, c2+1)) {
                A[r-r1][c-c1] = n;
                l = max(l, (int)to_string(n).size());
            }

            r += mv[d][0]; c += mv[d][1];
            n++;
        }
        d = (d+1)%4;
        if (n >= m) break;
    }

    for (int i = 0; i <= r2-r1; i++) {
        for (int j = 0; j <= c2-c1; j++) {
            cout.width(l);
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}

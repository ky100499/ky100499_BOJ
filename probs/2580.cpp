#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

int B[9][9];
vector<pi> zeros;

bool check(int x, int y)
{
    int bx = x/3*3,
        by = y/3*3;

    for (int i = 0; i < 9; i++) {
        if (i != x && B[i][y] == B[x][y]) return 0;
        if (i != y && B[x][i] == B[x][y]) return 0;
        if (bx+i/3 != x && by+i%3 != y && B[bx+i/3][by+i%3] == B[x][y]) return 0;
    }

    return 1;
}

bool bt(int idx)
{
    if (idx == zeros.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << B[i][j] << ' ';
            cout << '\n';
        }
        return 1;
    }

    auto [x, y] = zeros[idx];
    int ret = 0;
    for (int i = 1; i <= 9 && !ret; i++) {
        B[x][y] = i;
        if (check(x, y)) ret |= bt(idx+1);
    }
    B[x][y] = 0;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> B[i][j];
            if (!B[i][j]) zeros.emplace_back(i, j);
        }
    }

    bt(0);

    return 0;
}

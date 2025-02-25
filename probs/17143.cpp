#include <bits/stdc++.h>

using namespace std;
using pi = tuple<int, int, int, int, int>;

int B[101][101],
    mv[4][2] = { {-1,0}, {1,0}, {0,1}, {0,-1} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int R, C, M; cin >> R >> C >> M;
    vector<pi> tmp; tmp.reserve(M);
    memset(B, 0, sizeof B);
    while (M--) {
        int r, c, s, d, z; cin >> r >> c >> s >> d >> z;
        tmp.emplace_back(z, r, c, s%(d>2?2*C-2:2*R-2), d-1);
        B[r][c] = 1;
    }
    sort(tmp.begin(), tmp.end());
    deque<pi> F(tmp.rbegin(), tmp.rend());

    int ans = 0;
    for (int i = 1; i <= C; i++) {
        int cr = 0, cc = 0;
        for (int r = 1; r <= R; r++) {
            if (B[r][i]) {
                cr = r; cc = i;
                break;
            }
        }

        memset(B, 0, sizeof B);
        for (int j = F.size(); j; j--) {
            auto [z, r, c, s, d] = F.front(); F.pop_front();

            if (r == cr && c == cc) {
                ans += z;
                continue;
            }

            for (int k = 0; k < s; k++) {
                if (d == 0 && r == 1) d = 1;
                if (d == 1 && r == R) d = 0;
                if (d == 2 && c == C) d = 3;
                if (d == 3 && c == 1) d = 2;
                r += mv[d][0]; c += mv[d][1];
            }

            if (!B[r][c]) {
                B[r][c] = 1;
                F.emplace_back(z, r, c, s, d);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

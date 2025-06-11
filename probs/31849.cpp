#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 1000,
          INF = 1e9;

int A[MAX+1][MAX+1],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, R, C; cin >> N >> M >> R >> C;
    fill(&A[1][0], &A[N+1][0], INF);
    queue<ti> q;

    vector<ti> rooms; rooms.reserve(R);
    while (R--) {
        int a, b, p; cin >> a >> b >> p;
        rooms.emplace_back(a, b, p);
    }

    while (C--) {
        int c, d; cin >> c >> d;
        q.emplace(c, d, 0);
        A[c][d] = 0;
    }

    while (!q.empty()) {
        auto [c, d, w] = q.front(); q.pop();

        if (A[c][d] < w) continue;

        for (auto [dc, dd] : mv) {
            int nc = c+dc, nd = d+dd;
            if (in(nc, 1, N+1) && in(nd, 1, M+1) && A[nc][nd] > w+1) {
                A[nc][nd] = w+1;
                q.emplace(nc, nd, w+1);
            }
        }
    }

    int ans = INF;
    for (auto [a, b, p] : rooms)
        ans = min(ans, A[a][b] * p);

    cout << ans << '\n';

    return 0;
}

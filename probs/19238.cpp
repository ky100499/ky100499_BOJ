#include <bits/stdc++.h>

#define in(x, a, b) (a < x && x <= b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int INF = 1e9;

int A[21][21],
    D[400][21][21],
    V[400],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

pi S[400], T[400];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, F; cin >> N >> M >> F;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> A[i][j];

    int X, Y; cin >> X >> Y;
    fill(&D[0][0][0], &D[M][0][0], INF);
    for (int i = 0; i < M; i++) {
        cin >> S[i].first >> S[i].second >> T[i].first >> T[i].second;

        queue<ti> q; q.emplace(S[i].first, S[i].second, 0); D[i][S[i].first][S[i].second] = 0;
        while (!q.empty()) {
            auto [r, c, d] = q.front(); q.pop();

            if (D[i][r][c] < d) continue;

            for (auto [dr, dc] : mv) {
                int nr = r+dr, nc = c+dc;
                if (in(nr, 0, N) && in(nc, 0, N) && !A[nr][nc] && D[i][nr][nc] > d+1) {
                    q.emplace(nr, nc, d+1);
                    D[i][nr][nc] = d+1;
                }
            }
        }

        if (D[i][X][Y] == INF || D[i][T[i].first][T[i].second] == INF) {
            cout << "-1\n";
            return 0;
        }
    }

    memset(V, 0, sizeof V);
    int cnt = 0;
    while (cnt < M) {
        int t, d = INF;
        for (int i = 0; i < M; i++) {
            if (V[i]) continue;

            if (
                D[i][X][Y] < d ||
                (
                    D[i][X][Y] == d &&
                    (
                        S[i].first < S[t].first ||
                        (
                            S[i].first == S[t].first &&
                            S[i].second < S[t].second
                        )
                    )
                )
            ) {
                t = i;
                d = D[i][X][Y];
            }
        }

        F -= D[t][X][Y];
        tie(X, Y) = T[t];
        F -= D[t][X][Y];

        if (F < 0) {
            cout << "-1\n";
            return 0;
        }

        F += 2 * D[t][X][Y];
        cnt += V[t] = 1;
    }

    cout << F << '\n';

    return 0;
}

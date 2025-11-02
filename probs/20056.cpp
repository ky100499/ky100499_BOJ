#include <bits/stdc++.h>

#define in(x, a, b) (a < x && x <= b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 50;

int mv[8][2] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };
vector<ti> A[MAX][MAX], B[MAX][MAX];

int mod(int n, int m)
{
    return (n%m+m)%m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K; cin >> N >> M >> K;
    while (M--) {
        int r, c, m, s, d; cin >> r >> c >> m >> s >> d;
        A[r-1][c-1].emplace_back(m, s, d);
    }

    while (K--) {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                B[i][j].clear();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (auto [m, s, d] : A[i][j]) {
                    auto [di, dj] = mv[d];
                    B[mod(i+s*di, N)][mod(j+s*dj, N)].emplace_back(m, s, d);
                }
            }
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                A[i][j].clear();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (B[i][j].size() < 2) {
                    if (!B[i][j].empty()) A[i][j].push_back(B[i][j][0]);
                    continue;
                }

                int nm = 0, ns = 0, o = 0, e = 0;
                for (auto [m, s, d] : B[i][j]) {
                    nm += m;
                    ns += s;
                    (d%2 ? o : e)++;
                }
                nm /= 5;
                ns /= B[i][j].size();

                if (nm)
                    for (int nd = o*e > 0; nd < 8; nd += 2)
                        A[i][j].emplace_back(nm, ns, nd);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (auto [m, s, d] : A[i][j])
                ans += m;

    cout << ans << '\n';

    return 0;
}

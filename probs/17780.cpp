#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;

const int MAX = 12;

int A[MAX][MAX],
    D[MAX],
    mv[4][2] = { {1,0}, {0,1}, {0,-1}, {-1,0} };
vector<int> B[MAX][MAX];
pi P[MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, K; cin >> N >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];
    for (int i = 0; i < K; i++) {
        int x, y, d; cin >> x >> y >> d;
        B[x-1][y-1].push_back(i);
        P[i] = {x-1, y-1};
        D[i] = d%4;
    }

    int T = 0;
    while (++T <= 1000) {
        for (int i = 0; i < K; i++) {
            auto [x, y] = P[i];
            if (B[x][y].empty() || B[x][y][0] != i) continue;

            int nx = x+mv[D[i]][0], ny = y+mv[D[i]][1];
            if (!in(nx, 0, N) || !in(ny, 0, N) || A[nx][ny] == 2) {
                D[i] = 3-D[i];
                nx = x+mv[D[i]][0]; ny = y+mv[D[i]][1];
                if (in(nx, 0, N) && in(ny, 0, N) && A[nx][ny] != 2) {
                    if (A[nx][ny] == 1) {
                        for (int j = B[x][y].size()-1; j >= 0; j--) {
                            B[nx][ny].push_back(B[x][y][j]);
                            P[B[x][y][j]] = {nx, ny};
                        }
                    }
                    else {
                        for (int j = 0; j < B[x][y].size(); j++) {
                            B[nx][ny].push_back(B[x][y][j]);
                            P[B[x][y][j]] = {nx, ny};
                        }
                    }
                    B[x][y].clear();
                }
            }
            else if (A[nx][ny] == 1) {
                // Red
                for (int j = B[x][y].size()-1; j >= 0; j--) {
                    B[nx][ny].push_back(B[x][y][j]);
                    P[B[x][y][j]] = {nx, ny};
                }
                B[x][y].clear();
            }
            else {
                // White
                for (int j = 0; j < B[x][y].size(); j++) {
                    B[nx][ny].push_back(B[x][y][j]);
                    P[B[x][y][j]] = {nx, ny};
                }
                B[x][y].clear();
            }

            if (in(nx, 0, N) && in(ny, 0, N) && B[nx][ny].size() > 3) {
                cout << T << '\n';
                return 0;
            }
        }
    }

    cout << "-1\n";

    return 0;
}

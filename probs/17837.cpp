#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 12;

int A[MAX][MAX],
    D[MAX],
    mv[4][2] = { {1,0}, {0,1}, {0,-1}, {-1,0} };
vector<int> B[MAX][MAX];
ti P[MAX];

void white(int x, int y, int nx, int ny, int k)
{
    for (int j = k; j < B[x][y].size(); j++) {
        P[B[x][y][j]] = {nx, ny, B[nx][ny].size()};
        B[nx][ny].push_back(B[x][y][j]);
    }
    B[x][y].resize(k);
}

void red(int x, int y, int nx, int ny, int k)
{
    for (int j = B[x][y].size()-1; j >= k; j--) {
        P[B[x][y][j]] = {nx, ny, B[nx][ny].size()};
        B[nx][ny].push_back(B[x][y][j]);
    }
    B[x][y].resize(k);
}

bool isBlue(int x, int y, int N)
{
    return !in(x, 0, N) || !in(y, 0, N) || A[x][y] == 2;
}

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
        P[i] = {x-1, y-1, 0};
        D[i] = d%4;
    }

    int T = 0;
    while (++T <= 1000) {
        for (int i = 0; i < K; i++) {
            auto [x, y, k] = P[i];
            if (B[x][y][k] != i) continue;

            int nx = x+mv[D[i]][0], ny = y+mv[D[i]][1];
            if (isBlue(nx, ny, N)) {
                D[i] = 3-D[i];
                nx = x+mv[D[i]][0]; ny = y+mv[D[i]][1];
                if (!isBlue(nx, ny, N))
                    A[nx][ny] ? red(x, y, nx, ny, k) : white(x, y, nx, ny, k);
            }
            else if (A[nx][ny] == 1) red(x, y, nx, ny, k);
            else white(x, y, nx, ny, k);

            if (in(nx, 0, N) && in(ny, 0, N) && B[nx][ny].size() > 3) {
                cout << T << '\n';
                return 0;
            }
        }
    }

    cout << "-1\n";

    return 0;
}

#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;

const int MAX = 11;

int mv[8][2] = {
        {1,0},
        {1,1},
        {0,1},
        {-1,1},
        {-1,0},
        {-1,-1},
        {0,-1},
        {1,-1}
    };

int A[MAX][MAX],
    B[MAX][MAX],
    newt[MAX][MAX];
deque<int> T[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, K; cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            B[i][j] = 5;
        }
    }
    while (M--) {
        int x, y, z; cin >> x >> y >> z;
        T[x][y].push_back(z);
    }

    while (K--) {
        memset(newt, 0, sizeof newt);

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                int die = 0;
                for (int k = T[i][j].size(); k; k--) {
                    int t = T[i][j].front(); T[i][j].pop_front();
                    if (B[i][j] < t) die = 1;

                    if (die) B[i][j] += t/2;
                    else {
                        B[i][j] -= t;
                        T[i][j].push_back(t+1);
                        if (t%5 == 4) newt[i][j]++;
                    }
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (auto [di, dj] : mv) {
                    int ni = i+di, nj = j+dj;
                    if (in(ni, 1, N+1) && in(nj, 1, N+1))
                        for (int k = 0; k < newt[i][j]; k++)
                            T[ni][nj].push_front(1);
                }

                B[i][j] += A[i][j];
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            ans += T[i][j].size();
    cout << ans << '\n';

    return 0;
}

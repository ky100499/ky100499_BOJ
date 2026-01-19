#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;

char A[500][500];
int V[500][500][3],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

bool valid(int x, int y, int s)
{
    if (A[x][y] != '0') return 1;

    if (s == 1) return A[x-1][y] != '0' && A[x+1][y] != '0';
    if (s == 2) return A[x][y-1] != '0' && A[x][y+1] != '0';

    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, x, y; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
            if (A[i][j] == '2') x=i, y=j;
        }
    }

    memset(V, 0, sizeof V); V[x][y][0] = 1;
    queue<tuple<int, int, int, int>> q; q.emplace(x, y, 0, 0);
    int ans = -2;
    while (!q.empty()) {
        auto [x, y, d, s] = q.front(); q.pop();

        if (
            A[x][y] == '3' ||
            (s == 1 && (A[x-1][y] == '3' || A[x+1][y] == '3')) ||
            (s == 2 && (A[x][y-1] == '3' || A[x][y+1] == '3'))
        ) {
            ans = d;
            break;
        }

        d++;

        if (s == 0) {
            if (in(x+3, 0, N) && !V[x+2][y][1] && valid(x+2, y, 1)) {
                V[x+2][y][1] = 1;
                q.emplace(x+2, y, d, 1);
            }
            if (in(x-3, 0, N) && !V[x-2][y][1] && valid(x-2, y, 1)) {
                V[x-2][y][1] = 1;
                q.emplace(x-2, y, d, 1);
            }
            if (in(y+3, 0, M) && !V[x][y+2][2] && valid(x, y+2, 2)) {
                V[x][y+2][2] = 1;
                q.emplace(x, y+2, d, 2);
            }
            if (in(y-3, 0, M) && !V[x][y-2][2] && valid(x, y-2, 2)) {
                V[x][y-2][2] = 1;
                q.emplace(x, y-2, d, 2);
            }
        }
        else if (s == 1) {
            if (in(x+2, 0, N) && !V[x+2][y][0] && valid(x+2, y, 0)) {
                V[x+2][y][0] = 1;
                q.emplace(x+2, y, d, 0);
            }
            if (in(x-2, 0, N) && !V[x-2][y][0] && valid(x-2, y, 0)) {
                V[x-2][y][0] = 1;
                q.emplace(x-2, y, d, 0);
            }
            if (in(y+1, 0, M) && !V[x][y+1][1] && valid(x, y+1, 1)) {
                V[x][y+1][1] = 1;
                q.emplace(x, y+1, d, 1);
            }
            if (in(y-1, 0, M) && !V[x][y-1][1] && valid(x, y-1, 1)) {
                V[x][y-1][1] = 1;
                q.emplace(x, y-1, d, 1);
            }
        }
        else if (s == 2) {
            if (in(x+1, 0, N) && !V[x+1][y][2] && valid(x+1, y, 2)) {
                V[x+1][y][2] = 1;
                q.emplace(x+1, y, d, 2);
            }
            if (in(x-1, 0, N) && !V[x-1][y][2] && valid(x-1, y, 2)) {
                V[x-1][y][2] = 1;
                q.emplace(x-1, y, d, 2);
            }
            if (in(y+2, 0, M) && !V[x][y+2][0] && valid(x, y+2, 0)) {
                V[x][y+2][0] = 1;
                q.emplace(x, y+2, d, 0);
            }
            if (in(y-2, 0, M) && !V[x][y-2][0] && valid(x, y-2, 0)) {
                V[x][y-2][0] = 1;
                q.emplace(x, y-2, d, 0);
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;
using ti = tuple<int, int, int>;

int W[1000][1000],
    H[1001][1000],
    V[1000][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, L; cin >> N >> M >> L;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            W[i][j] = L;

    for (int i = 0; i <= N; i++)
        for (int j = 0; j < M; j++)
            cin >> H[i][j];
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= M; j++)
            cin >> V[i][j];

    priority_queue<ti, vector<ti>, greater<ti>> pq;
    for (int i = 0; i < M; i++) {
        if (H[0][i] != -1) {
            pq.push({H[0][i], 0, i});
            W[0][i] = min(W[0][i], H[0][i]);
        }
        if (H[N][i] != -1) {
            pq.push({H[N][i], N-1, i});
            W[N-1][i] = min(W[N-1][i], H[N][i]);
        }
    }
    for (int i = 0; i < N; i++) {
        if (V[i][0] != -1) {
            pq.push({V[i][0], i, 0});
            W[i][0] = min(W[i][0], V[i][0]);
        }
        if (V[i][M] != -1) {
            pq.push({V[i][M], i, M-1});
            W[i][M-1] = min(W[i][M-1], V[i][M]);
        }
    }

    while (!pq.empty()) {
        auto [w, x, y] = pq.top(); pq.pop();

        if (w > W[x][y]) continue;

        if (0 < x && H[x][y] != -1 && W[x-1][y] > max(H[x][y], W[x][y])) {
            W[x-1][y] = max(H[x][y], W[x][y]);
            pq.push({W[x-1][y], x-1, y});
        }
        if (x+1 < N && H[x+1][y] != -1 && W[x+1][y] > max(H[x+1][y], W[x][y])) {
            W[x+1][y] = max(H[x+1][y], W[x][y]);
            pq.push({W[x+1][y], x+1, y});
        }
        if (0 < y && V[x][y] != -1 && W[x][y-1] > max(V[x][y], W[x][y])) {
            W[x][y-1] = max(V[x][y], W[x][y]);
            pq.push({W[x][y-1], x, y-1});
        }
        if (y+1 < M && V[x][y+1] != -1 && W[x][y+1] > max(V[x][y+1], W[x][y])) {
            W[x][y+1] = max(V[x][y+1], W[x][y]);
            pq.push({W[x][y+1], x, y+1});
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            ans += W[i][j];
    cout << ans << '\n';

    return 0;
}

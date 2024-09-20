#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;

using ti = tuple<int, int, int, int>;

int dx[] = { 0, 1, 0, -1 },
    dy[] = { 1, 0, -1, 0 };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    vector<vector<int>> B(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (B[i][j] == 0) {
                int sero = 0, garo = 0;
                if (0 < i && B[i-1][j] != 1) sero = 1;
                if (i+1 < N && B[i+1][j] != 1) sero = 1;
                if (0 < j && B[i][j-1] != 1) garo = 1;
                if (j+1 < N && B[i][j+1] != 1) garo = 1;

                if (sero && garo) B[i][j] = -1;
            }
        }
    }

    priority_queue<ti, vector<ti>, greater<ti>> pq; pq.push({0, 0, 0, 0});
    vector<vector<vector<int>>> V(N, vector<vector<int>>(N, vector<int>(2)));

    while (!pq.empty()) {
        int t, x, y, u; tie(t, x, y, u) = pq.top(); pq.pop();

        if (x == N-1 && y == N-1) {
            cout << t << '\n';
            break;
        }

        if (V[x][y][u]) continue;
        V[x][y][u] = 1;

        for (int i = 0; i < 4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if (0 <= nx && nx < N && 0 <= ny && ny < N && !V[nx][ny][u]) {
                if (B[nx][ny] == 1) pq.push({t+1, nx, ny, u});
                else if (B[nx][ny] == 0 && !u) pq.push({(t/M+1)*M, nx, ny, 1});
                else if (B[nx][ny] > 1 && B[x][y] == 1) pq.push({(t/B[nx][ny]+1)*B[nx][ny], nx, ny, u});
            }
        }
    }

    return 0;
}

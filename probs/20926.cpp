#include <bits/stdc++.h>

#define in(x, a, b) a <= x && x < b

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 500,
          INF = 1e9;

int W, H,
    dist[MAX][MAX],
    mv[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

char B[MAX][MAX];

int dijkstra(pi s)
{
    auto [x, y] = s;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            dist[i][j] = INF;
    dist[x][y] = 0;

    priority_queue<ti, vector<ti>, greater<ti>> pq; pq.emplace(0, x, y);
    while (!pq.empty()) {
        auto [d, x, y] = pq.top(); pq.pop();

        if (dist[x][y] < d) continue;

        if (B[x][y] == 'E') return d;

        for (auto [dx, dy] : mv) {
            int k = 0, w = 0;
            while (++k) {
                int nx = x+k*dx, ny = y+k*dy;
                if (in(nx, 0, H) && in(ny, 0, W)) {
                    if (B[nx][ny] == 'E') {
                        if (dist[nx][ny] > d+w) {
                            dist[nx][ny] = d+w;
                            pq.emplace(d+w, nx, ny);
                        }
                        break;
                    }
                    else if (B[nx][ny] == 'R') {
                        if (dist[nx-dx][ny-dy] > d+w) {
                            dist[nx-dx][ny-dy] = d+w;
                            pq.emplace(d+w, nx-dx, ny-dy);
                        }
                        break;
                    }
                    else if (B[nx][ny] == 'H') break;
                    else w += B[nx][ny] - '0';
                }
                else break;
            }
        }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> W >> H;
    pi S;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            char ipt; cin >> ipt;
            if (ipt == 'T') {
                B[i][j] = '0';
                S = {i, j};
            }
            else B[i][j] = ipt;
        }
    }

    cout << dijkstra(S) << '\n';

    return 0;
}

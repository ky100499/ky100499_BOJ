#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 50,
          INF = 1e9;

int B[MAX+1][MAX+1],
    dist[MAX+1][MAX+1],
    mv[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}, };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    int si, sj, ei, ej; cin >> si >> sj >> ei >> ej;
    int K, M; cin >> K >> M;
    while (M--) {
        int n; cin >> n;
        int sx, sy; cin >> sx >> sy;
        B[sx][sy] = 1;
        while (--n) {
            int ex, ey; cin >> ex >> ey;
            int dx = ex-sx, dy = ey-sy; dx /= dx ? abs(dx) : 1; dy /= dy ? abs(dy) : 1;
            while (sx != ex || sy != ey) {
                sx += dx; sy += dy;
                B[sx][sy] = 1;
            }
        }
    }

    fill(&dist[0][0], &dist[N+1][0], INF);
    dist[si][sj] = B[si][sj] ? K : 1;
    priority_queue<ti, vector<ti>, greater<ti>> pq; pq.emplace(dist[si][sj], si, sj);
    while (!pq.empty()) {
        auto [d, x, y] = pq.top(); pq.pop();

        if (d > dist[x][y]) continue;
        if (x == ei && y == ej) break;

        for (auto [dx, dy] : mv) {
            int nx = x+dx, ny = y+dy;
            if (in(nx, 1, N+1) && in(ny, 1, N+1)) {
                int nd = d+(B[nx][ny] ? K : 1);
                if (dist[nx][ny] > nd) {
                    dist[nx][ny] = nd;
                    pq.emplace(nd, nx, ny);
                }
            }
        }
    }

    cout << dist[ei][ej] << '\n';
    deque<pi> ans; ans.emplace_back(ei, ej);
    while (ei != si || ej != sj) {
        for (auto [di, dj] : mv) {
            if (dist[ei][ej] - dist[ei+di][ej+dj] == (B[ei][ej] ? K : 1)) {
                while (dist[ei][ej] - dist[ei+di][ej+dj] == (B[ei][ej] ? K : 1)) {
                    ei += di; ej += dj;
                }
                ans.emplace_front(ei, ej);
                break;
            }
        }
    }

    cout << ans.size() << ' ';
    for (auto [x, y] : ans) cout << x << ' ' << y << ' '; cout << '\n';

    return 0;
}

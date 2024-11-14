#include <bits/stdc++.h>

#define in(x, a, b) a <= x && x < b

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

int parent[7] = {0, 1, 2, 3, 4, 5, 6},
    B[10][10] = {0,},
    _B[10][10],
    mv[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<ti> edges;

int find(int a)
{
    if (a == parent[a]) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    a = find(a); b = find(b);
    if (a != b) parent[b] = a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> _B[i][j];

    int n = 0;
    for (int i = 0 ; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (_B[i][j] && !B[i][j]) {
                n++;
                queue<pi> q({{i, j}});
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    B[x][y] = n;
                    for (auto [dx, dy] : mv) {
                        int nx = x+dx, ny = y+dy;
                        if (in(nx, 0, N) && in(ny, 0, M) && _B[nx][ny] && !B[nx][ny])
                            q.emplace(nx, ny);
                    }
                }
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (B[i][j]) {
                for (auto [di, dj] : mv) {
                    int k = 1;
                    while (1) {
                        int ni = i+k*di, nj = j+k*dj;
                        if (!(in(ni, 0, N) && in(nj, 0, M))) break;
                        if (B[ni][nj]) {
                            if (B[i][j] != B[ni][nj] && k > 2) edges.emplace_back(k-1, B[i][j], B[ni][nj]);
                            break;
                        }
                        k++;
                    }
                }
            }
        }
    }
    sort(edges.begin(), edges.end());

    int ans = 0, cnt = 0;
    for (auto [w, s, e] : edges) {
        if (find(s) != find(e)) {
            cnt++;
            ans += w;
            merge(s, e);
        }
    }

    cout << (cnt == n-1 ? ans : -1) << '\n';

    return 0;
}

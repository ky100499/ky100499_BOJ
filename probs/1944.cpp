#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int INF = 1e9;

int parent[251],
    D[50][50],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
char A[50][50];

map<pi, int> ctoi;
map<int, pi> itoc;

int find(int x)
{
    return x == parent[x] ? x : parent[x] = find(parent[x]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b) parent[max(a, b)] = min(a, b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, n = 0; cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
            if (A[i][j] == 'S' || A[i][j] == 'K') {
                parent[n] = ctoi[{i, j}] = n;
                itoc[n++] = {i, j};
            }
        }
    }

    vector<ti> G;
    for (auto [i, c] : itoc) {
        queue<pi> q; q.push(c);
        fill(&D[0][0], &D[N][0], INF); D[c.first][c.second] = 0;
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();

            if ((A[x][y] == 'S' || A[x][y] == 'K') && i < ctoi[{x, y}])
                G.emplace_back(D[x][y], i, ctoi[{x, y}]);

            for (auto [dx, dy] : mv) {
                int nx = x+dx, ny = y+dy;
                if (A[nx][ny] != '1' && D[nx][ny] > D[x][y]+1) {
                    D[nx][ny] = D[x][y]+1;
                    q.emplace(nx, ny);
                }
            }
        }
    }

    if (G.size() == M*(M+1)/2) {
        sort(G.begin(), G.end());
        int ans = 0, cnt = 0;
        for (auto [d, u, v] : G) {
            if (find(u) != find(v)) {
                merge(u, v);
                ans += d;
                cnt++;
            }
            if (cnt == M) break;
        }
        cout << ans << '\n';
    }
    else cout << "-1\n";

    return 0;
}

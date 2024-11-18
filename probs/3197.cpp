#include <bits/stdc++.h>

#define in(x, a, b) a <= x && x < b

using namespace std;
using pi = pair<int, int>;

const int MAX = 1500;

int parent[MAX*MAX],
    B[MAX][MAX] = {},
    W[MAX][MAX],
    mv[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int find(int a)
{
    if (parent[a] == a) return a;
    else return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    a = find(a), b = find(b);
    if (a < b) parent[b] = a;
    else if (a > b) parent[a] = b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int R, C; cin >> R >> C;
    if (R == 1 && C == 1) {
        cout << "0\n";
        return 0;
    }
    vector<pi> swans;
    deque<pi> waters;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char ipt; cin >> ipt;
            if (ipt == 'X') W[i][j] = 1;
            else waters.emplace_back(i, j);
            if (ipt == 'L') swans.emplace_back(i, j);
        }
    }

    int c = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!W[i][j] && !B[i][j]) {
                B[i][j] = ++c;
                queue<pi> q({{i, j}});
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (auto [dx, dy] : mv) {
                        int nx = x+dx, ny = y+dy;
                        if (in(nx, 0, R) && in(ny, 0, C) && !W[nx][ny] && !B[nx][ny]) {
                            B[nx][ny] = c;
                            q.emplace(nx, ny);
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i <= c; i++) parent[i] = i;

    for (int t = 0; ; t++) {
        if (find(B[swans[0].first][swans[0].second]) == find(B[swans[1].first][swans[1].second])) {
            cout << t << '\n';
            break;
        }

        for (int i = waters.size(); i; i--) {
            auto [x, y] = waters.front(); waters.pop_front();
            for (auto [dx, dy] : mv) {
                int nx = x+dx, ny = y+dy;
                if (in(nx, 0, R) && in(ny, 0, C) && W[nx][ny]) {
                    W[nx][ny] = 0;
                    B[nx][ny] = B[x][y];
                    waters.emplace_back(nx, ny);
                }
            }
        }

        for (auto [x, y] : waters) {
            for (auto [dx, dy] : mv) {
                int nx = x+dx, ny = y+dy;
                if (in(nx, 0, R) && in(ny, 0, C) && !W[nx][ny]) {
                    merge(B[x][y], B[nx][ny]);
                }
            }
        }
    }

    return 0;
}

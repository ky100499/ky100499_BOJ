#include <bits/stdc++.h>

#define in(x, a, b) a <= x && x < b

using namespace std;
using pi = pair<int, int>;

const int MAX = 1500;

int parent[MAX*MAX],
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
    vector<int> swans;
    deque<pi> waters;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            parent[i*C+j] = i*C+j;
            char ipt; cin >> ipt;
            if (ipt == 'X') W[i][j] = -1;
            else {
                W[i][j] = i*C+j;
                waters.emplace_back(i, j);
            }
            if (ipt == 'L') swans.push_back(i*C+j);
        }
    }

    for (int t = 0; ; t++) {
        for (auto [x, y] : waters) {
            for (auto [dx, dy] : mv) {
                int nx = x+dx, ny = y+dy;
                if (in(nx, 0, R) && in(ny, 0, C) && W[nx][ny] != -1) {
                    merge(W[x][y], W[nx][ny]);
                }
            }
        }

        if (find(swans[0]) == find(swans[1])) {
            cout << t << '\n';
            break;
        }

        for (int i = waters.size(); i; i--) {
            auto [x, y] = waters.front(); waters.pop_front();
            for (auto [dx, dy] : mv) {
                int nx = x+dx, ny = y+dy;
                if (in(nx, 0, R) && in(ny, 0, C) && W[nx][ny] == -1) {
                    W[nx][ny] = W[x][y];
                    waters.emplace_back(nx, ny);
                }
            }
        }
    }

    return 0;
}

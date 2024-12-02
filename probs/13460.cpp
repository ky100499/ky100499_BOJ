#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 10;

char B[MAX][MAX];
int mv[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    pi red, blue;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> B[i][j];
            if (B[i][j] == 'R') red = {i, j};
            else if (B[i][j] == 'B') blue = {i, j};
        }
    }

    deque<tuple<int, pi, pi>> q; q.emplace_back(1, red, blue);
    while (!q.empty()) {
        auto [c, r, b] = q.front(); q.pop_front();

        if (c > 10) break;

        for (auto [dx, dy] : mv) {
            auto [rx, ry] = r; auto [bx, by] = b;
            bool r_out = 0, b_out = 0;
            while (!r_out || !b_out) {
                if (!r_out && B[rx+dx][ry+dy] != '#' && (rx+dx != bx || ry+dy != by)) {
                    rx += dx; ry += dy;
                }
                else if (!b_out && B[bx+dx][by+dy] != '#' && (bx+dx != rx || by+dy != ry)) {
                    bx += dx; by += dy;
                }
                else break;

                if (B[rx][ry] == 'O') {
                    r_out = 1;
                    rx = -1;
                }
                if (B[bx][by] == 'O') {
                    b_out = 1;
                    bx = -1;
                }
            }

            if (b_out) {
                continue;
            }
            else if (r_out) {
                cout << c << '\n';
                return 0;
            }
            else if (rx != r.first || ry != r.second || bx != b.first || by != b.second) {
                q.emplace_back(c+1, make_pair(rx, ry), make_pair(bx, by));
            }
        }
    }

    cout << -1 << '\n';

    return 0;
}

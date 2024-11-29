#include <bits/stdc++.h>

#define in(x, a, b) a <= x && x < b

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 100;

char B[MAX+2][MAX+2];
int V[MAX+2][MAX+2],
    mv[4][2] = {{0,-1}, {-1,0}, {0,1}, {1,0}};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        int H, W; cin >> H >> W;

        for (int i = 0; i < H+2; i++)
            for (int j = 0; j < W+2; j++)
                B[i][j] = '.';

        for (int i = 1; i <= H; i++)
            for (int j = 1; j <= W; j++)
                cin >> B[i][j];

        int key = 0;
        string ipt; cin >> ipt;
        if (ipt != "0")
            for (char c : ipt)
                key |= 1 << (c - 'a');

        int old_key = -1, ans = 0;
        while (key != old_key) {
            old_key = key;

            deque<pi> q({{0, 0}});
            memset(V, 0, sizeof V); V[0][0] = 1;
            while (!q.empty()) {
                auto [x, y] = q.front(); q.pop_front();

                for (auto [dx, dy] : mv) {
                    int nx = x+dx, ny = y+dy;
                    if (in(nx, 0, H+2) && in(ny, 0, W+2) && !V[nx][ny]) {
                        V[nx][ny] = 1;
                        if (B[nx][ny] == '.') q.emplace_back(nx, ny);
                        else if (B[nx][ny] == '$') {
                            B[nx][ny] = '.';
                            ans++;
                            q.emplace_back(nx, ny);
                        }
                        else if (in(B[nx][ny], 'A', 'Z'+1) && key & (1<<(B[nx][ny]-'A'))) {
                            B[nx][ny] = '.';
                            q.emplace_back(nx, ny);
                        }
                        else if (in(B[nx][ny], 'a', 'z'+1)) {
                            key |= 1 << (B[nx][ny] - 'a');
                            B[nx][ny] = '.';
                            q.emplace_back(nx, ny);
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}

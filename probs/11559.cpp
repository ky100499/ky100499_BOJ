#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;
using pi = pair<int, int>;

const int H = 12, W = 6;

char A[H][W];
int V1[H][W], V2[H][W],
    mv[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> A[i][j];

    int ans = 0;
    while (1) {
        int exp = 0;
        memset(V1, 0, sizeof V1);
        for (int i = H-1; i >= 0; i--) {
            for (int j = 0; j < W; j++) {
                if (V1[i][j] || A[i][j] == '.') continue;

                int cnt = 0;
                memset(V2, 0, sizeof V2);
                queue<pi> q; q.emplace(i, j);
                while (!q.empty()) {
                    auto [h, w] = q.front(); q.pop();

                    if (V2[h][w]) continue;
                    V1[h][w] = V2[h][w] = 1;
                    cnt++;

                    for (auto [dh, dw] : mv) {
                        int nh = h+dh, nw = w+dw;
                        if (in(nh, 0, H) && in(nw, 0, W) && A[h][w] == A[nh][nw] && !V2[nh][nw]) {
                            q.emplace(nh, nw);
                        }
                    }
                }

                if (cnt >= 4) {
                    exp = 1;
                    for (int h = 0; h < H; h++)
                        for (int w = 0; w < W; w++)
                            if (V2[h][w]) A[h][w] = '.';
                }
            }
        }
        if (!exp) break;
        ans++;

        for (int w = 0; w < W; w++) {
            int h1 = H-1, h2 = H-1;
            while (h2 >= 0) {
                if (A[h2][w] != '.') {
                    char c = A[h2][w];
                    A[h2][w] = '.';
                    A[h1--][w] = c;
                }
                h2--;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}

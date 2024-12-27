#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

char B[20][20];
int dist[11][11];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    while (1) {
        int W, H; cin >> W >> H;
        if (W == 0) break;

        vector<pi> dusts;
        pi s;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> B[i][j];
                if (B[i][j] == '*') dusts.emplace_back(i, j);
                else if (B[i][j] == 'o') dusts.
            }
        }
    }

    return 0;
}

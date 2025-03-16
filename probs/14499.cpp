#include <bits/stdc++.h>

#define in(x, a, b) (a <= x && x < b)

using namespace std;

int A[20][20],
    dice[6] = {},
    mv[4][2] = { {0,1}, {0,-1}, {-1,0}, {1,0} };

function<void(void)> roll[] = {
    // dice: top, up, right, down, left, bottom
    []() {
        swap(dice[0], dice[4]);
        swap(dice[4], dice[5]);
        swap(dice[5], dice[2]);
    },
    []() {
        swap(dice[0], dice[2]);
        swap(dice[2], dice[5]);
        swap(dice[5], dice[4]);
    },
    []() {
        swap(dice[0], dice[3]);
        swap(dice[3], dice[5]);
        swap(dice[5], dice[1]);
    },
    []() {
        swap(dice[0], dice[1]);
        swap(dice[1], dice[5]);
        swap(dice[5], dice[3]);
    },
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, x, y, K; cin >> N >> M >> x >> y >> K;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    while (K--) {
        int d; cin >> d; d--;

        int nx = x+mv[d][0], ny = y+mv[d][1];
        if (in(nx, 0, N) && in(ny, 0, M)) {
            x = nx; y = ny;

            roll[d]();
            if (A[x][y]) {
                dice[5] = A[x][y];
                A[x][y] = 0;
            }
            else A[x][y] = dice[5];

            cout << dice[0] << '\n';
        }
    }

    return 0;
}

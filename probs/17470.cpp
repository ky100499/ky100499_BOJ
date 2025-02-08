#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;

// 0 1 2 3 rotate(0~3) Hflip(0/1)
int state[] = { 0, 1, 2, 3, 0, 0 },
    A[4][MAX][MAX];

function<void(void)> op[] = {
    []() {
        swap(state[0], state[2]);
        swap(state[1], state[3]);
        if (state[4]%2 == 0) state[4] = (state[4]+2) % 4;
        state[5] ^= 1;
    },
    []() {
        swap(state[0], state[1]);
        swap(state[2], state[3]);
        if (state[4]%2) state[4] = (state[4]+2) % 4;
        state[5] ^= 1;
    },
    []() {
        swap(state[0], state[2]);
        swap(state[2], state[3]);
        swap(state[3], state[1]);
        state[4] = ++state[4] % 4;
    },
    []() {
        swap(state[0], state[1]);
        swap(state[1], state[3]);
        swap(state[3], state[2]);
        state[4] = (state[4]+3) % 4;
    },
    []() {
        swap(state[0], state[2]);
        swap(state[2], state[3]);
        swap(state[3], state[1]);
    },
    []() {
        swap(state[0], state[1]);
        swap(state[1], state[3]);
        swap(state[3], state[2]);
    },
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M, R; cin >> N >> M >> R;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[2*(2*i/N)+2*j/M][i%(N/2)][j%(M/2)];

    while (R--) {
        int o; cin >> o;
        op[o-1]();
    }

    if (state[5])
        for (int i = 0; i < N/2; i++)
            for (int j = 0; j < M/4; j++)
                for (int k = 0; k < 4; k++)
                    swap(A[k][i][j], A[k][i][M/2-j-1]);

    int row = (state[4]%2 ? M : N) / 2,
        col = (state[4]%2 ? N : M) / 2;
    for (int s = 0; s < 4; s += 2) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col*2; j++) {
                if (state[4] == 0) cout << A[state[s+j/col]][i][j%col];
                if (state[4] == 1) cout << A[state[s+j/col]][N/2-1-j%col][i];
                if (state[4] == 2) cout << A[state[s+j/col]][N/2-1-i][M/2-1-j%col];
                if (state[4] == 3) cout << A[state[s+j/col]][j%col][M/2-1-i];
                cout << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}

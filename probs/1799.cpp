#include <bits/stdc++.h>

using namespace std;

const int MAX = 10;

int B[MAX][MAX], N, ans[2] = {};

// d1 : 우하향 대각선 -> 좌표 차 일정
// d2 : 우상향 대각선 -> 좌표 합 일정
map<int, int> d1, d2;

void bt(int x, int y, int b, int n)
{
    if (y >= N) {
        x += 1;
        y = x%2 == b;
    }

    if (x == N) {
        ans[b] = max(ans[b], n);
        return;
    }

    if (B[x][y] && !d1[x-y] && !d2[x+y]) {
        d1[x-y] = d2[x+y] = 1;
        bt(x, y+2, b, n+1);
        d1[x-y] = d2[x+y] = 0;
    }
    bt(x, y+2, b, n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> B[i][j];

    bt(-1, N, 0, 0);
    bt(-1, N, 1, 0);
    cout << ans[0]+ans[1] << '\n';

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

typedef tuple<int, int, int> ti;

int mv[][2] = { {0,-1}, {-1,0}, {0,1}, {1,0} };

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M)), V(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[i][j];

    priority_queue<ti> pq;
    for (int i = 0; i < N; i++) {
        pq.push({A[i][0], i, 0});
        if (M > 1) pq.push({A[i][M-1], i, M-1});
        V[i][0] = V[i][M-1] = 1;
    }
    for (int j = 1; j < M-1; j++) {
        pq.push({A[0][j], 0, j});
        if (N > 1) pq.push({A[N-1][j], N-1, j});
        V[0][j] = V[N-1][j] = 1;
    }

    int K; cin >> K;
    while (K--) {
        auto [v, x, y] = pq.top(); pq.pop();
        cout << x+1 << ' ' << y+1 << '\n';

        for (auto m : mv) {
            int nx = x+m[0], ny = y+m[1];
            if (0 <= nx && nx < N && 0 <= ny && ny < M && !V[nx][ny]) {
                pq.push({A[nx][ny], nx, ny});
                V[nx][ny] = 1;
            }
        }
    }

    return 0;
}

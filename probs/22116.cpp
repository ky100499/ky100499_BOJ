#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <tuple>

#define INF 2e9

using namespace std;

typedef tuple<int, int, int> ti;

int mv[][2] = {{-1,0}, {0,-1}, {1,0}, {0,1}};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> A[i][j];

    priority_queue<ti, vector<ti>, greater<ti>> pq; pq.push({0, 0, 0});
    vector<vector<int>> dist(N, vector<int>(N, INF)); dist[0][0] = 0;
    while (!pq.empty()) {
        auto [d, x, y] = pq.top(); pq.pop();

        if (x == N-1 && y == N-1) {
            cout << d << '\n';
            break;
        }

        if (dist[x][y] < d) continue;

        for (auto m : mv) {
            int nx = x+m[0], ny = y+m[1];
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                int slope = max(dist[x][y], abs(A[x][y] - A[nx][ny]));
                if (slope < dist[nx][ny]) {
                    dist[nx][ny] = slope;
                    pq.push({slope, nx, ny});
                }
            }
        }
    }

    return 0;
}

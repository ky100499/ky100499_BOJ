#include <iostream>
#include <map>
#include <queue>
#include <algorithm>

#define MAX 40000
#define MAXD 17

using namespace std;

int depth[MAX+1] = { 0, }, parent[MAX+1][MAXD][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N; cin >> N;

    map<int, int> G[MAX+1];
    int a, b, d;
    for (int i = 1; i < N; i++) {
        cin >> a >> b >> d;
        G[a][b] = G[b][a] = d;
    }

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < MAXD; j++)
            for (int k = 0; k < 2; k++)
                parent[i][j][k] = 0;

    queue<int> q({1});
    int visited[MAX+1] = { 0, };
    depth[0] = -1;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (visited[node]) continue;
        visited[node] = 1;

        for (auto next : G[node]) {
            if (visited[next.first]) continue;

            depth[next.first] = depth[node]+1;

            parent[next.first][0][0] = node;
            parent[next.first][0][1] = next.second;
            for (int i = 1; i < MAXD; i++) {
                parent[next.first][i][0] = parent[parent[next.first][i-1][0]][i-1][0];
                parent[next.first][i][1] = parent[next.first][i-1][1] + parent[parent[next.first][i-1][0]][i-1][1];
            }

            q.push(next.first);
        }
    }

    int M; cin >> M;
    while (M--) {
        cin >> a >> b;
        int ans = 0, diff = depth[b] - depth[a];
        if (diff < 0) {
            swap(a, b);
            diff *= -1;
        }
        for (int i = MAXD-1; i >= 0; i--) {
            if (depth[parent[b][i][0]] >= depth[a]) {
                ans += parent[b][i][1];
                b = parent[b][i][0];
            }
        }

        if (a != b) {
            for (int i = MAXD-1; i >= 0; i--) {
                if (parent[a][i][0] != parent[b][i][0]) {
                    ans += parent[a][i][1] + parent[b][i][1];
                    a = parent[a][i][0];
                    b = parent[b][i][0];
                }
            }
            ans += parent[a][0][1] + parent[b][0][1];
        }

        cout << ans << '\n';
    }

    return 0;
}

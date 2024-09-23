#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> G;
vector<int> visited;

bool dfs(int node, int depth)
{
    if (depth == 5) return 1;
    else {
        visited[node] = 1;
        for (int g : G[node])
            if (!visited[g])
                if (dfs(g, depth+1)) return 1;
        visited[node] = 0;
        return 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M; G.resize(N); visited.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    bool ans = false;
    for (int i = 0; i < N; i++)
        ans = ans || dfs(i, 1);
    cout << ans << '\n';

    return 0;
}

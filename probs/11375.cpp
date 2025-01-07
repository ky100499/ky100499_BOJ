#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;
using ti = tuple<int, int, int>;

const int MAX = 1000,
          INF = 1e9;

vector<int> G[MAX+1];
int mat[MAX+1] = {}, V[MAX+1];

bool match(int a)
{
    for (int b : G[a]) {
        if (V[b]) continue;
        V[b] = 1;

        if (mat[b] == 0 || match(mat[b])) {
            mat[b] = a;
            return 1;
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        int c; cin >> c;
        G[i].reserve(c);
        while (c--) {
            int ipt; cin >> ipt;
            G[i].push_back(ipt);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        memset(V, 0, sizeof V);
        if (match(i)) ans++;
    }
    cout << ans << '\n';

    return 0;
}

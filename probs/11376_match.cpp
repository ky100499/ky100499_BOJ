#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000;

vector<int> P[2*MAX];
int W[MAX+1], V[MAX+1];

bool match(int p)
{
    for (int w : P[p]) {
        if (V[w]) continue;
        V[w] = 1;

        if (W[w] == -1 || match(W[w])) {
            W[w] = p;
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
    for (int i = 0; i < N; i++) {
        int c; cin >> c;
        P[i].reserve(c);
        P[i+N].reserve(c);
        while (c--) {
            int w; cin >> w;
            P[i].push_back(w);
            P[i+N].push_back(w);
        }
    }

    memset(W, -1, sizeof W);
    int ans = 0;
    for (int i = 0; i < 2*N; i++) {
        memset(V, 0, sizeof V);
        if (match(i)) ans++;
    }
    cout << ans << '\n';

    return 0;
}

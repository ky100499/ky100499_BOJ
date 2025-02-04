#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;

vector<int> A[MAX+1];
int B[MAX+1], V[MAX+1];

bool match(int a)
{
    for (int b : A[a]) {
        if (V[b]) continue;
        V[b] = 1;

        if (!B[b] || match(B[b])) {
            B[b] = a;
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
    while (M--) {
        int a, b; cin >> a >> b;
        A[a].push_back(b);
    }

    memset(B, 0, sizeof B);
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        memset(V, 0, sizeof V);
        if (match(i)) ans++;
    }

    cout << ans << '\n';

    return 0;
}

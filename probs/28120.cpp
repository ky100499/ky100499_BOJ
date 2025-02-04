#include <bits/stdc++.h>

using namespace std;
using pi = pair<int, int>;

const int MAX = 15;

vector<int> A[MAX+1], B[MAX+1];
int V[MAX+1], N, K, X;
pi R[MAX+1];

bool match(int a)
{
    for (int b : A[a]) {
        if (V[b]) continue;
        V[b] = 1;

        int mat = 0;
        if (B[b].size() < X) {
            B[b].push_back(a);
            return 1;
        }
        for (int i = 0; i < X; i++) {
            if (match(B[b][i])) {
                B[b][i] = a;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    cin >> N >> K >> X;
    for (int i = 1; i <= N; i++) {
        int C; cin >> C;
        A[i].reserve(C);
        while (C--) {
            int a; cin >> a;
            A[i].push_back(a);
        }
    }
    for (int i = 0; i < N; i++) {
        cin >> R[i].first;
        R[i].second = i+1;
    }
    sort(R, R+N, greater<pi>());

    for (int i = 0; i < N; i++) {
        memset(V, 0, sizeof V);
        match(R[i].second);
    }

    for (int i = 1; i <= K; i++) {
        cout << B[i].size();
        for (int b : B[i]) cout << ' ' << b;
        cout << '\n';
    }

    return 0;
}

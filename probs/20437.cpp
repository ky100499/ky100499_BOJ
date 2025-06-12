#include <bits/stdc++.h>

using namespace std;

vector<int> A[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int T; cin >> T;
    while (T--) {
        string W; int K; cin >> W >> K;
        for (int i = 0; i < 26; i++) A[i].clear();

        int m = 1e9, M = -1;
        for (int i = 0; i < W.size(); i++) {
            int x = W[i]-'a';
            A[x].push_back(i);

            int s = A[x].size();
            if (s >= K) {
                m = min(m, A[x][s-1] - A[x][s-K] + 1);
                M = max(M, A[x][s-1] - A[x][s-K] + 1);
            }
        }

        if (M == -1) cout << "-1\n";
        else cout << m << ' ' << M << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

set<int> S;
map<int, vector<int>> M;
int A[100];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("input.txt", "r", stdin);

    int N, K; cin >> N >> K;
    for (int i = 0; i < K; i++) {
        cin >> A[i];
        M[A[i]].push_back(i);
    }
    for (auto [k, v] : M) M[k].push_back(INF);

    int ans = 0;
    for (int i = 0; i < K; i++) {
        int a = A[i];

        if (S.size() < N) S.insert(a);
        else if (S.find(a) == S.end()) {
            int k = 0, v;
            for (int s : S) {
                int x = *lower_bound(M[s].begin(), M[s].end(), i);
                if (k < x) k = x, v = s;
            }
            S.erase(v); S.insert(a);
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
